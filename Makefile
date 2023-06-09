CC=gcc
ZIGCC=zig cc
CFLAGS="-Wall"
LIN=-target x86_64-linux
WIN=-target x86_64-windows
zig:clean
	$(ZIGCC) $(CFLAGS) $(LIN) -g -o build/bin/rep src/rep/main.c src/rep/help.c src/rep/escape.c
	$(ZIGCC) $(CFLAGS) $(WIN) -g -o build/bin/rep src/rep/main.c src/rep/help.c src/rep/escape.c
debug:clean
	$(CC) $(CFLAGS) -g -o build/bin/rep src/rep/main.c src/rep/help.c src/rep/escape.c
stable:clean
	$(CC) $(CFLAGS) -o build/bin/rep src/rep/main.c src/rep/help.c src/rep/escape.c
clean:
	rm -vfr *~ build/bin/rep
	rm -vfr *~ build/bin/rep.exe
	rm -vfr *~ build/bin/rep.pdp
install:
	install rep /usr/bin/rep
