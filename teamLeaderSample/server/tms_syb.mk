# TMS Makefile for Sybase
# Linux

TARGET  = tms_syb
APOBJ   = dumy.o

APPDIR  = $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib
TMAXLIBS= -ltms -lsybs

SYBINCD = $(SYBASE)/$(SYBASE_OCS)/include
SYBLIBD = $(SYBASE)/$(SYBASE_OCS)/lib
SYBLIBS = -lxadtm `sybopts.sh ct cs comlibs` `sybopts.sh syslibs`
SYBESQL = sybesql.o

CFLAGS  = 
LDFLAGS = 
SYSLIBS = 

all : $(TARGET)

$(TARGET): $(APOBJ) $(SYBESQL)
	`sybopts.sh compile` $(CFLAGS) $(LDFLAGS) -o $(TARGET) -L$(TMAXLIBD) $(TMAXLIBS) $(APOBJ) -L$(SYBLIBD) $(SYBLIBS) $(SYBESQL) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/.
	rm $(SYBESQL)

$(APOBJ):
	$(CC) $(CFLAGS) -c dumy.c

$(SYBESQL) :
	`sybopts.sh compile` $(CFLAGS) -I. -I$(SYBINCD) -L$(SYBLIBD) -c `sybopts.sh ocsbase`/include/sybesql.c -o $(@F)


#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)