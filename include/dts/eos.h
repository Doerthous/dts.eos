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

#ifndef EOS_H_
#define EOS_H_

#include <dts_eos.h>

#define thrd_t dts_eos_thrd_t
#define thrd_new dts_eos_thrd_new
#define thrd_delete dts_eos_thrd_delete
#define thrd_suspend dts_eos_thrd_suspend
#define thrd_resume dts_eos_thrd_resume
#define thrd_sleep dts_eos_thrd_sleep

#define tick_from_second dts_eos_tick_from_second
#define tick_from_millisecond dts_eos_tick_from_millisecond

#define mem_alloc dts_eos_mem_alloc
#define mem_free dts_eos_mem_free

#define mutex_t dts_eos_mutex_t
#define mutex_new dts_eos_mutex_new
#define mutex_delete dts_eos_mutex_delete
#define mutex_lock dts_eos_mutex_lock
#define mutex_unlock dts_eos_mutex_unlock

#endif // EOS_H_
