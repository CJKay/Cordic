/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "suite.h"

void cordic_run_suite(struct cordic_suite *suite) {
    if(suite->setup)
        suite->setup();

    for(unsigned int i = 0; i < suite->num_tests; i++) {
        struct cordic_test *test = suite->tests[i];

        if(test->setup)
            test->setup();

        test->suite = suite;
        test->run(test);

        if(test->failed)
            suite->num_failed++;

        if(test->teardown)
            test->teardown();
    }

    if(suite->teardown)
       suite->teardown();
}
