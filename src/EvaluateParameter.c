#include <stdio.h>
#include "EvaluateParameter.h"
#include "CException.h"
#include "StringObject.h"
#include <malloc.h>

Argument *evaluate0Parameter(String *rawOperand){
	subString = getWordAndUpdate(rawOperand, ",;");
	Argument *argument = malloc(sizeof(Argument));
	
	if(subString->length == 0) {
		argument->operand1 = -1;
		argument->operand2 = -1;
		argument->operand3 = -1;
	} else
		Throw(INVALID_ARGUMENT);
	
	return argument;
}