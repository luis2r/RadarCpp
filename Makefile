#PJ = i7565H1H2
SHELL = /bin/sh

CROSS_COMPILE   =
LIBS = lib/libI7565H1H2.a -L lib -li7k
TARGET = dist/Debug/GNU-Linux-x86/radarcpp


CPP             = $(CROSS_COMPILE)g++


MACRO = -DI7565H1H2
CFLAGS =  $(MACRO) -I. -I include
LDFLAGS =
AM_LDFLAGS = -lpthread

all: $(TARGET)

$(TARGET): i7565H1H2.o
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $@ i7565H1H2.o $(LIBS) $(AM_LDFLAGS)
	rm -f i7565H1H2.o


clean:
	rm -f *.o *~ *.tmp *.bak i7565H1H2_arm i7565H1H2 \#* .\#*
