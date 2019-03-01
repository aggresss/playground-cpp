# reference: https://cmake.org/cmake/help/latest/command/string.html
cmake_minimum_required (VERSION 2.8)

# ------------------------------------------------------------------------------

# Returns the compiler prefix
function(compiler_prefix input_string output_string)
    string(REGEX MATCH "[^/]+$" compiler_basename ${input_string})
    string(REGEX MATCH "[^-]+$" compiler_id ${compiler_basename})
    if(NOT ${compiler_basename} STREQUAL ${compiler_id})
        string(REPLACE "-${compiler_id}" "" compiler_host ${compiler_basename})
    endif()
    set(${output_string} ${compiler_host} PARENT_SCOPE)
endfunction()

# Test function compiler_prefix
set(COMPILER_STRING "/usr/local/bin/arm-linux-gcc")
message("COMPILER_STRING: " ${COMPILER_STRING})
compiler_prefix(${COMPILER_STRING} COMPILER_PREFIX)
message("COMPILER_PREFIX: " ${COMPILER_PREFIX})

# ------------------------------------------------------------------------------

#
function(compiler_arch_os input_string output_string)
    string(REGEX REPLACE "([A-Za-z0-9_\\.]+)\\-([A-Za-z0-9_\\.]+)\\-([A-Za-z0-9_\\.]+)" "\\1-\\2"
      string_arch_os ${input_string})

    set(${output_string} ${string_arch_os} PARENT_SCOPE)
endfunction()

# Test function compiler_arch_os
set(COMPILER_TRIPLET "x86_64-apple-darwin17.5.0")
message("COMPILER_TRIPLET: " ${COMPILER_TRIPLET})
compiler_arch_os(${COMPILER_TRIPLET} COMPILER_ARCH_OS)
message("COMPILER_ARCH_OS: " ${COMPILER_ARCH_OS})


