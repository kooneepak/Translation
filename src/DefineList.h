#ifndef __DEFINE_LIST_H__
#define __DEFINE_LIST_H__
#include "LinkedList.h"

typedef struct DefineElement_t{
	struct DefineElement_t *next;
	char *id;
	int value;
}DefineElement;

void addDefineElement(LinkedList *defineList , void *defineElem); 

#endif //__DEFINE_LIST_H__