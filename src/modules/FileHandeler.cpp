#include "modules/FileHandeler.h"
#include "common/global.h"

#include <filesystem>
#include <fstream>

#ifdef _WIN32
    #include <Windows.h>
    #include <Shlobj.h>
#endif

bool osWindows()
{
    #ifdef _WIN32
        return true;
    #else
        return false;
    #endif
}


void modules::file::handeler::GetDataPath()
{
    if(osWindows)
    {
        #ifdef _WIN32
            PWSTR DataPath;
            HRESULT result = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &DataPath);

            if(result == S_OK)
            {
                std::wstring dataPathString(DataPath);
                APP::COMMON::GLOBAL::DATA_PATH = std::string(dataPathString.begin(), dataPathString.end()) + "\\UniversalBackupManager";
            }else
            {
                return;
            }
        #endif
    }else
    {
        char* DataPath = getenv("HOME");
        if(DataPath != nullptr)
        {
            APP::COMMON::GLOBAL::DATA_PATH = std::string(DataPath) + "\\.ubm";
        }else
        {
            return;
        }
    }
}

void modules::file::handeler::GetAppCfg()
{
    if(!std::filesystem::exists("app.cfg"))
    {
        std::ofstream file;

        file.open("app.cfg");
        file << "path=" + APP::COMMON::GLOBAL::DATA_PATH << std::endl;

        if(!std::filesystem::is_directory(APP::COMMON::GLOBAL::DATA_PATH))
        {
            std::filesystem::create_directory(APP::COMMON::GLOBAL::DATA_PATH);
        }

        file.close();
    }else
    {
        std::ifstream cfg("app.cfg");
        std::string cfg_line;

        if(std::getline(cfg, cfg_line))
        {
            if(cfg_line.substr(0,5) == "path=")
            {
                std::string path = cfg_line.substr(5);
                APP::COMMON::GLOBAL::DATA_PATH = path;

                if(!std::filesystem::is_directory(path))
                {
                    std::filesystem::create_directory(path);
                }
            }else
            {
                return;
            }
        }
    }
}