CC=gcc
ZIGCC=zig cc
CFLAGS="-Wall"
LIN=-target x86_64-linux
WIN=-target x86_64-windows
DST=build/bin
SRC=src/rep
zig:clean
	$(ZIGCC) $(CFLAGS) $(LIN) -g -o $(DST)/rep src/rep/main.c src/rep/info.c src/rep/escape.c
	$(ZIGCC) $(CFLAGS) $(WIN) -g -o $(DST)/rep src/rep/main.c src/rep/info.c src/rep/escape.c
debug:clean
	$(CC) $(CFLAGS) -g -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c
stable:clean
	$(CC) $(CFLAGS) -g -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c
clean:
	rm -vfr *~ build/bin/rep
	rm -vfr *~ build/bin/rep.exe
	rm -vfr *~ build/bin/rep.pdp
install:
	install rep /usr/bin/rep
