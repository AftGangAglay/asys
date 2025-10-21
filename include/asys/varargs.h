/*
 * SPDX-License-Identifier: X11
 * Copyright (C) 2025 Emily "TTG" Banerjee <prs.ttg+asys@pm.me>
 */

#ifndef ASYS_VARARGS_H
#define ASYS_VARARGS_H

#include <asys/base.h>

/* NOTE: It's unclear whether Windows 3.1 exposed `stdarg.h'. */
#if defined(ASYS_STDC) || defined(ASYS_GNUC) /* GCC dropped `varargs.h'. */
# include <stdarg.h>
#else
# include <varargs.h>
#endif

#endif
