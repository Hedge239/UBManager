cmake_minimum_required(VERSION 3.0.0)
project("UniversalBackupManager" VERSION 0.0.1)

# Todo, like linking and stuff

# ----- Build Subdirectorys ----- #

message("[BUILD] -- Building Subdirectorys")

add_subdirectory(src)
add_subdirectory(Common)

# ----- Build Executable ----- #

message("[BUILD] -- Building Executable")

add_executable("ubm" "ubm.cpp") # CLI Version
set_target_properties("ubm" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${PROJECT_NAME}/bin")

#add_executable("ubm-GUI" "ubmGUI.cpp")
#set_target_properties("ubm-GUI" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${PROJECT_NAME}/bin")

include_directories(/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)