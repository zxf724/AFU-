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
#ifndef __AFUDEF_H
#define __AFUDEF_H

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported typedef ----------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
#undef NULL
#define NULL 0u

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define IS_POWER_OF_TWO(A) (((A) != 0) && ((((A) - 1) & (A)) == 0))
#define IS_WORD(A)         (A % 4 == 0)

#define STR_EQUAL(des, token)   (strcmp((char*)des, (char*)token) == 0)
#define STR_NEQUAL(des, token)  (strncmp((char*)des, (char*)token, \
                                  strlen((char*)token)) == 0)
#undef MIN
#define MIN(x,y)  ((x) < (y) ? (x) : (y))

#undef MAX
#define MAX(x,y)  ((x) > (y) ? (x) : (y))

/* External variables --------------------------------------------------------*/
/* External functions --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif
