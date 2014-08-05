#include "LogManager.h"
#include <stdarg.h> 
#include <string.h>
#include "LogFromLog4cplus.h"

namespace xlog{
LogManager *LogManager::instance_ = NULL;
LogManager *LogManager::instance() {
    if(instance_ == NULL) {
        instance_ = new LogManager();
    }
    return instance_;
}
LogManager::LogManager() {
    memset(logModules_, 0, sizeof(logModules_));
}
void LogManager::init(const char *filename, bool isAuto) {
    LogFromLog4cplus::init(filename, isAuto);
}
void LogManager::destroy() {
    int i = 0;
    ILog *logger = NULL;
    for (i = 0; i < MAX_LOG_MODULES; ++i) {
        if(logModules_[i] != NULL) {
            logger = logModules_[i];
            delete logger;
            logModules_[i] = NULL;
        }
    }
    LogFromLog4cplus::destroy();
    delete instance_;
}
void LogManager::register_log_module(int module, const char *name) {
    if (module >= 0 && module < MAX_LOG_MODULES && logModules_[module] == NULL) {
        logModules_[module] = new LogFromLog4cplus(name);
    }
}
void LogManager::unregister_log_module(int module) {
    if (module >= 0 && module < MAX_LOG_MODULES && logModules_[module] != NULL) {
        delete logModules_[module];
        logModules_[module] = NULL;
    }
}
ILog * LogManager::get_log_module(int module) {
    if (module >= 0 && module < MAX_LOG_MODULES) {
        return logModules_[module];
    } else {
        return NULL;
    }
}
void LogManager::write_fmt(int module, const XLOG_LEVEL level, const char *fmt, ...) {
    ILog *pImp = get_log_module(module);
    if (pImp!=NULL && pImp->is_enable_level(level)) {
        va_list list;
        va_start( list, fmt ); 
        pImp->write_fmt(level, fmt, list);
        va_end( list );
    }
}
void LogManager::write_buf(int module,const XLOG_LEVEL level,const char *buf) {
    ILog *pImp=get_log_module(module);
    if (pImp!=NULL && pImp->is_enable_level(level)) {
        pImp->write_buf(level,buf);
    }
}
}

