/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_TEST_H
#define CORDIC_TEST_H

#include "config.h"
#include "result.h"

struct cordic_test {
    const char *name;
    const char *file;

    void (* run)(struct cordic_test *);

    unsigned int num_warnings;
    struct cordic_result warnings[CORDIC_MAX_WARNINGS];

    bool failed;
    struct cordic_result error;
};

#define cordic_test(NAME) \
    void _cordic_testfn_##NAME( \
        struct cordic_test *_cordic_mytest \
    ); \
    \
    struct cordic_test NAME = { \
        .name = #NAME, \
        .file = __FILE__, \
        .run = _cordic_testfn_##NAME \
    }; \
    \
    void _cordic_testfn_##NAME( \
        struct cordic_test *_cordic_mytest \
    )

#endif
