#include <stdio.h>
#include <stdlib.h>
#include "Translation.h"
#include <malloc.h>




char *readChar(){

	FILE *myFile;
	myFile = fopen("message.txt", "r+");
	char *string = malloc(sizeof(char)*6);

	string[0] = fgetc(myFile);	
	string[1] = fgetc(myFile);
	string[2] = fgetc(myFile);
	string[3] = fgetc(myFile);
	string[4] = fgetc(myFile);
	string[5] = 0;

	fclose(myFile);
	return string;
} 
	
char *readLine(){

	FILE *myFile;
	myFile = fopen("message.txt", "r+");
	char sizebuff[128];
	char *ptr2Str = malloc(sizeof(char)*6);
	
	
	ptr2Str = fgets(sizebuff , 6 , myFile );
	if(ptr2Str != NULL)
	return ptr2Str;
	
	


}

	