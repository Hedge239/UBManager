#ifndef _FILEHANDELER_H_
#define _FILEHANDELER_H_

#include <string>

namespace modules
{
    namespace file
    {
        class handeler
        {
            public:
            static void GetDataPath();
            static void GetAppCfg();
        };
    }
}

#endif /*_FILEHANDELER_H_*/