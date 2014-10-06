#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkInput();
char * appendString(char * dest, char * src);
void removeComment(FILE * oldFile, char * originalFileName);

int main(int argc, char * argv[]){
	
	FILE * fp;
	
	if(argc < 2){
		puts("Invalid number of arguments.");
		puts("use: removeCComments [name of c file]");
		return 1;
	}

	fp = fopen(argv[1], "r");
	
	removeComment(fp, argv[1]);
}


/*
 *Allows a user to append one string onto the end of another. If function
 *fails just return NULL.
 */

char * appendString(char * dest, char * src){
	char * newString; 
	int newStringLength = strlen(dest) + strlen(src) + 1;
	
	//allocate enough memory for our new string on the heap
	if((newString = malloc(newStringLength))==NULL){
		fprintf(stderr, "malloc failed\n");
		return NULL;
	}
	
	//make sure first element of new string is null terminated
	newString[0] = '\x00';
	
	strcat(newString, dest);
	strcat(newString, src);

	return newString;
	
}


/*
 *Meat of the program. Returns 0 upon terminating successfully. Saves striped
 *file as "[fileName].strip"
 */

void removeComment(FILE * oldFile, char * originalFileName){
	char * foo = appendString(originalFileName, ".strip");
	puts(foo);
}



