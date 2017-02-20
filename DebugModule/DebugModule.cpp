// DebugModule.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "config.h"
#include "log.h"
#include "solution.h"
//void test(const int& a)
//{
//	_assert(a>=0,3);
//}

int main()
{
	//test(-1); 
	//TRACE_CODE;
	solution s;
	std::cout<<s.sum(1, 2)<< std::endl;
	system("pause");
    return 0;
}

