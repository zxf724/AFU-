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
#include "string.h"
#include "kkring.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* External functions --------------------------------------------------------*/

/**
 * ring buffer init
 *
 * @param ring   a ring buffer handle
 * @param buffer buffer point
 * @param size   buffer size, must be Power of 2
 *
 * @return 1：Init OK
 *         0: Init fail
 */
int KKRingInit(KKRingDef* ring, uint8_t* buffer, uint32_t size) {
  if (NULL != ring && NULL != buffer && IS_POWER_OF_TWO(size)) {
    ring->buffer = buffer;
    ring->size_mask = size - 1;
    ring->wpos = ring->rpos = 0;
    return 1;
  }
  return 0;
}

/**
 * ring buffer reset
 *
 * @param ring   a ring buffer handle
 */
void KKRingReset(KKRingDef* ring) {
  ring->wpos = ring->rpos = 0;
}

/**
 * ring buffer put a byte into head
 *
 * @param ring   a ring buffer handle
 * @param byte   byte to be put
 *
 * @return 1: put ok
 *         0: no memory
 */
int KKRingPutByteHead(KKRingDef* ring, uint8_t byte) {
  if (KKRING_FREE_LENGTH(ring)) {
    ring->buffer[(ring->rpos - 1) & ring->size_mask] = byte;
    ring->rpos--;
    return 1;
  }
  return 0;
}

/**
 * ring buffer put a byte into tail
 *
 * @param ring   a ring buffer handle
 * @param byte   byte to be put
 *
 * @return 1: put ok
 *         0: no memory
 */
int KKRingPutByteTail(KKRingDef* ring, uint8_t byte) {
  if (KKRING_FREE_LENGTH(ring)) {
    ring->buffer[ring->wpos & ring->size_mask] = byte;
    ring->wpos++;
    return 1;
  }
  return 0;
}

/**
 * ring buffer get a byte from head
 *
 * @param ring   a ring buffer handle
 * @param pbyte  byte read pointer
 *
 * @return 1: get ok
 *         0: no data
 */
int KKRingGetByteHead(KKRingDef* ring, uint8_t* pbyte) {
  if (KKRING_LENGTH(ring)) {
    *pbyte = ring->buffer[ring->rpos & ring->size_mask];
    ring->rpos++;
    return 1;
  }
  return 0;
}
/**
 * ring buffer get a byte from tail
 *
 * @param ring   a ring buffer handle
 * @param pbyte byte read pointer
 *
 * @return 1: get ok
 *         0: no data
 */
int KKRingGetByteTail(KKRingDef* ring, uint8_t* pbyte) {
  if (KKRING_LENGTH(ring)) {
    *pbyte = ring->buffer[(ring->wpos - 1) & ring->size_mask];
    ring->wpos--;
    return 1;
  }
  return 0;
}

/**
 * look a byte in the ring buffer
 *
 * @param ring   a ring buffer handle
 * @param index  index of ring buffer
 * @param pbyte  byte look pointer
 *
 * @return 1: peek ok
 *         0: no data
 */
int KKRingPeekByte(KKRingDef* ring, uint32_t index, uint8_t* pbyte) {
  if (KKRING_LENGTH(ring) > index) {
    *pbyte = ring->buffer[(ring->rpos + index) & ring->size_mask];
    return 1;
  }
  return 0;
}

/**
 * ring buffer discard data from tail
 *
 * @param ring   a ring buffer handle
 * @param n      number of discard
 *
 * @return return discard bytes number
 */
int KKRingTailBack(KKRingDef* ring, uint32_t n) {
  uint32_t i;

  n = MIN(n, KKRING_LENGTH(ring));
  for (i = 0; i < n; i++) {
    ring->wpos--;
  }
  return n;
}

/**
 * ring buffer discard data from head
 *
 * @param ring   a ring buffer handle
 * @param n      number of discard
 *
 * @return return discard bytes number
 */
int KKRingHeapSkip(KKRingDef* ring, uint32_t n) {
  uint32_t i;

  n = MIN(n, KKRING_LENGTH(ring));
  for (i = 0; i < n; i++) {
    ring->rpos++;
  }
  return n;
}

/**
 * ring buffer delete data
 *
 * @param ring   a ring buffer handle
 * @param pos    begin position for delete
 * @param n      number of delete
 *
 * @return return deleted bytes number
 */
int KKRingDelete(KKRingDef* ring, uint32_t pos, uint32_t n) {
  uint32_t len, wlen, h;

  len = MIN(n, KKRING_LENGTH(ring));


  if (pos > KKRING_LENGTH(ring) >> 2) {
    ring->buffer[]
  }

  return len;
}

/**
 * ring buffer insert data
 *
 * @param ring   a ring buffer handle
 * @param data   data buffer pointer
 * @param len    data buffer length
 *
 * @return return inserted bytes number
 */
int KKRingInsert(KKRingDef* ring, uint32_t pos uint8_t* data, uint32_t len) {



}

/**
 * put data to ring buffer head
 *
 * @param ring     a ring buffer handle
 * @param data     data buffer pointer
 * @param data_len data buffer length
 *
 * @return return put length
 */
