/*
 * SPDX-License-Identifier: X11
 * Copyright (C) 2026 Emily "TTG" Banerjee <prs.ttg+aga@pm.me>
 */

#include <asys/control.h>
#define ASYS_FORCE_STD_INCLUDE
#include <asys/system.h>

struct asys_interrupt_storage {
	asys_interrupt_vector_t vector;
	void* userdata;
};

static struct asys_interrupt_storage asys_global_interrupt_storage = { 0 };

static void asys_user_interrupt_vector_internal(int signal_number) {
	(void) signal_number;

	asys_global_interrupt_storage.vector(
			asys_global_interrupt_storage.userdata);
}

enum asys_result asys_set_user_interrupt_handler(
		asys_interrupt_vector_t vector, void* userdata) {

	asys_global_interrupt_storage.vector = vector;
	asys_global_interrupt_storage.userdata = userdata;

	signal(SIGINT, asys_user_interrupt_vector_internal);

	return ASYS_RESULT_OK;
}

enum asys_result asys_clear_user_interrupt_handler(void) {
	signal(SIGINT, 0);

	return ASYS_RESULT_OK;
}
