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
 * 2019.2.18     Yang Song       first version.
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>        /* C标准库文件,系统头文件使用<>可提高编译速度*/
#include "kkshell.h"      /* 其他库文件*/
#include "coding_syle.h"  /* 项目头文件*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/**
 * 局部函数实例
 */
static int gs_variab;
/* Exported constants --------------------------------------------------------*/
/**
 * 常量用大小写混合，以小写k开头
 */
const int kMyConstan = 100;
/* External variables --------------------------------------------------------*/
/**
 * 全部变量全部小写
 */
int g_my_variable;
/* Private function prototypes -----------------------------------------------*/
/**
 * 局部函数申明
 */
static int MyPrivateFunction(void);
/* External functions --------------------------------------------------------*/

/**
 * 演示代码风格与缩进的函数，注意JAVADOC注释的格式
 *
 * @param fun      函数指针
 * @param argument 小写的参数
 */
void MyTestFunction(MyFunctioPointerFun fun, int argument) { // 大括号左边位于行尾
  int volatile delay = 0;
  static int gs_store = 0;

  while (delay++ < argument)
    continue;     // 不能直接使用;作循环语句的结尾

  /* 这是一个用来演示编码风格的语句*/
  switch (gs_variab) {
    case 100:
      gs_variab = 2;
      break;
    case 2:
      gs_variab = fun() + gs_store;
      break;
    default:
      gs_variab = MyPrivateFunction();
      break;
  }
  gs_store = gs_variab;
  g_my_variable = gs_variab;
}

/* Private functions ---------------------------------------------------------*/
/**
 * 局部函数实例
 *
 * @return 返回一个数
 */
static int MyPrivateFunction(void) {
  // TODO(song) 后续添加
  return 100;
}

