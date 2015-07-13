CC=g++
ARCH=


INCLUDE_FLAGS=-I/usr/local/include -I/usr/include
CFLAGS=-c -Wall -Wno-write-strings $(INCLUDE_FLAGS)
LDFLAGS= -L$(STAGING_DIR)/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lzbar

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=wcs

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS) Makefile
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
