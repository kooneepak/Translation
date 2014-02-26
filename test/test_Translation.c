#include "unity.h"
#include "Translation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUp(){}

void tearDown(){}


void test_readFile (){
	
	char *string;
	string = readFile();
	printf("%c",string);
	//TEST_ASSERT_EQUAL_STRING("movlw",string);

}
