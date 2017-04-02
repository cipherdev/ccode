#
#       Makefile
#
#       (C) 2017-2020 HuyLe <anhhuy@live.com>
#
#       15-March-2017 <anhhuy@live.com>
#
CC      = gcc
CFLAGS  = -W -Wall -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual \
	  -Wcast-align -Wwrite-strings -Wmissing-prototypes -Winline -Wundef \
	  -Wunused-parameter

# Let lseek and mmap support 64-bit wide offsets
CFLAGS += -D_FILE_OFFSET_BITS=64

#CFLAGS += -DBIGENDIAN
#CFLAGS += -DALIGNMENT_WORKAROUND

# When debugging, disable -O2 and enable -g.
CFLAGS += -O2
#CFLAGS += -g

# Pass linker flags here
LDFLAGS =

DESTDIR =
prefix  = /usr/local
sbindir = $(prefix)/sbin

INSTALL         := install
INSTALL_DIR     := $(INSTALL) -m 755 -d
INSTALL_PROGRAM := $(INSTALL) -m 755
RM              := rm -f

# BSD make provides $MACHINE, but GNU make doesn't
MACHINE ?= $(shell uname -m 2>/dev/null)

# These programs are only useful on x86
PROGRAMS-i386 := ccode operator funcponter struct
PROGRAMS-i486 := $(PROGRAMS-i386)
PROGRAMS-i586 := $(PROGRAMS-i386)
PROGRAMS-i686 := $(PROGRAMS-i386)
PROGRAMS-x86_64 := ccode operator funcponter struct
PROGRAMS-amd64 := $(PROGRAMS-x86_64)

PROGRAMS := ccode $(PROGRAMS-$(MACHINE))

all : $(PROGRAMS)

#
# Programs
#
ccode : ccode.o hello.o
	$(CC) $(LDFLAGS) ccode.o hello.o -o $@

operator : operator.o
	$(CC) $(LDFLAGS) operator.o -o $@
	$(RM) *.o

funcponter : funcponter.o
	$(CC) $(LDFLAGS) funcponter.o -o $@
	$(RM) *.o

struct : struct.o
	$(CC) $(LDFLAGS) struct.o -o $@
	$(RM) *.o
#
# Objects
#
ccode.o : ccode.c hello.h 
	$(CC) $(CFLAGS) -c $< -o $@

operator.o : operator.c
	$(CC) $(CFLAGS) -c $< -o $@

funcponter.o : funcponter.c define.h
	$(CC) $(CFLAGS) -c $< -o $@

hello.o : hello.c hello.h
	$(CC) $(CFLAGS) -c $< -o $@

struct.o : struct.c define.h
	$(CC) $(CFLAGS) -c $< -o $@

#
# Commands
#
strip : $(PROGRAMS)
	strip $(PROGRAMS)

install : install-bin

uninstall : uninstall-bin

install-bin : $(PROGRAMS)
	$(INSTALL_DIR) $(DESTDIR)$(sbindir)
	for program in $(PROGRAMS) ; do \
	$(INSTALL_PROGRAM) $$program $(DESTDIR)$(sbindir) ; done

uninstall-bin :
	for program in $(PROGRAMS) ; do \
	$(RM) $(DESTDIR)$(sbindir)/$$program ; done

clean :
	$(RM) *.o $(PROGRAMS)
