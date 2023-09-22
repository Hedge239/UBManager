// CLI version | Bellow logo use for later
//             ___       ___       ___
//            /\__\     /\  \     /\__\\
//           /:/ _/_   /::\  \   /::L_L_
//          /:/_/\__\ /::\:\__\ /:/L:\__\\
//          \:\/:/  / \:\::/  / \/_/:/  /
//           \::/  /   \::/  /    /:/  /
//            \/__/     \/__/     \/__/

#include "common/LogHandeler.h"
#include "modules/FileHandeler.h"
#include "common/global.h"

#ifdef _WIN32
    #include <windows.h>
#endif

#include <filesystem>
#include <iostream>


void appSetup()
{
    APP::COMMON::LOG::ToFile("ubm-cli", "Faild to find app.cfg");
    APP::COMMON::LOG::ToFile("ubm-cli", "Performing first-time setup");

    std::string UserInput;
    std::cout << "Please Answer the following questions" << std::endl;

    while(true)
    {
        std::cout << "Auto-update the application when able too? (Y/N): ";

        std::cin >> UserInput;

        if(UserInput == "Y")
        {
            break;
        }else if(UserInput == "N")
        {
            break;
        }else
        {
            std::cout << "Unkown Input: " << UserInput << " Please enter 'Y' or 'N'." << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    // Application arguments/initilzation for OS
    #ifdef _WIN32
        AllocConsole();                     // Alocate a new console for this app
        freopen("CONOUT$", "w", stdout);    // Redirect output to CMD window
        freopen("CONIN$", "r", stdin);      // Redirect Input to CMD window
    #endif

    std::string UsePreset;

    for(int i = 1; i < argc; ++i)
    {
        std::string argument = argv[i];

        // Check for arguments
        if(argument.substr(0,2) == "--")
            UsePreset = argument.substr(2);
    }

    // Application setup/initilzation
    if(!std::filesystem::exists("app.cfg"))
        modules::file::handeler::GetDataPath();
    
    modules::file::handeler::GetAppCfg();
    if(APP::COMMON::GLOBAL::DATA_PATH == "")
    {
        std::string userInput;

        std::cout << "[UBM] [ERROR] Faild to find valid DATA_PATH, unable to proceede" << std::endl;
        std::cout << "Press ENTER to continue";

        std::cin >> userInput;
        exit(-1);
    }

    APP::COMMON::LOG::RemoveFile("ubm-cli");
    APP::COMMON::LOG::ToFile("ubm-cli", "Data Path located: " + APP::COMMON::GLOBAL::DATA_PATH);
    APP::COMMON::LOG::ToFile("ubm-cli", "Checking for app.cfg...");

    if(!std::filesystem::exists(APP::COMMON::GLOBAL::DATA_PATH + "/app.cfg"))
        appSetup();
    
    // Application Runtime
    if(UsePreset == "")
    {

    }else
    {

    }
}
