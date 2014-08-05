#include "LogManager.h"

const int BUSINESS_MODULE = 102;
DEFINE_MODULE_XLOG(BUSINESS_MODULE, BS_XLOG)
#define BS_SLOG(Level,Event) SLOG(BUSINESS_MODULE,Level,Event)

void stop() {
    XLOG_DESTROY();
}
int main() {
    XLOG_INIT("log.properties", true);
    XLOG_REGISTER(BUSINESS_MODULE, "business");
    BS_XLOG(XLOG_DEBUG," ========== %s ========\n", __FUNCTION__);
    stop();
    return 0;
}