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
  
install:
	cp libxlog.a $(HOME)/local/xlog/lib/
