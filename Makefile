CFLAGS= -Wall -fpic -coverage -lm -std=c99
testme: testme.o testme.c
	gcc  -o testme testme.o  $(CFLAGS)

testme.o: testme.c
	gcc -c testme.c $(CFLAGS)

clean:
	rm *.o ouput
    
