#include <stdio.h>
#include "DefineList.h"
#include "LinkedList.h"

void addDefineElement(LinkedList *defineList , void *defineElem){
	List_addLast(defineList, defineElem);
}

int comparePreprocessor(char *line){

	int i=0;
	char *preprocessor = "#define";
	DefineElement defineElement;
	
	while(preprocessor[i] != 0) {
		if(line[i] != preprocessor[i])
			return 0;
		i++;
	}
	
	return 1;
	

}
