CC=gcc
ZIGCC=zig cc
CFLAGS="-Wall"
LIN=-target x86_64-linux
WIN=-target x86_64-windows
DST=build/bin
SRC=src/rep
debug:clean
	$(CC) $(CFLAGS) -g -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
stable:clean
	$(CC) $(CFLAGS) -g -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
clean:
	rm -vfr *~ build/bin/rep
	rm -vfr *~ build/bin/rep.exe
	rm -vfr *~ build/bin/rep.pdp
install:
	install  build/bin/rep /usr/bin/rep
