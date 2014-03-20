#include "unity.h"
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include <malloc.h>

Opcode opcodeTable[] =  {{"clrwdt",evaluate0Parameter},
						{"movlw",evaluate0Parameter},
						{"movff",evaluate0Parameter}};


void setUp(void){}
void tearDown(void){}

void test_evaluate0Parameter_should__parameter() {
	
	Error exception;
	String string = {.rawString = "",.startIndex = 0, .length = 0};
	Argument *argument;
	
	Try {
		argument = evaluate0Parameter(&string);
	} Catch(exception) {
		printf("Invalid Argument");
	}
	TEST_ASSERT_EQUAL(-1, argument->operand1);
	TEST_ASSERT_EQUAL(-1, argument->operand2);
	TEST_ASSERT_EQUAL(-1, argument->operand3);
	TEST_ASSERT_EQUAL(0, subString->length);
	TEST_ASSERT_EQUAL(0, string.length);
	
	TEST_ASSERT_NOT_NULL(argument);
	
	free(argument);
}