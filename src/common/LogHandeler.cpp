#include "common/LogHandeler.h"
#include "common/global.h"

#include <filesystem>
#include <fstream>
#include <string>


void APP::COMMON::LOG::ToFile(std::string FILE_NAME, std::string LOG_MESSAGE)
{
    std::string file_path = "logs/"+ FILE_NAME + ".log";
    
    std::ofstream file;
    if(std::filesystem::exists(file_path))
    {
        file.open(file_path, std::ios_base::app);
    }else
    {
        file.open(file_path, std::ios::out);
    }

    file << "[" << __TIME__ << "] " << LOG_MESSAGE << std::endl;
    file.close();
}

void APP::COMMON::LOG::RemoveFile(std::string FILE_NAME)
{
    std::string file_path = "logs/" + FILE_NAME + ".log";

    if(std::filesystem::exists("app.cfg"))
        std::filesystem::remove(file_path);
}