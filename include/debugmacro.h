#pragma once
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef _DEBUG
#define DEBUG_MSG(str) \
    do { std::cerr \
        << __FILENAME__ <<":" << __LINE__ << ":" << __func__ << "(): " \
        << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
