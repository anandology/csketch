
SOURCES=sketch.c
HEADERS=sketch.h
OBJECTS=sketch.o

default: build

build: libsketch.a

libsketch.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)

sketch.o: sketch.c $(HEADERS)
	gcc -c sketch.c -o sketch.o

clean:
	-rm -f $(OBJECTS) libsketch.a   
