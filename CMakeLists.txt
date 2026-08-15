cmake_minimum_required(VERSION 3.15)
project(6502Emulator C)

enable_testing()

# --- Add this block to enable debugging ---
# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# ------------------------------------------

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ... (the rest of your CMakeLists.txt stays exactly the same)

# Define output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Include directories
include_directories(
        include
        lib/Unity-2.7.0/src
)

# Collect all source, header, and test files
file(GLOB_RECURSE ALL_SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE TEST_SOURCES "test/unit/*.c")
file(GLOB_RECURSE UNITY_SOURCES "lib/Unity-2.7.0/src/*.c")

# Exclude main.c from the source files used by unit tests
set(LIB_SOURCES ${ALL_SOURCES})
list(REMOVE_ITEM LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/main.c")

# Main executable target (uses main.c and all library sources)
add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${HEADERS})

# Unit test target (uses library sources without main.c)
# --- Unit Testing ---
# Loop through every test file found in test/unit/
foreach(TEST_FILE ${TEST_SOURCES})
    # Get the filename without the extension (e.g., "ldaTest" from "ldaTest.c")
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # Create a unique executable for each test file
    add_executable(${TEST_NAME} ${TEST_FILE} ${UNITY_SOURCES} ${LIB_SOURCES} ${HEADERS})

    # Register this specific test executable with CTest
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# --- Resource Folder Synchronization ---
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res
        COMMENT "Copying resource files to bin/res..."
)

add_dependencies(${PROJECT_NAME} copy_resources)