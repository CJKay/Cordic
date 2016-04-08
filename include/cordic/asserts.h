/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_ASSERTS_H
#define CORDIC_ASSERTS_H

#include <stddef.h>

#include "vargs.h"

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

#define _cordic_assert1(COND) _cordic_assert2(COND, NULL)

#define cordic_assert(...) _cordic_vargs(_cordic_assert, __VA_ARGS__)

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

#define _cordic_warn1(COND) _cordic_warn2(COND, NULL)

#define cordic_warn(...) _cordic_vargs(_cordic_warn, __VA_ARGS__)

#endif
