OBJS = jakes.o getrealtime.o
CFLAGS = -O -g $(DEBUG)

all : jakes jakes.crlibm jakes.fdlibm

jakes : jakes.o getrealtime.o
	$(CC) -o $@ $^ -lm

jakes.crlibm : jakes.crlibm.o getrealtime.o
	$(CC) -o $@ $^ -Lcrlibm -lcrlibm -lm

jakes.fdlibm : jakes.fdlibm.o getrealtime.o
	$(CC) -o $@ $^ -Lfdlibm -lfdlibm -lm

jakes.crlibm.o : jakes.c
	$(CC) -c $(CFLAGS) -Icrlibm -DUSE_CRLIBM -o $@ $^

jakes.fdlibm.o : jakes.c
	$(CC) -c $(CFLAGS) -Ifdlibm -DUSE_FDLIBM -o $@ $^

clean :
	$(RM) *.o 
	$(RM) jakes jakes.crlibm jakes.fdlibm
