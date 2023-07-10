CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o rep main.c help.c escape.c
stable:clean
	$(CC) $(CFLAGS) -o rep main.c help.c escape.c
clean:
	rm -vfr *~ rep
install:
	install rep /usr/bin/rep
