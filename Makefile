CC = gcc
CFLAGS = -c -Wall -I./include

all: bin/nxfanctl

bin/nxfanctl: obj/main.o obj/config.o
	${CC} obj/main.o obj/config.o -o bin/nxfanctl

obj/main.o: src/main.c
	${CC} ${CFLAGS} src/main.c -o obj/main.o

obj/config.o: src/config.c
	${CC} ${CFLAGS} src/config.c -o obj/config.o

install:
	cp bin/nxfanctl /usr/local/bin

uninstall:
	rm -f /usr/local/bin/nxfanctl
	rm -f /etc/nxfan.conf	

clean:
	rm -f  bin/* obj/*

cleanall: clean
	rm -f src/*~ include/*~
