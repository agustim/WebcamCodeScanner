CC=g++
ARCH=


INCLUDE_FLAGS=-I/usr/local/include
CFLAGS=-c -Wall -Wno-write-strings $(INCLUDE_FLAGS) 
LDFLAGS= -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_videoio -lzbar

SOURCES = logger.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=wcs

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS) Makefile
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
