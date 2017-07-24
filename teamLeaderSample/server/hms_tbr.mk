# HMS Makefile for Tibero
# Linux 

TBLIBDIR = $(TB_HOME)/client/lib
TBLIB =-ltbxa -ltbertl -ltbcli -lm -lpthread

TARGET  = hms_tbr
APOBJ   = dumy.o

APPDIR	= $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib
TMAXLIBS= -lhms -lpthread 
TMAXINC = -I$(TMAXDIR)
CFLAGS  = 
LDFLAGS = 
SYSLIBS = 

all : $(TARGET)

$(TARGET): $(APOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TMAXINC) -L$(TMAXLIBD) $(TMAXLIBS) $(APOBJ) -L$(TBLIBDIR) $(TBLIB) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/.

$(APOBJ):
	$(CC) $(CFLAGS) $(LDFLAGS) -c dumy.c
#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)
