OBJS = jakes.o getrealtime.o
CFLAGS = -O -g $(DEBUG)

all : jakes jakes.crlibm jakes.fdlibm

jakes : jakes.o jakes-model.o getrealtime.o sincos.o
	$(CC) -o $@ $^ -lm -lrt

jakes.crlibm : jakes.o jakes-model.crlibm.o getrealtime.o sincos.crlibm.o
	$(CC) -o $@ $^ -Lcrlibm -lcrlibm -lm -lrt

jakes.fdlibm : jakes.o jakes-model.fdlibm.o getrealtime.o sincos.fdlibm.o
	$(CC) -o $@ $^ -Lfdlibm -lfdlibm -lrt

jakes-model.crlibm.o : jakes-model.c
	$(CC) -c $(CFLAGS) -Icrlibm -DUSE_CRLIBM -o $@ $^

jakes-model.fdlibm.o : jakes-model.c
	$(CC) -c $(CFLAGS) -Ifdlibm -DUSE_FDLIBM -o $@ $^

sincos.o : sincos.c
	$(CC) -o $@ -c $(CFLAGS) $^

sincos.crlibm.o : sincos.c
	$(CC) -o $@ -c $(CFLAGS) -Icrlibm -DUSE_CRLIBM  $^

sincos.fdlibm.o : sincos.c
	$(CC) -o $@ -c $(CFLAGS) -Ifdlibm -DUSE_FDLIBM $^

clean :
	$(RM) *.o 
	$(RM) jakes jakes.crlibm jakes.fdlibm
