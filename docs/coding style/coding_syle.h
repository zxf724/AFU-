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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AFUIOT_CODE_STYLE_H_
#define AFUIOT_CODE_STYLE_H_

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
/* Exported typedef ----------------------------------------------------------*/
/**
 * 定义函数指针类型
 */
typedef int (* MyFunctioPointerFun)(void);

/**
 * 定义结构体变量类型
 */
typedef struct MyStruct {
  int my_struct_member; // 结构体成员全部小写
} MystructDef;

/**
 * 定义结构体类型
 */
typedef enum {
  kMyenum0,   // 枚举成员等同于常量
  kMyenum1
} MyEnum;

/* Exported define -----------------------------------------------------------*/
/**
 * 无参数宏全部大写
 */
#define MY_DEFINE     1
/* Exported constants --------------------------------------------------------*/
/**
 * 常量用大小写混合，以小写k开头
 */
extern const int kMyConstan;
/* Exported macro ------------------------------------------------------------*/
/**
 * 带参数宏全部大写
 */
#define MY_ADDITION(x, y)   (x + y)
/* External variables --------------------------------------------------------*/
/**
 * 全部变量全部小写
 */
extern int g_my_variable;
/* External functions --------------------------------------------------------*/
void MyTestFunction(MyFunctioPointerFun fun, int argument);

#ifdef __cplusplus
}
#endif

#endif

