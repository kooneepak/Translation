#include "unity.h"
#include "Translation.h"




void setUp(){}



void tearDown(){}









void test_should_pass_if_correct_character(){



 char *string;

 string = readChar();



 UnityAssertEqualNumber((_U_SINT)(('m')), (_U_SINT)((string[0])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((string[1])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('v')), (_U_SINT)((string[2])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((string[3])), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((string[4])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string[5])), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualString((const char*)("movff"), (const char*)(string), (((void *)0)), (_U_UINT)26);

}
