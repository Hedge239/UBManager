cmake_minimum_required(VERSION 3.5.0)
project(UBM VERSION 0.0.1)

include(".buildtools/cmake/ubm.cmake")
option(BUILD_UI "Build ubm-ui executable" OFF)

# Build Terminal Application
add_executable(ubm "src/terminal.cpp")
target_sources(ubm PRIVATE ${APP_SRC})

set_target_properties(ubm PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../UniversalBackupManager")
target_include_directories(ubm PRIVATE "include")

# Build UI Application
if(BUILD_UI)
    message(FATAL_ERROR "UI in Development")
endif()

file(COPY "assets/" DESTINATION "${CMAKE_BINARY_DIR}/../UniversalBackupManager")