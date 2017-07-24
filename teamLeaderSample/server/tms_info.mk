# TMS Makefile for Informix 
# Linux

TARGET  = tms_info

APPDIR  = $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib
TMAXLIBS= -ltms -linfs

INFOLIBDIR = ${INFORMIXDIR}/lib
INFOELIBDIR = ${INFORMIXDIR}/esql
INFOLIBD = ${INFORMIXDIR}/lib/esql
INFOLIBS = `esql -libs` -lifxa

CFLAGS  = 
LDFLAGS = 
SYSLIBS = 

all : $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) -L$(TMAXLIBD) $(TMAXLIBS) -L$(INFOLIBD) -L$(INFOLIBDIR) -L$(INFOELIBDIR) $(INFOLIBS) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/.

#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)