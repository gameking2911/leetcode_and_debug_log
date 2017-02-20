#pragma once

#ifdef _LOG
#define LOG_INTERFACE virtual
#else 
#define LOG_INTERFACE
#endif

class Log
{
public:
	static Log* Instance();
	LOG_INTERFACE void printf(const char* format, ...) { }
};

class logfile :
	public Log
{
public:
	logfile() {};
	virtual ~logfile() {};
	void printf(const char* format, ...);
};

#ifndef _LOG
inline Log* Log::Instance()
{
	return static_cast<Log*>(0);
}

#else
inline Log* Log::Instance()
{
	static logfile instance;
	return &instance;
}

void logfile::printf(const char* format, ...)
{
	std::cout << "my" << std::endl;
}
#endif

#ifdef DEBUG_TRACE
#define TRACE_CODE Log::Instance()->printf("TRACE_CODE",__FILE__,__LINE__);
#else
#define TRACE_CODE
#endif

//#ifndef _LOG
//inline logfile* logfile::Instance()
//{
//	return static_cast<logfile*>(0);
//}
//
//inline void logfile::printf(const char* format, ...) {}
//#else
//inline logfile* logfile::Instance()
//{
//	static logfile instance;
//	return &instance;
//}
//
//void logfile::printf(const char* format, ...) 
//{
//	std::cout << 100 << std::endl;
//}
//#endif

