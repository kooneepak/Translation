#include "unity.h"
#include <stdio.h>
#include "DefineList.h"
#include "mock_LinkedList.h"


void setUp(){}
void tearDown(){}

void test_addDefineElement(){
	LinkedList defineList = {};
	
	DefineElement defineElement;
	defineElement.id = "MAX";
	defineElement.value = 2;
	
	List_addLast_Expect(&defineList,&defineElement);
	addDefineElement(&defineList, &defineElement);
}


