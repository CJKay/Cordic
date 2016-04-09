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

/**
 * @internal
 * @brief Creates a test case.
 *
 * @param NAME The name of this test case.
 * @param SETUP A fixture setup function. May be NULL.
 * @param TEARDOWN A fixture teardown function. May be NULL.
 */
#define _cordic_test3(NAME, SETUP, TEARDOWN) \
    void _cordic_testfn_##NAME(struct cordic_test *_cordic_mytest); \
    \
    struct cordic_test NAME = { \
        .name = #NAME, \
        .file = __FILE__, \
        .setup = SETUP, \
        .run = _cordic_testfn_##NAME, \
        .teardown = TEARDOWN \
    }; \
    \
    void _cordic_testfn_##NAME(struct cordic_test *_cordic_mytest)

/**
 * @internal
 * @brief Creates a test case.
 *
 * @param NAME The name of this test case.
 */
#define _cordic_test1(NAME) _cordic_test3(NAME, NULL, NULL)

#ifndef DOXYGEN
#define cordic_test(...) _cordic_vargs(_cordic_test, __VA_ARGS__)
#else
/**
 * @brief Creates a test case.
 *
 * @param NAME The name of this test case.
 * @param SETUP An optional fixture setup function. This and the @p TEARDOWN
 *     argument can be omitted.
 * @param TEARDOWN An optional fixture teardown function. This and the
 *     @p SETUP argument can be omitted.
 */
#define cordic_test(NAME, SETUP, TEARDOWN)
#endif

/**
 * @brief Used to store test case information, warnings and state.
 *
 * This structure should not be initialised manually. Instead refer
 * to the #cordic_test(NAME, SETUP, TEARDOWN) macro.
 *
 * @see #cordic_test(NAME, SETUP, TEARDOWN)
 */
struct cordic_test {
    /**
     * @brief The test suite this test case is being run by.
     *
     * @note This value will be overwritten whenever a test suite containing
     *       this test case has been started and does not need to be initialised
     *       statically.
     */
    struct cordic_suite *suite;

    /**
     * @brief This test case's name.
     */
    const char *name;

    /**
     * @brief The file this test case resides in.
     */
    const char *file;

    /**
     * @brief An optional fixture setup function to run before the test case is
     *     started.
     */
    void (* setup)();

    /**
     * @brief The test case function.
     */
    void (* run)(struct cordic_test *);

    /**
     * @brief An optional fixture teardown function to run after the test case
     *     has finished.
     */
    void (* teardown)();

    /**
     * @brief The cumulative number of warnings generated over the course of the
     * test case execution.
     *
     * @warning This value can exceed @ref CORDIC_MAX_WARNINGS and should not
     *     be used to directly index into @ref warnings.
     */
    unsigned int num_warnings;

    /**
     * @brief All the warnings generated over the course of the test case run.
     */
    struct cordic_result warnings[CORDIC_MAX_WARNINGS];

    /**
     * @brief Whether the test case run failed or not.
     */
    bool failed;

    /**
     * @brief The error generated in the case of a test case failure.
     */
    struct cordic_result error;
};

/**
 * @brief The name of the current running test case.
 */
#define CORDIC_TEST_NAME (_cordic_mytest->name)

#endif
