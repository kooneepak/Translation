#include "unity.h"
#include <stdio.h>
#include "DefineList.h"
#include "mock_LinkedList.h"
#include "StringObject.h"
#include <malloc.h>
#include "Error.h"
#include "CException.h"
#include <string.h>

Error e;

void setUp(){}
void tearDown(){}

void test_isPreprocessor_should_return_1_if_is_hast() {
	int result = isPreprocessor('#');
	
	TEST_ASSERT_EQUAL(1, result);
}

void test_isPreprocessor_should_return_0_if_not_hast() {
	int result = isPreprocessor('@');
	
	TEST_ASSERT_EQUAL(0, result);
}

void test_createDefineElement_should_create_properly() {
	String id = {.rawString = "#define MAX 10", .startIndex = 8, .length = 3};
	String value = {.rawString = "#define MAX 10", .startIndex = 12, .length = 2};	
	DefineElement *defineElement;
	
	defineElement = createDefineElement(&id, &value);

	TEST_ASSERT_EQUAL(8, defineElement->id.startIndex);
	TEST_ASSERT_EQUAL(3, defineElement->id.length);
	TEST_ASSERT_EQUAL(12, defineElement->value.startIndex);
	TEST_ASSERT_EQUAL(2, defineElement->value.length);

}


void xtest_storeDefineElement_should_add_define_element_to_linked_list() { // cannot be mocked
	LinkedList defineList;
	String idAndValue = {.rawString = "#define MAX 10", .startIndex = 8, .length = 6};
	String id = {.rawString = "#define MAX 10", .startIndex = 8, .length = 3};
	String value = {.rawString = "#define MAX 10", .startIndex = 12, .length = 2};
	DefineElement defineElement = {.id = id, .value = value};
	
	List_addLast_Expect(&defineList, &defineElement);
	
	Try {
		storeDefineElement(&defineList, &idAndValue);
	} Catch(e) {
		TEST_FAIL_MESSAGE("Should not throw error");
	}

}

/*
void test_isDefineAndStore_should_return_0_if_not_start_with_hast() {
	LinkedList defineList;
	String defineLine = {.rawString = "#define MAX 10", .startIndex = 0, .length = 7};
	
	addList
	
	Try {
		int result = isDefineAndStore('@');
	} Catch(e) {
		
	}
	TEST_ASSERT_EQUAL(0, result);
}
*/

/*



void test_addDefineElement(){
	LinkedList defineList;
	
	DefineElement defineElement;
	defineElement.id = "MAX";
	defineElement.value = "2";
	
	List_addLast_Expect(&defineList,&defineElement);
	addDefineElement(&defineList, &defineElement);
}

void test_comparePreprocessor_should_return_1_if_is_define() {
	
	char *string = "#define MAX 10";

	int result = comparePreprocessor(string);
	
	TEST_ASSERT_EQUAL(1, result);
	

}

void test_comparePreprocessor_should_return_0_if_is_not_define_else_return_1() {
	
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
	
	defineElement = getDefineElement("#define MAX 10");							  
	TEST_ASSERT_NOT_NULL(defineElement);
	TEST_ASSERT_EQUAL(10, defineElement->value);

}

void test_add_DefineElement_into_linkedList(){


	LinkedList defineList = {};
	
	DefineElement defineElement;
	defineElement = *getDefineElement("#define MAX 10");
	
	List_addLast_Expect(&defineList,&defineElement);
	addDefineElement(&defineList, &defineElement);


}


*/