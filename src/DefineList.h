#ifndef __DEFINE_LIST_H__
#define __DEFINE_LIST_H__
#include "LinkedList.h"

typedef struct DefineElement_t{
	struct DefineElement_t *next;
	char *id;
	int value;
}DefineElement;

int comparePreprocessor(char *line);
void addDefineElement(LinkedList *defineList , void *defineElem); 
DefineElement *getDefineElement(char* line);
#endif //__DEFINE_LIST_H__