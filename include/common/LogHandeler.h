#ifndef _LOGHANDLER_H_
#define _LOGHANDELER_H_

#include <string>

namespace APP
{
    namespace COMMON
    {
        class LOG
        {
            public:
            static void ToFile(std::string FILE_NAME, std::string LOG_MESSAGE);
            static void RemoveFile(std::string FILE_NAME);
        };
    }
}

#endif /*_LOGHANDELER_H_*/