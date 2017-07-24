# Server tbpc makefile
TBINC = $(TB_HOME)/client/include
TBLIBDIR = $(TB_HOME)/client/lib
TBLIB = -ltbxa -ltbertl -ltbcli -lm -lpthread
TARGET = $(COMP_TARGET)
	APOBJS = $(TARGET).o
	NSDLOBJ = $(TMAXDIR)/lib64/sdl.o
#Tibero
	LIBS = -lsvr -ltbs
	OBJS = $(APOBJS) $(SVCTOBJ)
	
SVCTOBJ = $(TARGET)_svctab.o
CFLAGS = -O -Ae -w +DSblended +DD64 -D_HP -I$(TMAXDIR)
	APPDIR = $(TMAXDIR)/appbin
	SVCTDIR = $(TMAXDIR)/svct
	TMAXLIBDIR = $(TMAXDIR)/lib64
#
	.SUFFIXES : .c
	.c.o:
	$(CC) $(CFLAGS) -c $<
#
# server compile
#
	all: $(TARGET)
	$(TARGET): $(OBJS)
				 $(CC) $(CFLAGS) -L$(TMAXLIBDIR) -o $(TARGET) -L$(TBLIBDIR) $(TBLIB) $(OBJS)
						  $(LIBS) $(NSDLOBJ)
								mv $(TARGET) $(APPDIR)/.
									  rm -f $(OBJS)
										 $(APOBJS): $(TARGET).tbc
													  tbpc iname=$(TARGET) include=$(TMAXDIR)
															   $(CC) $(CFLAGS) -L$(TBLIBDIR) -I$(TBINC) $(TBLIB) -c $(TARGET).c
																	 $(SVCTOBJ):
																		 cp -f $(SVCTDIR)/$(TARGET)_svctab.c .
																		 touch ./$(TARGET)_svctab.c
																		 $(CC) $(CFLAGS) -c ./$(TARGET)_svctab.c
#
																		 clean:
																		 -rm -f *.o core $(APPDIR)/$(TARGET) $(TARGET).lis
