# HMS Makefile for Oracle
# Linux 

include $(ORACLE_HOME)/precomp/lib/env_precomp.mk
ORALIBDIR = $(LIBHOME)
ORALIB = $(PROLDLIBS) 

TARGET  = hms_ora
APOBJ   = dumy.o

APPDIR	= $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib
TMAXLIBS= -lhms_ora -lpthread

CFLAGS  = 
LDFLAGS = 
SYSLIBS = 

all : $(TARGET)

$(TARGET): $(APOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -L$(TMAXLIBD) $(TMAXLIBS) $(APOBJ) -L$(ORALIBDIR) $(ORALIB) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/.

$(APOBJ):
	$(CC) $(CFLAGS) -c dumy.c
#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)
