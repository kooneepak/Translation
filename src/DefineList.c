#include <stdio.h>
#include "DefineList.h"
#include "LinkedList.h"
#include "StringObject.h"
#include <malloc.h>
#include "Error.h"
#include "CException.h"
#include <string.h>

int isDefineAndStore(LinkedList *defineList, String *line) {
	int i = 0;
	String *subString;
	
	subString = getWordAndUpdate(line, " \t");
	if(isPreprocessor(subString->rawString[subString->startIndex])) {
		if(stringCompare("#define", subString)) {
			subString = getWordAndUpdate(line, "\0");
			storeDefineElement(defineList, subString);
		} else {
			Throw(INVALID_PREPROCESSOR);
		}
	} else {
		return 0;
	}
		free(subString);
}

int isPreprocessor(char hast) {
	if(hast == '#')
		return 1;
	else
		return 0;
}

void storeDefineElement(LinkedList *defineList, String *idAndValue) {
	
	String id, value;
	String *subString;
	int j;
	
	subString = getWordAndUpdate(idAndValue, " ");
	if(isdigit(subString->rawString[subString->startIndex]))
		Throw(INVALID_IDENTIFIER);
	
	for(j = 1; j < subString->length; j++) {
		if(isdigit(subString->rawString[subString->startIndex + j]) == 0 && isalpha(subString->rawString[subString->startIndex + j]) == 0)
			Throw(INVALID_IDENTIFIER);
		else
			id = *subString;
	}
	
	subString = getWordAndUpdate(idAndValue, "\0");
	value = *subString;
	
	DefineElement *defineElement = createDefineElement(&id, &value);
	
	List_addLast(defineList, defineElement);
}

DefineElement *createDefineElement(String *id, String *value) {
	DefineElement *defineElement = malloc(sizeof(DefineElement));
	
	defineElement->id = *id;
	defineElement->value = *value;
	
	return defineElement;
}


