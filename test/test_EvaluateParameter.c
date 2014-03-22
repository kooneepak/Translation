#include "unity.h"
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "mock_Token.h"
#include <malloc.h>

Opcode opcodeTable[] =  {{"clrwdt",evaluate0Parameter}};
						 // {"movlw",evaluate1Parameter},
						 // {"movff",evaluate0Parameter}};


void setUp(void){}
void tearDown(void){}

void test_evaluate0Parameter() {
	
	Error exception;
	String string = {.rawString = "",.startIndex = 0, .length = 0};
	Argument *argument;
	
	Try {
		argument = evaluate0Parameter(&string);
	} Catch(exception) {
		TEST_FAIL_MESSAGE("Should not throw an error");
	}
	TEST_ASSERT_EQUAL(-1, argument->operand1);
	TEST_ASSERT_EQUAL(-1, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);
	TEST_ASSERT_EQUAL(0, string.length);
	
	TEST_ASSERT_NOT_NULL(argument);
	
	free(argument);
}

void test_evaluate0Parameter_should_pass() {
	Error exception;
	String string = {.rawString = ";",.startIndex = 0, .length = 1};
	Argument *argument;
	
	Try {
		argument = evaluate0Parameter(&string);
	} Catch(exception) {
		TEST_FAIL_MESSAGE("Should not throw an error");
	}
	TEST_ASSERT_EQUAL(-1, argument->operand1);
	TEST_ASSERT_EQUAL(-1, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);
	TEST_ASSERT_EQUAL(0, string.length);
	
	TEST_ASSERT_NOT_NULL(argument);
	
	free(argument);
}

void test_evaluate0Parameter_should_fail() {
	Error exception;
	String string = {.rawString = "abbc",.startIndex = 0, .length = 4};
	Argument *argument;
	
	Try {
		argument = evaluate0Parameter(&string);
		TEST_FAIL_MESSAGE("Should throw an error");
	} Catch(exception) {
		printf("Invalid Argument");
	}

	free(argument);
}

/*
void test_evaluate1Parameter() {

	Error exception;
	String string = {.rawString = "0xfc",.startIndex = 0, .length = 4};
	Argument *argument;
	
	
	
	Try {
		argument = evaluate1Parameter(&string);
	} Catch(exception) {
		printf("Invalid Argument");
	}
	TEST_ASSERT_EQUAL(4, argument->operand1);
	TEST_ASSERT_EQUAL(-1, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);
	TEST_ASSERT_EQUAL(0, string.length);
	
	TEST_ASSERT_NOT_NULL(argument);
	
	free(argument);
	
}
*/