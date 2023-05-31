CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o rep main.c
stable:clean
	$(CC) $(CFLAGS) -o rep main.c
clean:
	rm -vfr *~ rep
install:
	install rep /usr/bin/rep
