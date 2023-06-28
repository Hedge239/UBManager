cmake_minimum_required(VERSION 3.0.0)
project("UniversalBackupManager" VERSION 0.0.1)

# Todo, like linking and stuff

# ----- Build Subdirectorys ----- #

message("[BUILD] -- Building Subdirectorys")

set(COMMON_SRC
    "src/dobackup.cpp"          # Using set settings, creates a backup
    "src/installer.cpp"         # Install/uninstall the application to allow it to be run in cmd by just typeing .ubm or .ubm --gui (GUI application can just be launched via executable)
    "src/fmManager.cpp"         # Manages Memory and application files such as temp, DOES NOT manager moving files to backup drive or location
    "Common/logManager.cpp"     # Manages application logs
)

# set(GUI_SRC)

# ----- Build Executable ----- #

message("[BUILD] -- Building Executable")

add_executable("ubm" "ubm.cpp" ${COMMON_SRC}) # CLI Version
set_target_properties("ubm" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${PROJECT_NAME}/bin")

#add_executable("ubm-GUI" "ubmGUI.cpp" ${COMMON_SRC})
#set_target_properties("ubm-GUI" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${PROJECT_NAME}/bin")

include_directories(/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)