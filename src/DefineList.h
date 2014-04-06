#ifndef __DEFINE_LIST_H__
#define __DEFINE_LIST_H__

#include "LinkedList.h"
#include "StringObject.h"

typedef struct DefineElement_t{
	struct DefineElement_t *next;
	String id;
	String value;
}DefineElement;

DefineElement *createDefineElement(String *id, String *value);
int isPreprocessor(char hast);
int  isDefineAndStore(LinkedList *defineList, String *line);
void storeDefineElement(LinkedList *defineList, String *idAndValue);

#endif //__DEFINE_LIST_H__