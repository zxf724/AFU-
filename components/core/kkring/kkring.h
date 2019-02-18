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
#ifndef AFUIOT_KKRING_H_
#define AFUIOT_KKRING_H_

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported typedef ----------------------------------------------------------*/
/**
 * ring buffer types
 */
typedef struct {
  uint8_t* buffer;
  uint32_t size_mask;
  uint32_t wpos;
  uint32_t rpos;
} KKRingDef;

/**
 * pointer ring buffer types
 */
typedef struct {
  void** pointers;
  uint32_t size_mask;
  uint32_t wpos;
  uint32_t rpos;
} KKPointRingDef;

/* Exported define -----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/**
 * get ring buffer length
 */
#define KKRING_LENGTH(x)  (x->wpos - x->rpos)

/**
 * get ring buffer free length macro
 */
#define KKRING_FREE_LENGTH(x) (x->size_mask - KKRING_LENGTH(x) + 1)

/* External variables --------------------------------------------------------*/
/* External functions --------------------------------------------------------*/
int KKRingInit(KKRingDef* ring, uint8_t* buffer, uint32_t size);
void KKRingReset(KKRingDef* ring);

int KKRingPutByteHead(KKRingDef* ring, uint8_t byte);
int KKRingPutByteTail(KKRingDef* ring, uint8_t byte);
int KKRingGetByteHead(KKRingDef* ring, uint8_t* pbyte);
int KKRingGetByteTail(KKRingDef* ring, uint8_t* pbyte);

int KKRingPeekByte(KKRingDef* ring, uint32_t index, uint8_t* pbyte);
int KKRingTailBack(KKRingDef* ring, uint32_t n);
int KKRingHeapSkip(KKRingDef* ring, uint32_t n);

int KKRingDelete(KKRingDef* ring, uint32_t pos, uint32_t n);
int KKRingInsert(KKRingDef* ring, uint32_t pos, uint8_t* data, uint32_t len);

int KKRingPutHead(KKRingDef* ring, uint8_t* data, uint32_t data_len);
int KKRingPutTail(KKRingDef* ring, uint8_t* data, uint32_t data_len);
int KKRingGetHead(KKRingDef* ring, uint8_t* data, uint32_t data_len);
int KKRingGetTail(KKRingDef* ring, uint8_t* data, uint32_t data_len);

int KKPointerRingInit(KKPointRingDef* ring, void** pointers, uint32_t size);
int KKPointerRingReset(KKPointRingDef* ring);

int KKPointerRingPutHead(KKPointRingDef* ring, void* p);
int KKPointerRingPutTail(KKPointRingDef* ring, void* p);
int KKPointerRingGetHead(KKPointRingDef* ring, void** pp);
int KKPointerRingGetTail(KKPointRingDef* ring, void** pp);

#ifdef __cplusplus
}
#endif

#endif
