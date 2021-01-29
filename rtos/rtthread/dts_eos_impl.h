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
    *thrd = rt_thread_create("", func, param, stack_size,
        DTS_EOS_THREAD_DEFAULT_PRIORITY, DTS_EOS_THREAD_DEFAULT_TICK);
    if (*thrd) {
        rt_thread_startup(*thrd);
    }
}
#define dts_eos_thrd_delete rt_thread_delete
#define dts_eos_thrd_suspend(thrd) do \
{ \
    rt_thread_suspend(thrd); \
    rt_schedule(); \
} while (0)
#define dts_eos_thrd_resume rt_thread_resume
#define dts_eos_thrd_sleep rt_thread_delay

#define dts_eos_mem_alloc rt_malloc
#define dts_eos_mem_free rt_free

#define dts_eos_tick_from_second(second) ((second)*RT_TICK_PER_SECOND)
#define dts_eos_tick_from_millisecond(millisecond) ((millisecond)*(RT_TICK_PER_SECOND)/1000)

#endif // DTS_EOS_IMPL_H_
