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
	
	Try{
		result = isLabel(&word);
		
	} Catch(e) {
		TEST_FAIL_MESSAGE("should not throw error");
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}
}

void test_isLabel_should_return_0_if_the_word_is_not_an_label() {
	String word = {.rawString = "bz", .startIndex = 0, .length = 2};
	int result;
	
	Try{
		result = isLabel(&word);
		
	} Catch(e) {
		TEST_FAIL_MESSAGE("should not throw an error");
	}
	
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
	String word = {.rawString = "!!!abc", .startIndex = 0, .length = 6}; 
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) {
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}

}

void test_isLabel_should_return_1_if_the_word_is_an_symbol() {
	int result;
	
	result = isValidSymbol('?');
	TEST_ASSERT_EQUAL(1, result);
	
	result = isValidSymbol('.');
	TEST_ASSERT_EQUAL(1, result);
	
	result = isValidSymbol('@');
	TEST_ASSERT_EQUAL(1, result);
	
	result = isValidSymbol('#');
	TEST_ASSERT_EQUAL(1, result);
	
	result = isValidSymbol('_');
	TEST_ASSERT_EQUAL(1, result);
}

void test_isLabel_should_return_0_if_the_word_is_invalid_symbol() {
	int result;
	
	result = isValidSymbol('$');
	TEST_ASSERT_EQUAL(0, result);
	
	result = isValidSymbol('^');
	TEST_ASSERT_EQUAL(0, result);
	
	result = isValidSymbol('&');
	TEST_ASSERT_EQUAL(0, result);
	
	result = isValidSymbol('*');
	TEST_ASSERT_EQUAL(0, result);
	
	result = isValidSymbol('%');
	TEST_ASSERT_EQUAL(0, result);
	
}


void test_isLabel_should_return_1_if_the_word_is_valid_label_symbol() {
	String word = {.rawString = ".bz", .startIndex = 0, .length = 3};
	int result;
	
	result = isLabel(&word);
	
	TEST_ASSERT_EQUAL(1, result);
}

void test_isLabel_should_return_1_if_the_word_is_valid_label_bz() {
	String word = {.rawString = "bz.", .startIndex = 0, .length = 3};
	int result;
	
	Try{
		result = isLabel(&word);
		
	} Catch(e) {
		TEST_FAIL_MESSAGE("should not throw error");
	}
	
	TEST_ASSERT_EQUAL(1, result);
}


void test_isLabel_should_throw_an_exception_if_the_word_is_invalid_label_bz() {
	String word = {.rawString = "bz*", .startIndex = 0, .length = 3};
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) {
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}
}

void test_isLabel_should_return_1_if_the_word_is_valid_label() {
	String word = {.rawString = "@bz", .startIndex = 0, .length = 3};
	int result;
	
	result = isLabel(&word);
	
	TEST_ASSERT_EQUAL(1, result);

}

void test_isLabel_should_throw_an_exception_if_the_word_is_invalid_label_movff() {
	String word = {.rawString = "+movff", .startIndex = 0, .length = 6};
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) { 
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}

}

void test_isLabel_should_return_1_if_the_word_is_valid_label_for_valid_instruction() {
	String word = {.rawString = "movff@_?", .startIndex = 0, .length = 8};
	int result;
	
	result = isLabel(&word);
	
	TEST_ASSERT_EQUAL(1, result);

}

void test_isLabel_should_throw_an_exception_if_the_word_is_invalid_symbol_for_valid_label() {
	String word = {.rawString = "movff@^&", .startIndex = 0, .length = 8};
	int result;
	
	Try{
		result = isLabel(&word);
		TEST_FAIL_MESSAGE("should throw an error");
	} Catch(e) { 
		TEST_ASSERT_EQUAL(INVALID_LABEL, e);
	}

}




