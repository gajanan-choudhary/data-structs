#pragma once

#ifdef _DEBUG
#define DEBUG_MSG(str) \
    do { std::cerr \
        << __FILE__ <<":" << __LINE__ << ":" << __func__ << "(): " \
        << str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif
