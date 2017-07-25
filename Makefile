# server tbpc makefile

SOURCEDIR = $(TMAXDIR)/workspace/bank20170720
TBINC = $(TB_HOME)/client/include
TBLIBDIR = $(TB_HOME)/client/lib
TBLIB = -lsvr -ltbs -ltbertl -ltbcli -ltbxa

TARGETSVR = anbankxasvr
TARGETCLI = anbankxacli
TARGET = anbankxa

APOBJS = $(TARGETSVR).o
SDLOBJ = $(SOURCEDIR)/sdl/$(TARGET)_sdl.o

SVCTOBJ = $(TARGETSVR)_svctab.o
OBJS	= $(APOBJS) $(SVCTOBJ)

LDFLAGS =
CFLAGS = -O -I$(TMAXDIR)

TMAXLIBDIR = $(TMAXDIR)/lib
APPDIR = $(TMAXDIR)/appbin
SVCTDIR = $(TMAXDIR)/svct
#
.SUFFIXES : .c

.c.o:
	$(CC) $(CFLAGS) $(LDFLAGS) -c $<

#
#
# server compile
all: $(TARGET)

#
clean:
	rm -f $(TMAXDIR)/appbin/$(TARGETSVR)
	rm -f $(SOURCEDIR)/server/$(TARGETSVR).c
	rm -f $(SOURCEDIR)/server/$(TARGETSVR).o
	rm -f $(SOURCEDIR)/server/$(TARGETSVR)
	rm -f $(SOURCEDIR)/client/$(TARGETCLI).o
	rm -f $(SOURCEDIR)/client/$(TARGETCLI)
	rm -f $(SOURCEDIR)/sdl/$(TARGET)_sdl.c
	rm -f $(SOURCEDIR)/sdl/$(TARGET)_sdl.h
	rm -f $(SOURCEDIR)/sdl/$(TARGET)_sdl.o
	rm -f $(SOURCEDIR)/sdl/$(TARGET).sdl
	rm -f $(TMAXDIR)/svct/$(TARGETSVR)_svctab.c
	rm -f $(TMAXDIR)/svct/$(TARGETSVR)_svctab.o
	rm -f $(SOURCEDIR)/$(TARGETCLI)

$(TARGET): $(TARGET).m $(TARGET).s $(TARGETSVR) $(TARGETCLI)
	cd $(SOURCEDIR) ; \
	ln -s $(SOURCEDIR)/client/$(TARGETCLI) $(SOURCEDIR)/
$(TARGET).m:
	cd $(SOURCEDIR)/config ; \
	cfl -i $(SOURCEDIR)/config/$(TARGET).m
	gst
	cd $(SVCTDIR) ; \
	cc -c -I$(TMAXDIR) $(TARGETSVR)_svctab.c

$(TARGET).s:
	cd $(SOURCEDIR)/sdl ; \
	sdlc -i $(TARGET).s 
	cd $(SOURCEDIR)/sdl ; \
	cc -c -I$(TMAXDIR) $(TARGET)_sdl.c 
	cd $(SOURCEDIR)/sdl ; \
	sdlc -c -i $(TARGET).s -o $(TARGET).sdl


$(TARGETCLI): 
	cd $(SOURCEDIR)/client ; \
	cc -c -I$(TMAXDIR) $(TARGETCLI).c
	cd $(SOURCEDIR)/client ; \
	cc -O -I$(TMAXDIR) -L$(TMAXLIBDIR) -o $(TARGETCLI) $(TARGETCLI).o -lcli -lnsl

$(TARGETSVR): $(TARGETSVR).tbc
	cd $(SOURCEDIR)/server ; \
	cc -c -I$(TBINC) -I$(TMAXDIR) $(TARGETSVR).c -lsvr -ltbs
	cd $(SOURCEDIR)/server ; \
	cc -o $(TARGETSVR) $(TARGETSVR).o $(SDLOBJ) $(SVCTDIR)/$(SVCTOBJ) -I$(TBINC) -I$(TMAXDIR) -L$(TBLIBDIR) -L$(TMAXLIBDIR) $(TBLIB)
	cd $(SOURCEDIR)/server ; \
	cp -f $(TARGETSVR) $(TMAXDIR)/appbin/$(TARGETSVR)


$(TARGETSVR).tbc:
	cd $(SOURCEDIR)/server ; \
	tbpc INCLUDE=$(TMAXDIR) INCLUDE=$(TBINC) $(TARGETSVR).tbc









