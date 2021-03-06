# Server makefile

TARGET	= $(COMP_TARGET)
APOBJS	= $(TARGET).o
NSDLOBJ = $(TMAXDIR)/lib/sdl.o

LIBS	= -lsvr -lnodb
OBJS    = $(APOBJS) $(SVCTOBJ)
SVCTOBJ = $(TARGET)_svctab.o

CFLAGS  = -O -I$(TMAXDIR)

APPDIR  = $(TMAXDIR)/appbin
SVCTDIR = $(TMAXDIR)/svct
LIBDIR  = $(TMAXDIR)/lib
 
#
.SUFFIXES : .c

.c.o: 
	$(CC) $(CFLAGS) -c $<

#
# server compile
#

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBDIR) -o $(TARGET) $(OBJS) $(LIBS) $(NSDLOBJ)
	mv $(TARGET) $(APPDIR)/.
	rm -f $(OBJS)

$(APOBJS): $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

$(SVCTOBJ): 
	cp -f $(SVCTDIR)/$(TARGET)_svctab.c . 
	touch ./$(TARGET)_svctab.c 
	$(CC) $(CFLAGS) -c ./$(TARGET)_svctab.c 

#
clean:
	-rm -f *.o core $(APPDIR)/$(TARGET) 
