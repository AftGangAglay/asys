/*
* SPDX-License-Identifier: X11
 * Copyright (C) 2026 Emily "TTG" Banerjee <prs.ttg+asys@pm.me>
 */

#ifndef ASYS_CONTROL_H
#define ASYS_CONTROL_H

#include <asys/result.h>

typedef void (*asys_interrupt_vector_t)(void*);

enum asys_result asys_set_user_interrupt_handler(asys_interrupt_vector_t, void*);

/*
 * Interrupt handler should be cleared at the start of the vector call to avoid
 * Nested states.
 */
enum asys_result asys_clear_user_interrupt_handler(void);

#endif
