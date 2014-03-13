#include <stdio.h>
#include "DefineList.h"
#include "LinkedList.h"

void addDefineElement(LinkedList *defineList , void *defineElem){
	List_addLast(defineList, defineElem);
}
