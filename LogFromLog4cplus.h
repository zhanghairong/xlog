#ifndef _XLOG_LOG_FROM_LOG4CPLUS_H_
#define _XLOG_LOG_FROM_LOG4CPLUS_H_
#include "ILog.h"
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>

using namespace log4cplus;
namespace xlog{
class LogFromLog4cplus : public ILog {
public:
    static void init(const char *filename, bool isAuto);
    static void destroy();
    LogFromLog4cplus(const char * instance);
    virtual bool is_enable_level(const XLOG_LEVEL l);
    virtual void write_fmt(const XLOG_LEVEL l,const char *fmt, ...);
    virtual void write_fmt(const XLOG_LEVEL l,const char *fmt,va_list ap);
    virtual void write_buf(const XLOG_LEVEL l,const char *szBuf);
private:
    Logger imp_;
    static ConfigureAndWatchThread *watchdog_thread_;
};
}

#endif

