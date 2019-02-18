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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AFUIOT_KKSHELL_H_
#define AFUIOT_KKSHELL_H_

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "kkring.h"

/* Exported typedef ----------------------------------------------------------*/
/**
 * shell print fromatted funtion types
 */
typedef int (* ShellPrintfFun)(uint8_t shell_id, const char* format, ...);

/**
 * shell command callback funtion types
 */
typedef void (* ShellCallbackFun)(uint8_t shell_id, int argc, char* argv[]);

// /**
//  * command argument list types
//  */
// typedef struct ArgDesc {
//   char const* arg;
//   char const* arg_desc;
//   struct Argument* next;
// } CommandArgumentList;

/**
 * shell command registry block types
 */
typedef struct CommandRegistry {
  char const* command;
  char const* help_info;
  ShellCallbackFun cb;
  struct CommandRegistry* next;
} ShellCommandRegistryDef;

/* Exported define -----------------------------------------------------------*/

/**
 * define signal command-line argument count max
 */
#define CMD_LINE_ARGC_MAX         8

/**
 * define characters numbers of signal command line maximum
 */
#define CMD_LINE_CHARS_MAX        100

/**
 * define shell echo ebable default set
 */
#define CMD_ECHO_ENABLE_DEFAULT   1

/**
 * define numbers of shlle client maximum
 */
#define SHELL_CLIENT_MAX          4

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/**
 * define a shell command register variable
 */
#define CMD_REGISTR_VAR(cmd)          (my_reg_block_##cmd)
/**
 * shell register a new command macro
 */
#define KK_CMD_REGISTER(cmd, desc, callback)\
    static CliCommandRegistryDef CMD_REGISTR_VAR(cmd)=\
        {#cmd, desc, callback, NULL};\
    KKShellCommandRegister(&CMD_REGISTR_VAR(cmd));

/**
 * shell print formatted string
 */
#define KK_PRINTF(format, ...)\
    MyShellPrintfFun(shell_id, format, ##__VA_ARGS__)

/**
 * shell print log(string with client head and CRLF)
 */
#define KK_LOG(format, ...)\
    KK_PRINTF("client-%d>"format"\r\n", shell_id, ##__VA_ARGS__)

/**
 * shell print client head
 */
#define KK_RSP()  KK_PRINTF("client-%d >", shell_id)

/* External variables --------------------------------------------------------*/
extern ShellPrintfFun g_my_shell_printf;

/* External functions --------------------------------------------------------*/
void KKShellSetPrintfFun(ShellPrintfFun fun);
int KKShellClientInit(uint8_t shell_id, uint8_t* fifo_buffer,
                      uint16_t buf_size);

void KKShellCommandRegister(ShellCommandRegistryDef* cmdblock);
int KKShellCommandProcess(uint8_t shell_id, char* rec_str, uint16_t rec_len);

int KKshelGetString(char* getbuf, uint16_t buflen);
int KKShellGetData(char* getbuf, uint16_t buflen);
int KKShellGetByte(char* cbyte);

int KKFindOpt(int argc, char* argv[], char opt, char** optarg, char** argvret);
int KKFindOptLong(int argc, char* argv[], char* opt, char** optarg,
                  char** argvret);
int KKFindArgument(int argc, char* argv[], char* argstr, char** argvret);

#ifdef __cplusplus
}
#endif

#endif
