#ifndef EvaluateParameter_H
#define EvaluateParameter_H
#include "StringObject.h"

typedef enum{
			CLRWDT,
			DAW, 
			NOP, 
			POP, 
			PUSH, 
			RESET, 
			SLEEP,
			TBLRD, 
			TBLRD_POSTINC, 
			TBLRD_POSTDEC,
			TBLRD_PREINC, 
			TBLWT, 
			TBLWT_POSTINC, 
			TBLWT_POSTDEC, 
			TBLWT_PREINC, 
			BC,
			BN, 	
			BNC, 	 
			BNN, 	 
			BNOV, 	 
			BNZ, 	 
			BOV, 	 
			BRA, 	 
			BZ,	 
			GOTO, 	 
			RCALL, 	 
			RETFIE, 	 
			RETLW, 	 
			RETURN, 	 
			ADDLW, 	 
			ANDLW, 	 
			IORLW, 	 
			MOVLB, 	 
			MOVLW, 	
			MULLW, 	 	 
			SUBLW, 	 
			XORLW, 	 
			CALL, 	
			LFSR,
			MOVFF
			}Opcode;

typedef  struct {
	int operand1;
	int operand2;
	int operand3;
} Argument;

Argument *evaluate0Parameter(String *rawOperand);
Argument *evaluate1Parameter(String *rawOperand);
Argument *evaluate2Parameter(String *rawOperand);


#endif // EvaluateParameter_H
