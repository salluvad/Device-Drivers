{\rtf1\ansi\ansicpg1252\cocoartf2758
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\csgray\c0;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs36 \cf2 \CocoaLigature0 /////////////////////////////////////////////////////////////////////////////\
// Name:         simdrv.c\
// Description:  Simple device driver loadable kernel module\
// Ref: https://lwn.net/Kernel/LDD3/\
/////////////////////////////////////////////////////////////////////////////\
\
#include <linux/init.h>\
#include <linux/module.h>\
\
MODULE_LICENSE("GPL");\
\
static int __init simdrv_init(void)\{\
  printk(KERN_INFO "SIMDRV: init.");\
  return 0;\
\}\
\
static void __exit simdrv_exit(void)\{\
  printk(KERN_INFO "SIMDRV: exit.");\
\}\
\
module_init(simdrv_init);\
module_exit(simdrv_exit);}