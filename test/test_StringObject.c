#include "unity.h"
#include <stdio.h>
#include <malloc.h>
#include "StringObject.h"

void setUp() {}
void tearDown() {}





void test_getWordAndUpdate_should_get_the_first_word_from_a_line_with_space_delimiter() {
String oneLineString = {.rawString = "bcf 0x20", .startIndex = 0, .length = 8};

	

}


void test_getWordAndUpdate_should_get_the_first_and_second_word_from_a_line_with_space_delimiter() {
String oneLineString = {.rawString = "bcf 0x20", .startIndex = 0, .length = 8};

subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(3, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(5, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('b', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('c', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('f', subString->rawString[subString->startIndex + 2]);

	free(subString);

	subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(4, subString->startIndex);
	TEST_ASSERT_EQUAL(4, subString->length);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('x', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('2', subString->rawString[subString->startIndex + 2]);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex + 3]);

	free(subString);
}


void test_getWordAndUpdate_should_get_a_zero_length_word_when_getting_words_beyond_the_line() {
String oneLineString = {.rawString = "bcf 0x20", .startIndex = 0, .length = 8};

	subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(3, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(5, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('b', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('c', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('f', subString->rawString[subString->startIndex + 2]);


	free(subString);

	subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(4, subString->startIndex);
	TEST_ASSERT_EQUAL(4, subString->length);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('x', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('2', subString->rawString[subString->startIndex + 2]);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex + 3]);

	free(subString);

	subString = getWordAndUpdate(&oneLineString, " ");

	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(8, subString->startIndex);
	TEST_ASSERT_EQUAL(0, subString->length);

	free(subString);
}

void test_getWordAndUpdate_should_get_the_instruction_operand1_operand2_from_a_line_with_space_delimiter() {
	String oneLineString = {.rawString = "bcf 0x20, 0", .startIndex = 0, .length = 11};
	
	subString = getWordAndUpdate(&oneLineString, " ,");

	TEST_ASSERT_EQUAL(3, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(8, oneLineString.length);
	TEST_ASSERT_EQUAL(0, subString->startIndex);
	TEST_ASSERT_EQUAL(3, subString->length);
	TEST_ASSERT_EQUAL('b', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('c', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('f', subString->rawString[subString->startIndex + 2]);

	free(subString);
	
	
	subString = getWordAndUpdate(&oneLineString, " ,");

	TEST_ASSERT_EQUAL(8, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(3, oneLineString.length);
	TEST_ASSERT_EQUAL(4, subString->startIndex);
	TEST_ASSERT_EQUAL(4, subString->length);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex]);
	TEST_ASSERT_EQUAL('x', subString->rawString[subString->startIndex + 1]);
	TEST_ASSERT_EQUAL('2', subString->rawString[subString->startIndex + 2]);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex + 3]);

	free(subString);
	
	
	subString = getWordAndUpdate(&oneLineString, " ,");

	TEST_ASSERT_EQUAL(11, oneLineString.startIndex);
	TEST_ASSERT_EQUAL(0, oneLineString.length);
	TEST_ASSERT_EQUAL(10, subString->startIndex);
	TEST_ASSERT_EQUAL(1, subString->length);
	TEST_ASSERT_EQUAL('0', subString->rawString[subString->startIndex]);


	free(subString);
	
}

