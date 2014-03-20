#ifndef EvaluateParameter_H
#define EvaluateParameter_H
#include "StringObject.h"


typedef  struct {
	int operand1;
	int operand2;
	int operand3;
} Argument;

typedef struct {
	char *name;
	Argument *(*evaluate)(String*);
} Opcode;


Argument *evaluate0Parameter(String *argument);
// Argument evaluate1Parameter(String *argument);
// Argument evaluate2Parameter(String *argument);




extern Opcode opcodeTable[];

#endif // EvaluateParameter_H
