#include <stdio.h>
#include <stdlib.h>
#include "Translation.h"
#include <malloc.h>
#include <string.h>



char *readChar(){

	FILE *myFile;
	myFile = fopen("message.txt", "r");
	char *string = malloc(sizeof(char)*20);
	
//get one character from the message.txt file
	string[0] = fgetc(myFile);	//m
	string[1] = fgetc(myFile);  //o
	string[2] = fgetc(myFile);	//v
	string[3] = fgetc(myFile);	//f
	string[4] = fgetc(myFile);	//f
	string[5] = 0;

	fclose(myFile);
	return string;
} 
	
char *readLine(FILE *myFile){

	
	char *line = malloc(sizeof(char)*128);
	char c;
	int i = 0;
	
	while(!feof(myFile) && (c = fgetc(myFile)) != '\n' ) {
		line[i] = c;
		i++;
	}
	
	line[i] = 0;
	
	
	return line;

	
	

}











	