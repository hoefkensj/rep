CC=gcc
ZIGCC=zig cc
CFLAGS="-Wall"
LIN=-target x86_64-linux
WIN=-target x86_64-windows
DST=build/bin
SRC=src/rep


g-unescape:clean-lin-unescape
	$(CC) $(CFLAGS) -o $(DST)/unescape $(SRC)/unescape_standalone.c  $(SRC)/escape.c $(SRC)/about.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
g-rep:clean-lin-rep
	$(CC) $(CFLAGS) -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
z-rep-lin-x64:clean-lin-rep
	$(ZIGCC) $(LIN) $(CFLAGS) -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
z-unescape-lin-x64:clean-lin-unescape
	$(ZIGCC) $(LIN) $(CFLAGS) -o $(DST)/unescape $(SRC)/escape.c $(SRC)/about.c $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c
z-win-x61:cleanwin
	$(ZIGCC) $(WIN) $(CFLAGS) -g -o $(DST)/rep.exe $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/info.c $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c

debug:clean-lin
	$(CC) $(CFLAGS) -g -o $(DST)/rep $(SRC)/main.c  $(SRC)/about.c  $(SRC)/escape.c  $(SRC)/parser.c $(SRC)/pipe.c $(SRC)/tools.c  $(SRC)/envvar.c

clean-lin-rep:
	rm -vfr *~ build/bin/rep
clean-lin-unescape:
	rm -vfr *~ build/bin/unescape
clean-lin:clean-lin-unescape clean-lin-rep

clean-win-rep:
	rm -vfr *~ build/bin/rep.exe
	rm -vfr *~ build/bin/rep.pdp


z-lin-x64:clean-lin  z-unescape-lin-x64 z-rep-lin-x64
g-lin-x64:clean-lin  g-unescape g-rep

stable:g-lin-x64
ztable:z-lin-x64

install:
	install build/bin/rep /usr/bin/rep
	install build/bin/rep /usr/bin/unescape

list-variables:
	printf '%s\n' $(.VARIABLES)   

list-env:
	@$(foreach V, $(.VARIABLES), $(info $(V) = $($(V))))

