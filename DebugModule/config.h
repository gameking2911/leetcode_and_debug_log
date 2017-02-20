#pragma once
#include <iostream>

#define _DEBUG
#define _ASSERT_LEVEL
#define _LOG
#define DEBUG_TRACE

//自定义assert更多行为
#ifdef _DEBUG
#define _assert(c) if(c) 0;else \
__assert(#c,__FILE__,__LINE__)

#ifdef _ASSERT_LEVEL
#define LEVEL 2
#define _assert(c,level) if(level<=LEVEL) 0;else \
if(!c) __assert(#c,__FILE__,__LINE__)
#endif

#else
#define _assert(c) 0
#endif 


void __assert(const char* a, const char* b, const int c)
{
	std::cout << a << ',' << b << ',' << c << std::endl;
}