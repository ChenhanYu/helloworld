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
project (HELLOWORLD)

# Custom CFLAGS
# ---------------------------
set (HELLOWORLD_CFLAGS "-std=c++11 -03")
set (HELLOWORLD_EXE_LINKER_FLAGS "")

# Setup all flags
# ---------------------------
set (CMAKE_C_FLAGS        "${CMAKE_C_FLAGS} ${HELLOWORLD_CFLAGS}")
set (CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} ${HELLOWORLD_CFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${HELLOWORLD_EXE_LINKER_FLAGS}")

# Headers.
# ---------------------------
include_directories ("include" "frame")
file (GLOB HELLOWORLD_HDRS ${CMAKE_SOURCE_DIR}/include/*)
install (FILES ${HELLOWORLD_HDRS} DESTINATION ${CMAKE_BINARY_DIR}/include)


# Library dependencies
# ---------------------------
file (GLOB CXX_SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library (helloworld STATIC ${CXX_SRC})

# Build the executable files.
# ---------------------------
file (GLOB TEST_CXX_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp)
foreach( testsrc ${TEST_CXX_SRC} )
  string( REPLACE ".cpp" ".x" testexe ${testsrc} )
  get_filename_component( testexe ${testsrc} NAME_WE )
  add_executable( "${testexe}.x" ${testsrc} )
  target_link_libraries( "${testexe}.x" helloworld )
endforeach()
