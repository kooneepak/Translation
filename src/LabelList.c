#include "Interpret.h"
#include "StringObject.h"
#include "LabelList.h"
#include "CException.h"
#include "Error.h"
#include <string.h>

extern InstructionTable instructionTable[];

/*
 * This function is to check is it a valid label 
 * 
 * Input :
 *			*word The valid label
 * 	
 *
 * Return:
 *	0				if is label
 * 	1				
 * 
 */

int isLabel(String *word){
	int i,j;
	for(i =0 ; i<41 ; i++) {
		if(stringCompare(instructionTable[i].mnemonic, word)) {
			return 0;
		}
	}
	for(j=0 ; j < word->length ; j++){
		if(isalpha(word->rawString[word->startIndex + j]) || isValidSymbol(word->rawString[word->startIndex + j]))
			;
		else
			Throw(INVALID_LABEL);
	}
	return 1;
}

/*
 * This function is to check is it a valid symbol 
 * 
 * Input :
 *			character The valid symbol
 * 	
 *
 * Return:
 *	1				if is label
 * 	0				
 * 
 */
						 

int isValidSymbol(char character){
	if(character == '.' || character == '?' || character == '@' || character == '#' || character == '_' ) 
		return 1;	
	else
		return 0;
}
// Add storeLabel



