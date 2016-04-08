/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_TEST_H
#define CORDIC_TEST_H

#include <stdbool.h>

#include "config.h"
#include "result.h"

struct cordic_suite;

struct cordic_test {
    struct cordic_suite *suite;

    const char *name;
    const char *file;

    void (* setup)();
    void (* run)(struct cordic_test *);
    void (* teardown)();

    unsigned int num_warnings;
    struct cordic_result warnings[CORDIC_MAX_WARNINGS];

    bool failed;
    struct cordic_result error;
};

#define _cordic_test3(NAME, SETUP, TEARDOWN) \
    void _cordic_testfn_##NAME( \
        struct cordic_test *_cordic_mytest \
    ); \
    \
    struct cordic_test NAME = { \
        .name = #NAME, \
        .file = __FILE__, \
        .setup = SETUP, \
        .run = _cordic_testfn_##NAME, \
        .teardown = TEARDOWN \
    }; \
    \
    void _cordic_testfn_##NAME( \
        struct cordic_test *_cordic_mytest \
    )

#define _cordic_test1(NAME) _cordic_test3(NAME, NULL, NULL)

#define cordic_test(...) _cordic_vargs(_cordic_test, __VA_ARGS__)

#define CORDIC_TEST_NAME (_cordic_mytest->name)

#endif
