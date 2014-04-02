#include "unity.h"
#include "Interpret.h"
#include "EvaluateParameter.h"
#include "mock_Token.h"
#include "StringObject.h"
#include "CException.h"
#include "Error.h"

Error e;

extern InstructionTable instructionTable[];

void setUp(void){}

void tearDown(void){}

void test_isLabel_should_return_1_if_the_word_is_an_label() {
	String word = {.rawString = "label", .startIndex = 0, .length = 5};
	int result;
	
	result = isLabel(&word);
	
	TEST_ASSERT_EQUAL(1, result);
}

void test_isLabel_should_return_0_if_the_word_is_not_an_label() {
	String word = {.rawString = "bz", .startIndex = 0, .length = 2};
	int result;
	
	result = isLabel(&word);
	
	TEST_ASSERT_EQUAL(0, result);
}

void test_isLabel_should_throw_an_exception_if_the_first_character_of_the_word_is_number() {
	String word = {.rawString = "1abc", .startIndex = 0, .length = 4}; 
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) {
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}

}

void test_isLabel_should_throw_an_exception_if_the_first_character_of_the_word_is_symbol() {
	String word = {.rawString = "!!!abc", .startIndex = 0, .length = 5}; 
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) {
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}

}

