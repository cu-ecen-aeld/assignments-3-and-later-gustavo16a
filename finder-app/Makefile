CC = gcc

ifdef CROSS_COMPILE
	DD := tres
	ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
		CC := $(CROSS_COMPILE)$(CC)
	endif
endif

default:
	$(CC) -g -Wall -c -o writer.o writer.c
	$(CC) -g -Wall -I/ writer.o -o writer
clean:
	rm -rf *.o writer