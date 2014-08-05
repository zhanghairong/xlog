#ifndef _XLOG_LOG_MANAGER_H_
#define _XLOG_LOG_MANAGER_H_
#include "ILog.h"
#include <sstream>
namespace xlog{
const int MAX_LOG_MODULES = 128;
class XLOG_EXPORT LogManager {
  public:
    static LogManager * instance();
    void init(const char *filename, bool isAuto = false);
    void register_log_module(int module, const char *name);
    void unregister_log_module(int module);
    ILog * get_log_module(int module);
    void write_fmt(int module, const XLOG_LEVEL level, const char *fmt, ...);
    void write_buf(int module, const XLOG_LEVEL level, const char *buf);
    void destroy();
  private:
    LogManager();
    static LogManager *instance_;
    ILog *logModules_[MAX_LOG_MODULES];
};
}

#define XLOG_INIT xlog::LogManager::instance()->init
#define XLOG_DESTROY xlog::LogManager::instance()->destroy
#define XLOG_REGISTER(module, name) xlog::LogManager::instance()->register_log_module(module, name)
#define XLOG_UNREGISTER(module) xlog::LogManager::instance()->unregister_log_module(module) 
#define XLOG xlog::LogManager::instance()->write_fmt
#define XLOG_BUFFER xlog::LogManager::instance()->write_buf

#define SLOG(Module, Level, Event) \
    do{ \
        xlog::ILog *logger = xlog::LogManager::instance()->get_log_module(Module); \
        if(logger != NULL && logger->is_enable_level(Level)) { \
            std::ostringstream _SLOG_BUF_INTERNAL_; \
            _SLOG_BUF_INTERNAL_<<Event; \
            logger->write_buf(Level, _SLOG_BUF_INTERNAL_.str().c_str()); \
        } \
    }while(0);

#define DEFINE_MODULE_XLOG(module, xlog_func) \
    inline void xlog_func(const XLOG_LEVEL level, const char *fmt, ...) \
    { \
        xlog::ILog *logger = xlog::LogManager::instance()->get_log_module(module); \
        if (logger != NULL && logger->is_enable_level(level)) { \
            va_list list; \
            va_start( list, fmt );  \
            logger->write_fmt(level, fmt, list); \
            va_end( list ); \
        } \
    }
#endif


