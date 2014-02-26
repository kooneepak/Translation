#include <stdio.h>
#include <stdlib.h>
#include "Translation.h"
#include <malloc.h>

char *readFile(){

	char tempChar;
	char *filename = "message.txt";
	FILE *myFile;
	myFile = fopen(filename, "r+");
	
	int i=0;
	char *array=malloc(sizeof(char));
	
	do {
    array[i] = fgetc(myFile);
	tempChar=array[i];
	i++;
	}while(tempChar!=EOF);
	
	fclose(myFile);
	return array;
	
	

} 



	