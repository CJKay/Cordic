/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_SUITE_H
#define CORDIC_SUITE_H

#include "test.h"

/**
 * @brief Creates a test suite.
 *
 * @param NAME The name of this test suite.
 * @param SETUP A fixture one-time setup function. May be NULL.
 * @param TEARDOWN A fixture one-time teardown function. May be NULL.
 * @param ... A list of pointers to the test cases belonging to this test suite.
 */
#define cordic_suite(NAME, SETUP, TEARDOWN, ...) \
    struct cordic_suite NAME = { \
        .name = #NAME, \
        .setup = SETUP, \
        .teardown = TEARDOWN, \
        .num_tests = sizeof((struct cordic_test *[]) { __VA_ARGS__ }) \
            / sizeof(struct cordic_test *), \
        .tests = (struct cordic_test *[]) { __VA_ARGS__ } \
    }

/**
 * @brief Define a fixture one-time setup function.
 */
#define cordic_setup_once(NAME) void NAME(void)

/**
 * @brief Define a fixture one-time teardown function.
 */
#define cordic_teardown_once(NAME) void NAME(void)

/**
 * @brief Define a fixture setup function.
 */
#define cordic_setup(NAME) void NAME(void)

/**
 * @brief Define a fixture teardown function.
 */
#define cordic_teardown(NAME) void NAME(void)

/**
 * @brief Used to store information about an entire test suite run.
 *
 * This structure should not be initialised manually. Instead refer to the
 * #cordic_suite(NAME, SETUP, TEARDOWN, ...) macro.
 *
 * @see #cordic_suite(NAME, SETUP, TEARDOWN, ...)
 */
struct cordic_suite {
    /**
     * @brief The name of this test suite.
     */
    const char *name;

    /**
     * @brief An optional fixture one-time setup function to run before the test
     *     suite is started.
     */
    void (* setup)(void);

    /**
     * @brief An optional fixture one-time teardown function to run after the
     *     test suite has finished.
     */
    void (* teardown)(void);

    /**
     * @brief The number of test cases in this test suite.
     */
    unsigned int num_tests;

    /**
     * @brief The number of test cases that failed after completing a test suite
     *     run.
     */
    unsigned int num_failed;

    /**
     * @brief A list of test cases to run.
     */
    struct cordic_test **tests;
};

/**
 * @brief The name of the current running test suite.
 */
#define CORDIC_SUITE_NAME (_cordic_mysuite->name)

/**
 * @brief Run a test suite.
 *
 * @param suite The test suite to run.
 */
void cordic_run_suite(struct cordic_suite *suite);

#endif
