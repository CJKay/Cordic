################################################################################
# This Source Code Form is subject to the terms of the Mozilla Public License, #
# v. 2.0. If a copy of the MPL was not distributed with this file, You can     #
# obtain one at http://mozilla.org/MPL/2.0/.                                   #
################################################################################

################################################################################
# Add a prefix to all values in a list.                                        #
################################################################################

function(add_prefix out prefix values)
    set(tmp "")

    foreach(value "${values}")
        list(APPEND tmp "${prefix}${value}")
    endforeach()

    set(${out} ${tmp} PARENT_SCOPE)
endfunction()
