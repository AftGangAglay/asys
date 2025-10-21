/*
 * SPDX-License-Identifier: X11
 * Copyright (C) 2025 Emily "TTG" Banerjee <prs.ttg+asys@pm.me>
 */

#include <asys/getopt.h>
#include <asys/base.h>

#ifndef ASYS_UNIX
/* Prefer system `getopt'. */
# include <port/getopt.c>
#endif
