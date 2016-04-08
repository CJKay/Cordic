/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_VARGS_H
#define CORDIC_VARGS_H

#define _cordic_rseq_n 3, 2, 1, 0

#define _cordic_arg_n(_1, _2, _3, N, ...) N
#define _cordic_narg_i(...) _cordic_arg_n(__VA_ARGS__)
#define _cordic_narg(...) _cordic_narg_i(__VA_ARGS__, _cordic_rseq_n)

#define _cordic_vargs__(NAME, N) NAME##N
#define _cordic_vargs_(NAME, N) _cordic_vargs__(NAME, N)
#define _cordic_vargs(FN, ...) _cordic_vargs_(FN, \
    _cordic_narg(__VA_ARGS__))(__VA_ARGS__)

#endif
