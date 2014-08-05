#ifndef _XLOG_ILOG_H_
#define _XLOG_ILOG_H_

#ifdef WIN32
#define XLOG_EXPORT __declspec(dllexport)
#else
#define XLOG_EXPORT
#endif

#include <stdarg.h>
typedef enum {
    XLOG_OFF = 0,
    XLOG_FATAL = 1,
    XLOG_ERROR = 2,
    XLOG_WARNING = 3,
    XLOG_INFO = 4,
    XLOG_DEBUG = 5,
    XLOG_TRACE = 6,
    XLOG_ALL = 7
}XLOG_LEVEL;


namespace xlog{
class XLOG_EXPORT ILog {
 public:
    virtual bool is_enable_level(const XLOG_LEVEL l) = 0;
    virtual void write_fmt(const XLOG_LEVEL l,const char *fmt, ...) = 0;
    virtual void write_fmt(const XLOG_LEVEL l,const char *fmt,va_list ap) = 0;
    virtual void write_buf(const XLOG_LEVEL l,const char *szBuf) = 0;
    virtual ~ILog() {}
};
}
#endif

