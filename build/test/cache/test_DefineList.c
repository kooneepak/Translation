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



void test_comparePreprocessor_should_return_0_if_is_not_define_else_return_1() {



 char *string = "#def 10";



 int result = comparePreprocessor(string);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);



 string = "#define 10";



 result = comparePreprocessor(string);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);





}





void test_getDefineElement_should_return_a_define_element_id() {



 DefineElement *defineElement;



 defineElement = getDefineElement("#define MIN 10");

 if ((((defineElement)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};

 UnityAssertEqualNumber((_U_SINT)(('M')), (_U_SINT)((defineElement->id[0])), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('I')), (_U_SINT)((defineElement->id[1])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('N')), (_U_SINT)((defineElement->id[2])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);



}





void test_getDefineElement_should_return_a_define_element_value() {



 DefineElement *defineElement;



 defineElement = getDefineElement("#define MAX 10");

 if ((((defineElement)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)68);;};

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((defineElement->value)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);



}



void test_add_DefineElement_into_linkedList(){





 LinkedList defineList = {};



 DefineElement defineElement;

 defineElement = *getDefineElement("#define MAX 10");



 List_addLast_CMockExpect(81, &defineList, &defineElement);

 addDefineElement(&defineList, &defineElement);













}
