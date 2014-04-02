#ifndef Interpret_H
#define Interpret_H

#include "EvaluateParameter.h"

typedef struct {
	char *mnemonic;
	Opcode opcode;
	Argument *(*evaluate)(String*);
}InstructionTable;


int isLabel(String *word);


#endif // Interpret_H
