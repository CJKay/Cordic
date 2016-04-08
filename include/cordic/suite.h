/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_SUITE_H
#define CORDIC_SUITE_H

#include "test.h"

struct cordic_suite {
    const char *name;

    void (* setup)(void);
    void (* teardown)(void);

    unsigned int num_tests;
    unsigned int num_failed;
    struct cordic_test **tests;
};

#define cordic_suite(NAME, SETUP, TEARDOWN, ...) \
    struct cordic_suite NAME = { \
        .name = #NAME, \
        .setup = SETUP, \
        .teardown = TEARDOWN, \
        .num_tests = sizeof((struct cordic_test *[]) { __VA_ARGS__ }) \
            / sizeof(struct cordic_test *), \
        .tests = (struct cordic_test *[]) { __VA_ARGS__ } \
    }
#define cordic_setup_once(NAME) void NAME(void)
#define cordic_teardown_once(NAME) void NAME(void)

#define cordic_setup(NAME) void NAME(void)
#define cordic_teardown(NAME) void NAME(void)

#define CORDIC_SUITE_NAME (_cordic_mysuite->name)

void cordic_run_suite(struct cordic_suite *suite);

#endif
