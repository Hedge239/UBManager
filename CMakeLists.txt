cmake_minimum_required(VERSION 3.5.0)
project(UniversalBackupManager VERSION 0.0.1)

set(APP_SRC
    "src/common/LogHandeler.cpp"
    "src/common/global.cpp"
    "src/modules/FileHandeler.cpp"
)

add_executable("ubm" "src/app.cpp" ${APP_SRC})

set_target_properties("ubm" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${PROJECT_NAME}/bin")

target_include_directories("ubm" PUBLIC "include")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)