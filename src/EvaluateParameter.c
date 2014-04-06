#include <stdio.h>
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "Token.h"
#include "Error.h"
#include <malloc.h>

extern Error exception;

/*
* This function used by no parameter instructions to parse arguments
*
* Input: 	*rawOperand 	Whole line of parameter after the opcode get extracted
*
* Return: 	argument 		Argument type object that stores operands
*/

Argument *evaluate0Parameter(String *rawOperand){
	String *subString = getWordAndUpdate(rawOperand, ";");
	Argument *argument = malloc(sizeof(Argument));
	
	if(subString->length == 0) {
		argument->operand1 = -1;
		argument->operand2 = -1;
		argument->operand3 = -1;
	} else
		Throw(INVALID_ARGUMENT);
	
	return argument;
}


/*
 * This function used by one parameter instructions to parse arguments
 *
 * Input: 	*rawOperand 	Whole line of parameter after the opcode get extracted
 *
 * Return: 	argument 		Argument type object that stores operands
 */

Argument *evaluate1Parameter(String *rawOperand){

	String *subString ;
	Argument *argument = malloc(sizeof(Argument));
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;"); // check one parameter
	stringRightTrim(subString);
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand1 = evaluate(subString);
		
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");// than check again 
	stringRightTrim(subString);
	
	if(subString->length == 0 ){
		argument->operand2 = -1;
		argument->operand3 = -1;
	} else 
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
	}
	
	
/*
* This function used by two parameter instructions to parse arguments
*
* Input: 	*rawOperand 	Whole line of parameter after the opcode get extracted
*
* Return: 	argument 		Argument type object that stores operands
*/	

Argument *evaluate2Parameter(String *rawOperand){

	String *subString ;
	Argument *argument = malloc(sizeof(Argument));
	
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");
	stringRightTrim(subString);
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand1 = evaluate(subString);
	
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");
	stringRightTrim(subString);
	
	//printf("csub: %x\n", subString);
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand2 = evaluate(subString);
	
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");
	stringRightTrim(subString);
	
	//printf("csub: %x\n", subString);
	if(subString->length == 0 ){
		argument->operand3 = -1;
	} else 
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
}

/*
 * This function check if the string is previously delimited by the specified delimiter or not
 *
 * Input:	
 *		*string		String object that is been checking
 *		delimiter	Specified delimiter that previously delimit the string
 *
 * Return:	
 *		1	The string is previously delimited by the specified delimiter
 *		0	The string previously delimited by other delimiter (or not delimited)
 */
// int isDelimiter(String *string, char delimiter) {
	// int index = string->startIndex - 1;

	// while(string->rawString[index] == ' ' || string->rawString[index] == '\t') {
		// index--;
	// }
	// if(string->rawString[index] == delimiter)
		// return 1;
	// else
		// return 0;
// }



	