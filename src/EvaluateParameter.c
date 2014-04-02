#include <stdio.h>
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include "Token.h"
#include "Error.h"
#include <malloc.h>

extern Error exception;

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


Argument *evaluate1Parameter(String *rawOperand){

	String *subString ;
	Argument *argument = malloc(sizeof(Argument));
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;"); // check one parameter
	stringRightTrim(rawOperand);
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand1 = evaluate(subString);
		
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");// than check again 
	stringRightTrim(rawOperand);
	
	if(subString->length == 0 ){
		argument->operand2 = -1;
		argument->operand3 = -1;
	} else 
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
	}

Argument *evaluate2Parameter(String *rawOperand){

	String *subString ;
	Argument *argument = malloc(sizeof(Argument));
	subString = getWordAndUpdate(rawOperand, ",;");
	
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand1 = evaluate(subString);
	
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");
	stringRightTrim(rawOperand);
	
	//printf("csub: %x\n", subString);
	if(subString->length == 0)
		Throw(INVALID_ARGUMENT);
	else
		argument->operand2 = evaluate(subString);
	
	stringLeftTrim(rawOperand);
	subString = getWordAndUpdate(rawOperand, ",;");
	stringRightTrim(rawOperand);
	
	//printf("csub: %x\n", subString);
	if(subString->length == 0 ){
		argument->operand3 = -1;
	} else 
		Throw(INVALID_ARGUMENT);
	
	return argument;
	
}





	