/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, you can
 * obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef CORDIC_RESULT_H
#define CORDIC_RESULT_H

/**
 * @brief Stores details about assertion failures and warnings.
 */
struct cordic_result {
    /**
     * @brief The line number the condition failed on.
     */
	int line;

	/**
	 * @brief The condition that failed.
	 */
	const char *cond;

	/**
	 * @brief An optional message.
	 */
	const char *msg;
};

#endif
