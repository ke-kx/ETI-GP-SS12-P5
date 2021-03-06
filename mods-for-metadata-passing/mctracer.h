/*
   ----------------------------------------------------------------

   Notice that the following BSD-style license applies to this one
   file (mctracer.h) only.  The rest of Valgrind is licensed under the
   terms of the GNU General Public License, version 2, unless
   otherwise indicated.  See the COPYING file in the source
   distribution for details.

   ----------------------------------------------------------------

   This file is part of McTracer, a Valgrind tool for memory tracing.
   Written for ETI @ TUM, McVisCas2010, (C) 2010 Josef Weidendorfer.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

   2. The origin of this software must not be misrepresented; you must
      not claim that you wrote the original software.  If you use this
      software in a product, an acknowledgment in the product
      documentation would be appreciated but is not required.

   3. Altered source versions must be plainly marked as such, and must
      not be misrepresented as being the original software.

   4. The name of the author may not be used to endorse or promote
      products derived from this software without specific prior written
      permission.

   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   ----------------------------------------------------------------

   Notice that the above BSD-style license applies to this one file
   (callgrind.h) only.  The entire rest of Valgrind is licensed under
   the terms of the GNU General Public License, version 2.  See the
   COPYING file in the source distribution for details.

   ----------------------------------------------------------------
*/

#ifndef __MCTRACER_H
#define __MCTRACER_H

#include "valgrind.h"

/* !! ABIWARNING !! ABIWARNING !! ABIWARNING !! ABIWARNING !!
   This enum comprises an ABI exported by Valgrind to programs
   which use client requests.  DO NOT CHANGE THE ORDER OF THESE
   ENTRIES, NOR DELETE ANY -- add new ones at the end.
 */

typedef
   enum {
      VG_USERREQ__PRINT = VG_USERREQ_TOOL_BASE('M','T'),
      VG_USERREQ__PRINTA,
      VG_USERREQ__PRINTU,
      VG_USERREQ__TRACING,
      VG_USERREQ__SIMPLESIM_DEFINE_DATA,
      VG_USERREQ__SIMPLESIM_CHANGE_SECTION,
      VG_USERREQ__SIMPLESIM_CONFIGURE
   } Vg_McTracerClientRequest;

/* Print a string into the trace, prefixed by "P  " */
#define MCTRACER_PRINT(str)              				\
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__PRINT,                          \
                            str, 0, 0, 0, 0);                           \
   }

/* Print a string and a hex address into the trace, prefixed by "PA " */
#define MCTRACER_PRINTA(addr)             				\
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__PRINTA,                         \
			       addr, 0, 0, 0, 0);                        \
   }

/* Print a string and an unsigned into the trace, prefixed by "PU " */
#define MCTRACER_PRINTU(uval)             				\
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__PRINTU,                         \
			       uval, 0, 0, 0, 0);			\
   }

/* Switch tracing on */
#define MCTRACER_TRACING_ON                 				\
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__TRACING,                        \
                            1, 0, 0, 0, 0);                             \
   }

/* Switch tracing off */
#define MCTRACER_TRACING_OFF                 				\
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__TRACING,                        \
                            0, 0, 0, 0, 0);                             \
   }

/* Define a data range for the SimpleSim cache simulator */
#define SIMPLESIM_DEFINE_DATA(description, start, length)     \
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__SIMPLESIM_DEFINE_DATA,          \
                            description, start, length, 0, 0);          \
   }

/* Change section in SimpleSim cache simulator to section #id*/
#define SIMPLESIM_CHANGE_SECTION(id,description)     \
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__SIMPLESIM_CHANGE_SECTION,       \
                            id, description, 0, 0, 0);               \
   }

/* Init the SimpleSim cache simulator (cachesize) */
#define SIMPLESIM_CONFIGURE(setting, value)         \
   {unsigned int _qzz_res;                                              \
    VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \
                            VG_USERREQ__SIMPLESIM_CONFIGURE,          \
                            setting, value, 0, 0, 0);          \
   }

#endif /* __MCTRACER_H */
