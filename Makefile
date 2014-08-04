#PJ = i7565H1H2
SHELL = /bin/sh

LIBS =  lib/libI7565H1H2_64.a lib/libi7k_64.a
TARGET = dist/Debug/GNU-Linux-x86/radarcpp

CPP             = $(CROSS_COMPILE)g++

AM_LDFLAGS = -lpthread

all: $(TARGET)

$(TARGET): i7565H1H2.o
	$(CPP) $(LDFLAGS) -o $@ i7565H1H2.o $(LIBS) $(AM_LDFLAGS)
	rm -f i7565H1H2.o
clean:
	rm -f *.o *~ *.tmp *.bak i7565H1H2_arm i7565H1H2 \#* .\#*
