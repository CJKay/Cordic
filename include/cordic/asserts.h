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
        return (struct cordic_result) { \
            .line = __LINE__, \
            .file = __FILE__, \
            .fn = __func__, \
            .msg = MSG \
        }; \
    }

#define _cordic_assert1(COND) _cordic_assert2(COND, NULL)

#define cordic_assert(...) _cordic_vargs(_cordic_assert, __VA_ARGS__)

#define cordic_success \
    return (struct cordic_result) { \
        -1, __FILE__, __func__, NULL \
    }

#endif
