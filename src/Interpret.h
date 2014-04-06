#ifndef Interpret_H
#define Interpret_H

#include "EvaluateParameter.h"

typedef struct {
	char *mnemonic;
	Opcode opcode;
	Argument *(*evaluate)(String*);
}InstructionTable;

extern InstructionTable instructionTable[];

#endif // Interpret_H
