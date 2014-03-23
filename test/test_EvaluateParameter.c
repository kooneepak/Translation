#include "unity.h"
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "mock_Token.h"
#include <malloc.h>

Opcode opcodeTable[] =  {{"clrwdt",evaluate0Parameter},
						 {"movlw",evaluate1Parameter},
						 {"movff",evaluate0Parameter}};


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

void test_evaluate0Parameter_should_pass_if_insert_semicolon() {
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

void test_evaluate0Parameter_should_fail_if_insert_alphabet() {
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




void test_evaluate1parameter_should_pass_if_one_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw 0xfe" , .startIndex = 6, .length = 4};
	String subString = {.rawString = "movlw 0xfe" , .startIndex = 6, .length = 4};
	
	evaluate_ExpectAndReturn(&subString, 0xfe);
	
	Try {
	argument = evaluate1Parameter(&parameter); 
	 }Catch(exception) {
		TEST_FAIL_MESSAGE("Should not throw error");
	}
	
	TEST_ASSERT_EQUAL(0xfe, argument->operand1);
	TEST_ASSERT_EQUAL(-1, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);

	TEST_ASSERT_NOT_NULL(argument);	
	free(argument);
	
}


void test_evaluate2parameter_should_pass_if_two_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movff 0xfe,0xff" , .startIndex = 6, .length = 9};
	String subString1 = {.rawString = "movff 0xfe,0xff" , .startIndex = 6, .length = 4};
	String subString2= {.rawString = "movff 0xfe,0xff" , .startIndex = 11, .length = 4};
	
	evaluate_ExpectAndReturn(&subString1, 0xfe);
	//printf("sub1: %x\n", subString1);
	evaluate_ExpectAndReturn(&subString2, 0xff);
	//printf("sub2: %x\n", subString2);
	Try {
	argument = evaluate2Parameter(&parameter); 
	 }Catch(exception) {
		TEST_FAIL_MESSAGE("Should not throw error");
	}
	
	TEST_ASSERT_EQUAL(0xfe, argument->operand1);
	TEST_ASSERT_EQUAL(0xff, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);

	TEST_ASSERT_NOT_NULL(argument);	
	free(argument);
	
}
