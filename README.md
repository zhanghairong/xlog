xlog
====

based on log4cpp

linux:
将编译后的log4cpp include文件夹 及 .a 文件拷贝至主目录下， make即可生成ligxlog.a
当log4cpp版本变更时，连接最新版本即可。

mac:
需手动将liblog4cplus.a 与 编译生成的o文件合并。 
执行 make -f Makefile.mac 即可


感谢宗指导，该库主要是宗指导的成果。 
