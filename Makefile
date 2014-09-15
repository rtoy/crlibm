OBJS = jakes.o getrealtime.o
CFLAGS = -O -g $(DEBUG)

all : jakes jakes.crlibm jakes.fdlibm

jakes : jakes.o jakes-model.o getrealtime.o
	$(CC) -o $@ $^ -lm

jakes.crlibm : jakes.o jakes-model.crlibm.o getrealtime.o
	$(CC) -o $@ $^ -Lcrlibm -lcrlibm -lm

jakes.fdlibm : jakes.o jakes-model.fdlibm.o getrealtime.o
	$(CC) -o $@ $^ -Lfdlibm -lfdlibm -lm

jakes-model.crlibm.o : jakes-model.c
	$(CC) -c $(CFLAGS) -Icrlibm -DUSE_CRLIBM -o $@ $^

jakes-model.fdlibm.o : jakes-model.c
	$(CC) -c $(CFLAGS) -Ifdlibm -DUSE_FDLIBM -o $@ $^

clean :
	$(RM) *.o 
	$(RM) jakes jakes.crlibm jakes.fdlibm
