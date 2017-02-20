#pragma once
#define Error \
exit(1)

#define _DEBUG
#define ASSERT_LEVEL 1

#ifdef _DEBUG
#define _FDEBUG(LINE) LINE

#define ASSERT(c) if(c) 0;else \
_myassert(#c,__FILE__,__lINE__)
#else
#define ASSERT(c) 0
#define _FDEBUG 0
#endif

#ifdef ASSERT_LEVEL
#define ASSERTP(C,P) \
	if(P>=ASSERT_LEVEL)\
{
	if(!C)\
	{_assert(#C, __FILE__, __lINE__); }

}
#else
	#define ASSERTP(C,P) 0
#endif

class Debug
{
public:
	Debug();
	~Debug();
};

