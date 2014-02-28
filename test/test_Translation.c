#include "unity.h"
#include "Translation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUp(){}

void tearDown(){}




void test_should_pass_if_correct_character(){

	char *string;
	string = readChar();
	
	TEST_ASSERT_EQUAL('m', string[0]);
	TEST_ASSERT_EQUAL('o', string[1]);
	TEST_ASSERT_EQUAL('v', string[2]);
	TEST_ASSERT_EQUAL('f', string[3]);
	TEST_ASSERT_EQUAL('f', string[4]);
	TEST_ASSERT_EQUAL(0, string[5]);
	
	TEST_ASSERT_EQUAL_STRING("movff", string);
}



