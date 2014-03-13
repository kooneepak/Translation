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

void test_comparePreprocessor_should_return_1_if_is_define() {
	
	char *string = "#define MAX 10";

	int result = comparePreprocessor(string);
	
	TEST_ASSERT_EQUAL(1, result);
	

}

void test_comparePreprocessor_should_return_0_if_is_not_define() {
	
	char *string = "#def 10";

	int result = comparePreprocessor(string);
	
	TEST_ASSERT_EQUAL(0, result);
	
	string = "#define 10";

	result = comparePreprocessor(string);
	
	TEST_ASSERT_EQUAL(1, result);
	

}

void test_getDefineElement_should_return_a_define_element_id() {

	DefineElement *defineElement;
	
	defineElement = getDefineElement("#define MIN 10");
	TEST_ASSERT_NOT_NULL(defineElement);
	TEST_ASSERT_EQUAL('M', defineElement->id[0]);
	TEST_ASSERT_EQUAL('I', defineElement->id[1]);
	TEST_ASSERT_EQUAL('N', defineElement->id[2]);

}

void test_getDefineElement_should_return_a_define_element_value() {

	DefineElement *defineElement;
	
	defineElement = getDefineElement("#define MIN 10");
	TEST_ASSERT_NOT_NULL(defineElement);
	TEST_ASSERT_EQUAL(1, defineElement->value[0]);
	TEST_ASSERT_EQUAL(0, defineElement->value[1]);
	
}



