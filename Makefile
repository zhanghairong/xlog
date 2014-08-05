AR     =       ar
RM     =       rm
CP     =       cp
ECHO  =       echo

INCLUDES    = -I./ -I./log4cplus
CFLAGS      += -O $(INCLUDES)

include     tool.mak
TARGET      = libxlog.a
LIBS        = liblog4cplus.a
OBJS        = LogFromLog4cplus.o LogManager.o

all:$(TARGET)

$(TARGET):$(OBJS) $(LIBS)
	$(BUILD_LIBRARY)

%.o:%.cpp
	g++ -c -fPIC $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(TARGET)

INSTALLDIR=$(HOME)/local/xlog2
install:
	if [ ! -d "$(INSTALLDIR)/lib/" ];  then mkdir -p $(INSTALLDIR)/lib; fi;
	if [ ! -d "$(INSTALLDIR)/include/" ];  then mkdir -p $(INSTALLDIR)/include; fi;
	cp ILog.h $(INSTALLDIR)/include/;
	cp LogManager.h $(INSTALLDIR)/include/;
	cp -r log4cplus $(INSTALLDIR)/include/;
	cp libxlog.a $(INSTALLDIR)/lib/;
