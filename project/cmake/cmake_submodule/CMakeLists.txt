
cmake_minimum_required(VERSION 2.8)

project("cmake_submodule" C)

option(BUILD_ALL "Build all submodule" OFF)

# ------------------------------------------------------------------------------
# Subdirectory
# ------------------------------------------------------------------------------

# Get subdirectory list
macro(SUBDIRLIST result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

SUBDIRLIST(SUB_DIRS ${PROJECT_SOURCE_DIR})
foreach(subdir ${SUB_DIRS})
  if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/${subdir}/CMakeLists.txt)
    add_subdirectory(${subdir})
  endif()
endforeach()

