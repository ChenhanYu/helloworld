# Check cmake version.
# ---------------------------
cmake_minimum_required (VERSION 2.8)

# Configure the path structure.
# ---------------------------
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RELEASE_POSTFIX "")
set (CMAKE_DEBUG_POSTFIX "-debug")

# Project specification.
# ---------------------------
#project (PROJECT)
project ($ENV{PROJECT_NAME})

# Custom CFLAGS
# ---------------------------
find_program (ICC_PATH "icc")
find_program (ICPC_PATH "icpc")
set (CMAKE_C_COMPILER ${ICC_PATH})
set (CMAKE_CXX_COMPILER ${ICPC_PATH})
set (PROJECT_CFLAGS "-std=c++11 -O3")
set (PROJECT_EXE_LINKER_FLAGS "-mkl=parallel")

# Setup all flags
# ---------------------------
set (CMAKE_C_FLAGS        "${CMAKE_C_FLAGS} ${PROJECT_CFLAGS}")
set (CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} ${PROJECT_CFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_EXE_LINKER_FLAGS}")

# Headers.
# ---------------------------
include_directories ("include" "frame")
file (GLOB PROJECT_HDRS ${CMAKE_SOURCE_DIR}/include/*)
install (FILES ${PROJECT_HDRS} DESTINATION ${CMAKE_BINARY_DIR}/include)


# Library dependencies
# ---------------------------
file (GLOB CXX_SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library ($ENV{PROJECT_NAME} STATIC ${CXX_SRC})

# Build the executable files.
# ---------------------------
file (GLOB TEST_CXX_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp)
foreach( testsrc ${TEST_CXX_SRC} )
  string( REPLACE ".cpp" ".x" testexe ${testsrc} )
  get_filename_component( testexe ${testsrc} NAME_WE )
  add_executable( "${testexe}.x" ${testsrc} )
  target_link_libraries( "${testexe}.x" $ENV{PROJECT_NAME} )
endforeach()
