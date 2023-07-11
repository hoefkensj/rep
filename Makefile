# CC=gcc
CC=/home/hoefkens/Development/Compilers/zig/zig cc
CFLAGS="-Wall"
LIN=-target x86_64-linux
WIN=-target x86_64-windows

debug:clean
	$(CC) $(CFLAGS) $(LIN) -g -o rep main.c help.c escape.c
	$(CC) $(CFLAGS) $(WIN) -g -o rep.exe main.c help.c escape.c
stable:clean
	$(CC) $(CFLAGS) $(LIN) -o rep main.c help.c escape.c
	$(CC) $(CFLAGS) $(WIN) -o rep.exe main.c help.c escape.c
clean:
	rm -vfr *~ rep
	rm -vfr *~ rep.exe
install:
	install rep /usr/bin/rep
