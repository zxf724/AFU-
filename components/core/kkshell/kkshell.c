/*
 * This file is a part of AFUIOT, Which is a free software project, Developed by
 * ShenZhen AFU Smart Internet Technology Co.,Ltd(AFU company).
 * AFUIOT, The new start of IoT, get news on www.afuiot.com.
 *
 * Copyright © 2019 [copyright AFU company].
 * @license (MIT license)
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:The above copyright
 * notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Version Logs:
 * Date         Author          Notes
 * 2019.2.8     Yang Song       first version.
 */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "kkshell.h"
#include "kkring.h"

/* Private typedef -----------------------------------------------------------*/
/**
 * shell client handle types
 */
typedef struct {
  uint8_t   echo_enable;
  uint32_t  pos_last;
  KKRingDef ring;
} ShellClientHandleDef;

/* Private define ------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static ShellCommandRegistryDef* command_entrance = NULL;
static ShellClientHandleDef shell_clients[SHELL_CLIENT_MAX];

/* External variables --------------------------------------------------------*/
ShellPrintfFun g_my_shell_printf;

/* Private function prototypes -----------------------------------------------*/
/* External functions --------------------------------------------------------*/

/**
 * KK shell set printf function pointer
 *
 * @param fun    printf function
 */
void KKShellSetPrintfFun(ShellPrintfFun fun) {
  g_my_shell_printf = fun;
}

/**
 * KK shell  client init
 * if buffer NULL or buffer size fault
 *
 * @param shell_id shell client id
 * @param fifo_buffer
 *                 shell history and get data ring buffer size
 * @param buf_size ring buffer size
 *
 * @return 1: Init OK
 *         0: Init Fail
 */
int KKShellClientInit(uint8_t shell_id, uint8_t* fifo_buffer,
                      uint16_t buf_size) {
  int ret = 0;

  if (shell_id < SHELL_CLIENT_MAX) {
    shell_clients[shell_id].echo_enable = CMD_ECHO_ENABLE_DEFAULT;
    ret = 1;

    if (NULL != fifo_buffer && buf_size > 0) {
      KKRingInit(&(shell_clients[shell_id].ring), fifo_buffer, buf_size);
    }
  }
  return ret;
}

/**
 * KK shell register new command
 *
 * @param cmdblock command registry block
 */
void KKShellCommandRegister(ShellCommandRegistryDef* cmdblock) {
  ShellCommandRegistryDef* pcmd;

  if (NULL != cmdblock) {
    if (NULL == command_entrance) {
      command_entrance = cmdblock;
    } else {
      pcmd = command_entrance;

      while (pcmd->next != NULL) {
        if (0 == strcmp(pcmd->next->command, cmdblock->command)) {
          break;
        }
        pcmd = pcmd->next;
      }
      pcmd->next = cmdblock;
    }
  }
}

int KKShellCommandProcess(ShellClientHandleDef* handle, char* rec_str,
                          int rec_len) {

}

int KKshelGetString(char* getbuf, uint16_t buflen);
int KKShellGetData(char* getbuf, uint16_t buflen);
int KKShellGetByte(char* cbyte);

/**
 * find option from argument vector
 *
 * @param argc   argument count
 * @param argv   argument vector
 * @param opt    option character
 * @param argret return option argument and argument vector
 *
 * @return return index of first non-option in argument vector
 */
int KKFindOpt(int argc, char* argv[], char opt, char** optarg, char** argvret) {
  int argind = -1, i;

  if (optarg != NULL) {
    *optarg = NULL;
  }
  if (argvret != NULL) {
    *argvret = NULL;
  }
  for (i = 0; i < argc; i++) {
    if ('-' == argv[i][0] && opt == argv[i][1]) {
      argind = i;
      if (argvret != NULL) {
        *argvret = argv[i + 1];
      }

      if (isgraph(argv[i][2])) {
        if (optarg != NULL) {
          *optarg = &argv[i][2];
        }
      }
      break;
    }
  }
  return argind;
}

/**
 * find long option from argument vector
 *
 * @param argc   argument count
 * @param argv   argument vector
 * @param opt    long option string
 * @param argret return option argument and argument vector
 *
 * @return return index of first non-option in argument vector
 */
int KKFindOptLong(int argc, char* argv[], char* opt, char** optarg,
                  char** argvret) {
  char* p;
  int argind = -1, i;

  if (optarg != NULL) {
    *optarg = NULL;
  }
  if (argvret != NULL) {
    *argvret = NULL;
  }
  for (i = 0; i < argc; i++) {
    if ('-' == argv[i][0] && '-' == argv[i][1]
        && 0 == strcmp(&argv[i][2], opt)) {
      argind = i;
      if (argvret != NULL) {
        *argvret = argv[i + 1];
      }

      p = &argv[i][2];
      while (*p && *p++ != '=');
      if (optarg != NULL) {
        *optarg = p;
      }
      break;
    }
  }
  return argind;
}

/**
 * find a signal argument from argument vector
 *
 * @param argc    argument count
 * @param argv    argument vector
 * @param argstr  argument string to find
 * @param argvret return argument vector
 *
 * @return return index of first non-option in argument vector
 */
int KKFindArgument(int argc, char* argv[], char* argstr, char** argvret) {
  int argind = -1, i;

  if (NULL != argvret) {
    *argvret = NULL;
  }

  for (i = 0; i < argc; i++) {
    if (0 == strcmp(argstr, argv[i])) {
      argind = i;
      if (NULL != argvret && argv[i + 1]) {
        *argvret = argv[i + 1];
      }
      break;
    }
  }
  return argind;
}


/* Private functions ---------------------------------------------------------*/


