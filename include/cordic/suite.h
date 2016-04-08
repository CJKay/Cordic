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

#endif
