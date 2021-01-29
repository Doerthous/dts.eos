/*
   The MIT License (MIT)

   Copyright (c) 2021 Doerthous

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

   Authour: Doerthous <doerthous@gmail.com>
*/

#ifndef DTS_EOS_IMPL_H_
#define DTS_EOS_IMPL_H_

static inline void
dts_eos_thrd_new(dts_eos_thrd_t **thrd, void (*func)(void *), void *param, size_t stack_size)
{
    BaseType_t ret = xTaskCreate((TaskFunction_t)func, "",
        (uint16_t)stack_size, param, 
        (UBaseType_t)DTS_EOS_THREAD_DEFAULT_PRIORITY, 
        (TaskHandle_t *)thrd);
    if (ret != pdPASS) {
        while (1);
    }
}
#define dts_eos_thrd_delete vTaskDelete
#define dts_eos_thrd_suspend vTaskSuspend
#define dts_eos_thrd_resume vTaskResume
#define dts_eos_thrd_sleep vTaskDelay

#define dts_eos_mem_alloc pvPortMalloc
#define dts_eos_mem_free vPortFree

#define dts_eos_tick_from_second(second) ((second)*configTICK_RATE_HZ)
#define dts_eos_tick_from_millisecond(millisecond) ((millisecond)*(configTICK_RATE_HZ)/1000)

#define dts_eos_mutex_new xSemaphoreCreateMutex
#define dts_eos_mutex_delete vSemaphoreDelete
#define dts_eos_mutex_lock(m) xSemaphoreTake(m, 0xFFFF)
#define dts_eos_mutex_unlock xSemaphoreGive

#endif // DTS_EOS_IMPL_H_
