/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_RESULT_H
#define CORDIC_RESULT_H

#include <stdbool.h>

struct cordic_result {
	int line;
	const char *cond;
	const char *msg;
};

#endif
