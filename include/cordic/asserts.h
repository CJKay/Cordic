/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_ASSERTS_H
#define CORDIC_ASSERTS_H

#include <stddef.h>

#include "vargs.h"

/**
 * @internal
 * @brief Generates an error in a test function if the condition evaluates to
 *     @c false.
 *
 * @param COND The condition that must be evaluated to determine if an error
 *     will be generated.
 * @param MSG An error message. May be NULL.
 */
#define _cordic_assert2(COND, MSG) \
    if(!(COND)) { \
        _cordic_mytest->failed = true; \
        _cordic_mytest->error = \
            (struct cordic_result) { \
                __LINE__, \
                #COND, \
                (MSG) \
            }; \
        \
        return; \
    }

/**
 * @internal
 * @brief Generates an error in a test function if the condition evaluates to
 *     @c false.
 *
 * @param COND The condition that must be evaluated to determine if an error
 *     will be generated.
 */
#define _cordic_assert1(COND) _cordic_assert2(COND, NULL)

/**
 * @internal
 * @brief Generates a warning in a test function if the condition evaluates to
 *     @c true.
 *
 * @param COND The condition that must be evaluated to determine if a warning
 *     will be generated.
 * @param MSG A warning message. May be NULL.
 */
#define _cordic_warn2(COND, MSG) \
    if(COND) { \
        _cordic_mytest->num_warnings++; \
        if(_cordic_mytest->num_warnings <= CORDIC_MAX_WARNINGS) { \
            _cordic_mytest->warnings[_cordic_mytest->num_warnings - 1] = \
                (struct cordic_result) { \
                    __LINE__, \
                    #COND, \
                    (MSG) \
                }; \
        } \
    }

/**
 * @internal
 * @brief Generates a warning in a test function if the condition evaluates to
 *     @c true.
 *
 * @param COND The condition that must be evaluated to determine if a warning
 *     will be generated.
 */
#define _cordic_warn1(COND) _cordic_warn2(COND, NULL)

#ifndef DOXYGEN
#define cordic_warn(...) _cordic_vargs(_cordic_warn, __VA_ARGS__)
#define cordic_assert(...) _cordic_vargs(_cordic_assert, __VA_ARGS__)
#else
/**
 * @brief Generates a warning in a test function if the condition evaluates to
 *     @c true.
 *
 * @param COND The condition that must be evaluated to determine if a warning
 *     will be generated.
 * @param MSG An optional warning message. This argument may be omitted.
 */
#define cordic_warn(COND, MSG)

/**
 * @brief Generates an error in a test function if the condition evaluates to
 *     @c false.
 *
 * @param COND The condition that must be evaluated to determine if an error
 *     will be generated.
 * @param MSG An optional error message. This argument can be omitted.
 */
#define cordic_assert(COND, MSG)
#endif

#endif
