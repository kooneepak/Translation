#include "unity.h"
#include "mock_LinkedList.h"
#include "DefineList.h"






void setUp(){}

void tearDown(){}



void test_addDefineElement(){

 LinkedList defineList = {};



 DefineElement defineElement;

 defineElement.id = "MAX";

 defineElement.value = 2;



 List_addLast_CMockExpect(17, &defineList, &defineElement);

 addDefineElement(&defineList, &defineElement);

}
