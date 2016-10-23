#**************************************************
# Makefile for OIT Nameserver lab
# CST 415 Lab 1
#
# Author: Philip Howard
# Email:  phil.howard@oit.edu
# Date:   Sept 22, 2016
#
COPTS = -g -O0 -Wall

all: fileclient filesever

clean:
	rm -f fileclient
	rm -f fileserver
	rm -f *.o

.c.o:
	gcc $(COPTS) -c $? -o $@

fileclient: fileclient.c md5sum.h readline.h getport.h
	gcc $(COPTS) fileclient.c -o fileclient

fileserver: fileserver.c md5sum.h getport.h readline.h
	gcc $(COPTS) fileclient.c -o fileclient
