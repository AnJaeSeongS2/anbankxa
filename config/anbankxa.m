################################################################################
#                                                                              #
#                    Openframe TMAX Configuration Sample                       #
#                    ===================================                       #
#                                                                              #
#      Copyright (c) 2006, 2007 Tmax Soft Co., Ltd. All rights reserved.       #
#                                                                              #
################################################################################
# At least following items should be configured to your system.                #
# - @#HOSTNAME#@ should be replaced with actual hostname.                      #
# - @#TMAXDIR#@ should be replaced with actual tmax directory.                 #
################################################################################
*DOMAIN
oframe
    SHMKEY      = 98941,
    MAXUSER     = 256,
    MINCLH      = 1,
    MAXCLH      = 1,
    BLOCKTIME   = 100,
    MAXCPC      = 256,
    MAXSPR      = 512,
    MAXSVR      = 128,
    MAXSVC      = 512,
    DOMAINID    = 4,
    IPCPERM     = 0777,
    MAXSACALL   = 1024,
    MAXCACALL   = 1024
*NODE
DEFAULT:
    HOSTNAME = "ahriman",
    DOMAINNAME = "oframe"
NODE1
    TMAXHOME = "/home/anu/o7/tmax",
    TMAXDIR = "/home/anu/o7/tmax",
    APPDIR  = "/home/anu/o7/tmax/appbin",
    TLOGDIR = "/home/anu/o7/tmax/log/tlog",
    ULOGDIR = "/home/anu/o7/tmax/log/ulog",
    SLOGDIR = "/home/anu/o7/tmax/log/slog",
    CLHOPT  = " -o /home/anu/o7/tmax/log/clh.log -e /home/anu/o7/tmax/log/clh.err",
    TPORTNO = 8940, SHMKEY = 98941, RACPORT = 9559

*SVRGROUP
svg_domain
    NODENAME = "NODE1"
svg_node1
    NODENAME = "NODE1"
svg_anbank1
   NODENAME = "NODE1",
   DBNAME = "TIBERO",
   OPENINFO="TIBERO_XA:user=anbank1,pwd=tmax,sestm=60,db=tb_start,conn_id=anbank1",
   TMSNAME = "tms_tbr",
   SVGTYPE = "STMAX",
   RMID = 1
svg_anbank2
   NODENAME = "NODE1",
   DBNAME = "TIBERO",
   OPENINFO="TIBERO_XA:user=anbank2,pwd=tmax,sestm=60,db=tb_start,conn_id=anbank2",
   TMSNAME = "tms_tbr",
   SVGTYPE = "STMAX",
   RMID = 2
svg_anbankxa
   NODENAME = "NODE1",
   SVGTYPE = MTMAX,
   SVGLIST = "svg_anbank1, svg_anbank2"
   

   
################################################################################
# Sample Tmax Configuration for OpenFrame Base.                                #
#                                                                              #
# (OpenFrame Base product developer)                                           #
# - This file is controlled under CVS.                                         #
#   For local changes, edit Tmax config file in $TMAXDIR/config.               #
# - When you change Base servers or services,                                  #
#   you should change this file also in according to your changes.             #
################################################################################
*SERVER
################################################################################
# OpenFrame Base Servers                                                       #
# - TACF Server                 (UCS)                                          #
# - Lock Server                 (UCS)                                          #
# - Lock Worker                                                                #
# - Dataset Management Server   (UCS)                                          #
# - Dataset Edit Server         (CONV)                                         #
# - Console Server              (UCS)                                          #
# - User Interface Server                                                      #
# - System Management Logger
################################################################################
anbankxasvr       SVGNAME = svg_anbankxa,
       CLOPT="-o $(SVR)$(DATE).out -e $(SVR)$(DATE).err"

*SERVICE
#########################################
#  made by anu@ahriman
######################################

ATMSERVICE SVRNAME = anbankxasvr,
		   SVCTIME = 90
CREATE SVRNAME = anbankxasvr,
        SVCTIME = 90
DEPOSIT SVRNAME = anbankxasvr,
		SVCTIME = 90
WITHDROW SVRNAME = anbankxasvr,
		 SVCTIME = 90
SENDMONEY SVRNAME = anbankxasvr,
		  SVCTIME = 90

