all: removeCComments.c
	gcc removeCComments.c -std=c99 -o removeCComments
