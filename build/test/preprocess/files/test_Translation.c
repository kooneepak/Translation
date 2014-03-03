#include "unity.h"
#include "Translation.h"




void setUp(){}



void tearDown(){}





void test_readChar_should_pass_if_correct_character(){



 char *string;

 string = readChar();



 UnityAssertEqualNumber((_U_SINT)(('m')), (_U_SINT)((string[0])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((string[1])), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('v')), (_U_SINT)((string[2])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((string[3])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((string[4])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((string[5])), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualString((const char*)("movff"), (const char*)(string), (((void *)0)), (_U_UINT)24);

}





void test_readLine_should_read_first_line_from_the_file(){



 FILE *myFile;

 myFile = fopen("message.txt", "r");



 char *line;

 line = readLine(myFile);





 UnityAssertEqualNumber((_U_SINT)(('m')), (_U_SINT)((line[0])), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((line[1])), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('v')), (_U_SINT)((line[2])), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((line[3])), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((line[4])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 if ((('\n') != (line[5]))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)42);;};



 line = readLine(myFile);



 UnityAssertEqualNumber((_U_SINT)(('m')), (_U_SINT)((line[0])), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((line[1])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('v')), (_U_SINT)((line[2])), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('l')), (_U_SINT)((line[3])), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('w')), (_U_SINT)((line[4])), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

 if ((('\n') != (line[5]))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)51);;};



 line = readLine(myFile);



 UnityAssertEqualNumber((_U_SINT)(('m')), (_U_SINT)((line[0])), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('o')), (_U_SINT)((line[1])), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('v')), (_U_SINT)((line[2])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('w')), (_U_SINT)((line[3])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('f')), (_U_SINT)((line[4])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

 if ((('\n') != (line[5]))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)60);;};



 line = readLine(myFile);



 UnityAssertEqualNumber((_U_SINT)(('b')), (_U_SINT)((line[0])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('t')), (_U_SINT)((line[1])), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(('g')), (_U_SINT)((line[2])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

 if ((('\n') != (line[3]))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)67);;};



 fclose(myFile);



}
