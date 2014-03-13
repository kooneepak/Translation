#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct {
	void *head;
	void *tail;
}LinkedList;

void List_addLast(LinkedList *list, void *element);

#endif //__LINKED_LIST_H__