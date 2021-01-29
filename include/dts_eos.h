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

#ifndef DTS_EOS_H_
#define DTS_EOS_H_

#include <dts_eos_conf.h>
#include <dts_eos_t.h>

void dts_eos_thrd_new(dts_eos_thrd_t **thrd, void (*func)(void *), void *param, size_t stack_size);
void dts_eos_thrd_delete(dts_eos_thrd_t *thrd);
void dts_eos_thrd_suspend(dts_eos_thrd_t *thrd);
void dts_eos_thrd_resume(dts_eos_thrd_t *thrd);
void dts_eos_thrd_sleep(dts_eos_tick_t *ticks);

dts_eos_tick_t dts_eos_tick_from_second(size_t second);
dts_eos_tick_t dts_eos_tick_from_millisecond(size_t millisecond);

#ifndef DTS_EOS_MEM_SIZE_T
# define DTS_EOS_MEM_SIZE_T size_t
#endif
void *dts_eos_mem_alloc(DTS_EOS_MEM_SIZE_T *size);
void dts_eos_mem_free(void *ptr);

dts_eos_mutex_t *dts_eos_mutex_new(void);
void dts_eos_mutex_delete(dts_eos_mutex_t *mutex);
void dts_eos_mutex_lock(dts_eos_mutex_t *mutex);
void dts_eos_mutex_unlock(dts_eos_mutex_t *mutex);

#ifdef DTS_EOS_IMPL
# include <dts_eos_impl.h>
#endif // DTS_EOS_IMPL_H_

#endif // DTS_EOS_H_
