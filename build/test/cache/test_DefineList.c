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



void test_comparePreprocessor_should_return_1_if_is_define() {



 char *string = "#define MAX 10";



 int result = comparePreprocessor(string);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);





}
