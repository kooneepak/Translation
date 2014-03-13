#include <stdio.h>
#include "DefineList.h"
#include "LinkedList.h"
#include <malloc.h>
#include <string.h>

void addDefineElement(LinkedList *defineList , void *defineElem){
	List_addLast(defineList, defineElem);
}

int comparePreprocessor(char *line) {
	int i =0;
	char *preprocessor = "#define";
	DefineElement defineElement;
	
	while(preprocessor[i] != 0) {
		if(line[i] != preprocessor[i])
			return 0;
		i++;
	}return 1;
}

DefineElement *getDefineElement(char* line) {
	int i =0,j=0;
	char *preprocessor = "#define";
	DefineElement *defineElement=malloc(sizeof(DefineElement));
	char *tempString=malloc(strlen(line));
	int tempValue=0;

	
	while(preprocessor[i] != 0) {
		if(line[i] != preprocessor[i])
			printf("Error\n");
		i++;
	}
	i++;
	
	if(comparePreprocessor(line) == 1) {
		//ID
		while(line[i] != ' ') {
			if((line[i] >= 'A' && line[i] <= 'Z'))
			{
				tempString[j] = line[i];
				i++;
				j++;
			}
			else
				printf("Error\n");
				
		}
		tempString[i]=0;
		defineElement->id = tempString;	
		
		//Value
		while(line[i] != ' '){
			if((line[i] >= '0') && (line[i] <='9'))
			{
				tempValue =tempValue*10+(line[i]-'0');
				i++;
			
		}
		else
			printf("Error\n");
		
	}
		
		defineElement->value = tempValue;	
		
	return defineElement;
		
	
	}
}