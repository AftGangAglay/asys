/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright (C) 2024 Emily "TTG" Banerjee <prs.ttg+aga@pm.me>
 */

#include <asys/base.h>
#include <asys/log.h>
#include <asys/error.h>
#include <asys/system.h>
#include <asys/main.h>

#ifdef ASYS_WIN32
/*
 * NOTE: The Windows 3.1 guide to programming section 14.3 states that we need
 * 		 To declare these ourselves -- this does not work under modern Windows
 * 		 As they require dllimport (depending on CRT).
 */
/*
extern int __argc;
extern char** __argv;
 */

/*
 * TODO: For some reason this doesn't link correctly under MinGW? Do we need to
 * 		 Use `--whole-archive' or reorder our links to place `WinMain' in a
 * 		 Separate library?
 * 		 For now this file just gets included into aga's build directly.
 */
int PASCAL WinMain(
		HINSTANCE instance, HINSTANCE previous, LPSTR command_line, int show) {

	struct asys_main_data main_data;

	(void) command_line;

	if(previous) {
		asys_log(
				__FILE__,
				"warn: asys cannot guarantee previous instances wont conflict"
				"with application class");
	}

	main_data.argv = __argv;
	main_data.argc = __argc;
	main_data.show = show;
	main_data.module = instance;

	asys_result_check(__FILE__, "asys_main", asys_main(&main_data));

	return 0;
}
#else
int main(int argc, char** argv) {
	struct asys_main_data main_data;

	main_data.argv = argv;
	main_data.argc = argc;

	asys_result_check(__FILE__, "asys_main", asys_main(&main_data));

	return 0;
}
#endif