int KKRingPutHead(KKRingDef* ring, uint8_t* data, uint32_t data_len) {
  uint32_t len, wlen, pos;

  len = MIN(data_len, KKRING_FREE_LENGTH(ring));

  pos = ring->rpos & ring->size_mask;
  wlen = MIN(len, pos);
  memcpy(ring->buffer + pos - wlen, data + len - wlen, wlen);

  memcpy(ring->buffer + (ring->size_mask + 1 - wlen), data, len - wlen);

  ring->rpos -= len;
  return len;
}

/**
 *  put data to ring buffer tail
 *
 * @param ring     a ring buffer handle
 * @param data     data buffer pointer
 * @param data_len data buffer length
 *
 * @return return put length
 */
int KKRingPutTail(KKRingDef* ring, uint8_t* data, uint32_t data_len) {
  uint32_t len, wlen, pos;

  len = MIN(data_len, KKRING_FREE_LENGTH(ring));

  pos = ring->wpos & ring->size_mask;
  wlen = MIN(len, ring->size_mask + 1 - pos);
  memcpy(ring->buffer + pos, data, wlen);

  memcpy(ring->buffer, data + wlen, len - wlen);

  ring->wpos += len;
  return len;
}

/**
 * get data from ring bufffer head
 *
 * @param ring     a ring buffer handle
 * @param data     data buffer pointer
 * @param data_len data buffer length
 *
 * @return retun get length
 */
int KKRingGetHead(KKRingDef* ring, uint8_t* data, uint32_t data_len) {
  uint32_t len, rlen, pos;

  len = MIN(data_len, KKRING_LENGTH(ring));

  pos = (ring->rpos & ring->size_mask);
  rlen = MIN(len, ring->size_mask + 1 - pos);
  memcpy(data, ring->buffer + pos, rlen);

  memcpy(data + rlen, ring->buffer, len - rlen);
  return len;
}

/**
 * get data from ring bufffer tail
 *
 * @param ring     a ring buffer handle
 * @param data     data buffer pointer
 * @param data_len data buffer length
 *
 * @return retun get length
 */
int KKRingGetTail(KKRingDef* ring, uint8_t* data, uint32_t data_len) {
  uint32_t len, rlen, pos;

  len = MIN(data_len, KKRING_LENGTH(ring));

  pos = (ring->wpos & ring->size_mask);
  rlen = MIN(len, pos);
  memcpy(data + len - rlen, ring->buffer + pos - rlen, rlen);

  memcpy(data, ring->buffer + (ring->size_mask + 1 - rlen), len - rlen);
  return len;
}

/**
 * pointer ring buffer init
 *
 * @param ring   a pointer ring buffer handle
 * @param pointers pointer bubbfer
 * @param size   pointer buffer size, must be Power of 2
 *
 * @return 1：Init OK
 *         0: Init fail
 */
int KKPointerRingInit(KKPointRingDef* ring, void** pointers, uint32_t size) {
  if (NULL != ring && NULL != pointers && IS_POWER_OF_TWO(size)) {
    ring->pointers = pointers;
    ring->size_mask = size - 1;
    ring->wpos = ring->rpos = 0;
    return 1;
  }
  return 0;
}

/**
 * pointer ring buffer reset
 *
 * @param ring   a pointer ring buffer handle
 */
void KKPointRingReset(KKPointRingDef* ring) {
  ring->wpos = ring->rpos = 0;
}

/**
 * pointeer ring buffer put a pointer into head
 *
 * @param ring   a ring buffer handle
 * @param p      pointer to be put
 *
 * @return 1: put ok
 *         0: no memory
 */
int KKPointerRingPutHead(KKPointRingDef* ring, void* p) {
  if (KKRING_FREE_LENGTH(ring)) {
    ring->pointers[(ring->rpos - 1) & ring->size_mask] = p;
    ring->rpos--;
    return 1;
  }
  return 0;
}

/**
 * pointer ring buffer put a pointer into tail
 *
 * @param ring   a ring buffer handle
 * @param p      pointer to be put
 *
 * @return 1: put ok
 *         0: no memory
 */
int KKPointerRingPutTail(KKPointRingDef* ring, void* p) {
  if (KKRING_FREE_LENGTH(ring)) {
    ring->pointers[ring->wpos & ring->size_mask] = p;
    ring->wpos++;
    return 1;
  }
  return 0;
}

/**
 * pointer ring buffer get a pointer from head
 *
 * @param ring   a ring buffer handle
 * @param pp     pointer read pointer
 *
 * @return 1: get ok
 *         0: no data
 */
int KKPointerRingGetHead(KKPointRingDef* ring, void** pp) {
  if (KKRING_LENGTH(ring)) {
    *pp = ring->pointers[ring->rpos & ring->size_mask];
    ring->rpos++;
    return 1;
  }
  return 0;
}


/**
 * pointer ring buffer get a pointer from tail
 *
 * @param ring   a ring buffer handle
 * @param pp     pointer read pointer
 *
 * @return 1: get ok
 *         0: no data
 */
int KKPointerRingGetTail(KKPointRingDef* ring, void** pp) {
  if (KKRING_LENGTH(ring)) {
    *pp = ring->pointers[(ring->wpos - 1) & ring->size_mask];
    ring->wpos--;
    return 1;
  }
  return 0;
}

/* Private functions ---------------------------------------------------------*/

