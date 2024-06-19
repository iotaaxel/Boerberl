cmake_minimum_required(VERSION 3.14)
project(Boerboel)


# Add header files in the lib
include_directories(lib)
# Set up clang-tidy
find_program(CLANG_TIDY NAMES clang-tidy)
if (CLANG_TIDY)
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY"}
endif()

# Add source files
add_subdirectory(src)

# Set sources variable with a link to all cpp files to compile
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Add executable
add_executable(Boerboel ${SOURCES})
target_include_directories(Boerboel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link libraries
target_link_libraries(Boerboel PUBLIC ${LIBRARIES})

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL ${CMAKE_CURRENT_SOURCE_DIR}/googletest-5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Add tests
add_subdirectory(test)

