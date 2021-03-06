#include "unity.h"
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "mock_Token.h"
#include <malloc.h>
#include "Error.h"

void setUp(void){}
void tearDown(void){}

// Evaluate0parameter 
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluate1parameter

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

void test_evaluate1parameter_should_pass_if_pass_in_extra_spacing_in_one_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw     0xfe" , .startIndex = 10, .length = 4};
	String subString = {.rawString = "movlw     0xfe" , .startIndex = 10, .length = 4};
	
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

void test_evaluate1parameter_should_throw_an_exception_when_there_is_no_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw" , .startIndex = 5, .length = 0};
	String subString = {.rawString = "movlw" , .startIndex = 5, .length = 0};

	Try {
		argument = evaluate1Parameter(&parameter);
		TEST_FAIL_MESSAGE("Should throw an error");
	} Catch(exception) {
		printf("Invalid Argument");
	}

	free(argument);
	
}

void test_evaluate1parameter_should_fail_if_pass_in_wrong_parameter_comma() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw ," , .startIndex = 6, .length = 1};
	String subString = {.rawString = "movlw ," , .startIndex = 6, .length = 1};
	
	Try {
		argument = evaluate1Parameter(&parameter);
		TEST_FAIL_MESSAGE("Should throw an error");
	} Catch(exception) {
		printf("Invalid Argument");
	}

	free(argument);
	
}

void test_evaluate1parameter_should_fail_if_pass_in_wrong_parameter_semicolon() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw ;" , .startIndex = 6, .length = 1};
	String subString = {.rawString = "movlw ;" , .startIndex = 6, .length = 1};
	
	Try {
		argument = evaluate1Parameter(&parameter);
		TEST_FAIL_MESSAGE("Should throw an error");
	} Catch(exception) {
		printf("Invalid Argument");
	}

	free(argument);
	
}

void test_evaluate1parameter_should_throw_an_exception_when_pass_in_more_than_one_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movlw 0xff,0xfc" , .startIndex = 6, .length = 9};
	String subString = {.rawString = "movlw 0xff,0xfc" , .startIndex = 6, .length = 4};
	
	evaluate_ExpectAndReturn(&subString, 0xff);

	Try {
		argument = evaluate1Parameter(&parameter);
		TEST_FAIL_MESSAGE("Should throw an error");
	} Catch(exception) {
		printf("Invalid Argument");
	}

	free(argument);
	
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluate2parameter 

void test_evaluate2parameter_should_pass_if_two_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movff 0xfe,0xff" , .startIndex = 6, .length = 9};
	String subString1 = {.rawString = "movff 0xfe,0xff" , .startIndex = 6, .length = 4};
	String subString2= {.rawString = "movff 0xfe,0xff" , .startIndex = 11, .length = 4};
	
	evaluate_ExpectAndReturn(&subString1, 0xfe);
	
	evaluate_ExpectAndReturn(&subString2, 0xff);
	
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



void test_evaluate2parameter_should_fail_if_pass_wrong_parameter_comma_first() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movff ,0xfe 0xff" , .startIndex = 6, .length = 9};
	String subString1 = {.rawString = "movff ,0xfe 0xff" , .startIndex = 6, .length = 4};
	String subString2= {.rawString = "movff ,0xfe 0xff" , .startIndex = 12, .length = 4};
	
	
	Try {
	argument = evaluate2Parameter(&parameter);
	TEST_FAIL_MESSAGE("Should throw error");
	 }Catch(exception) {
		printf("Invalid Argument");
	}
	
	free(argument);
	
}

void test_evaluate2parameter_should_fail_if_pass_in_less_parameter_one_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movff 0xfe," , .startIndex = 6, .length = 4};
	String subString1 = {.rawString = "movff 0xfe," , .startIndex = 6, .length = 4};
	String subString2= {.rawString = "movff 0xfe," , .startIndex = 10, .length = 0};
	
	evaluate_ExpectAndReturn(&subString1, 0xfe);
	
	Try {
	argument = evaluate2Parameter(&parameter); 
	TEST_FAIL_MESSAGE("Should throw error");
	 }Catch(exception) {
		printf("Invalid Argument");
	}
	
	free(argument);
	
}


void test_evaluate2parameter_should_fail_if_pass_in_more_than_two_parameter() {
	Error exception;
	Argument *argument;
	String parameter = {.rawString = "movff 0xfe,0xff,0xfc" , .startIndex = 6, .length = 14};
	String subString1 = {.rawString = "movff 0xfe,0xff,0xfc", .startIndex = 6, .length = 4};
	String subString2= {.rawString = "movff 0xfe,0xff,0xfc" , .startIndex = 11, .length =4};
	String subString3= {.rawString = "movff 0xfe,0xff,0xfc" , .startIndex = 16, .length =4};
	
	evaluate_ExpectAndReturn(&subString1, 0xfe);
	evaluate_ExpectAndReturn(&subString2, 0xff);
	
	
	Try {
	argument = evaluate2Parameter(&parameter); 
	TEST_FAIL_MESSAGE("Should throw error");
	 }Catch(exception) {
		printf("Invalid Argument");
	}
	
	free(argument);
	
}

