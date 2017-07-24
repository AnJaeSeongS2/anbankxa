# TMS Makefile for DB2
# Linux

TARGET  = tms_db2
APOBJ   = dumy.o

APPDIR  = $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib
TMAXLIBS= -ltms -ldb2s

DB2PATH = $(DB2DIR)
DB2LIBDIR= $(DB2PATH)/lib
DB2LIB  = -ldb2

CFLAGS  = 
LDFLAGS = 
SYSLIBS = 

all: $(TARGET)

$(TARGET): $(APOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -L$(TMAXLIBD) $(TMAXLIBS) $(APOBJ) -L$(DB2LIBDIR) $(DB2LIB) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/.

$(APOBJ):
	$(CC) $(CFLAGS) -c dumy.c
#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)