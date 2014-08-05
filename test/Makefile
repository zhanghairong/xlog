all:
	g++ *.cc -g -o test -I ../ ../libxlog.a -lrt -Wl,-Bstatic -Wl,-Bdynamic -lpthread
clean:
	rm -rf test