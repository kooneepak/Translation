#include <stdio.h>
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "Token.h"
#include <malloc.h>

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
Argument *evaluate1Parameter(String *rawOperand){

	subString = getWordAndUpdate(rawOperand, ",;");
	Argument *argument = malloc(sizeof(Argument));
	char *buffer;
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		buffer = stringCopy(subString, 0, subString->length);
		argument->operand1 = shuntingYard(buffer);
	
	if(subString->length == 0 ){
		argument->operand2 = -1;
		argument->operand3 = -1;
	} else
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
	}
	
Argument *evaluate2Parameter(String *rawOperand){

	subString = getWordAndUpdate(rawOperand, ",;");
	Argument *argument = malloc(sizeof(Argument));
	char *buffer;
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		buffer = stringCopy(subString, 0, subString->length);
		argument->operand1 = shuntingYard(buffer);
		argument->operand2 = shuntingYard(buffer);
	
	if(subString->length == 0 ){
		argument->operand3 = -1;
	} else
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
	}
*/
	