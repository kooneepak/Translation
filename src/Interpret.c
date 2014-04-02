#include "Interpret.h"
#include "EvaluateParameter.h"
#include "Error.h"
#include "CException.h"

InstructionTable instructionTable[] =  {{.mnemonic = "clrwdt",.opcode = CLRWDT , .evaluate = evaluate0Parameter},
						 {.mnemonic = "daw",.opcode = DAW , .evaluate = evaluate0Parameter},
						 {.mnemonic = "nop",.opcode = NOP , .evaluate = evaluate0Parameter},
						 {.mnemonic = "pop",.opcode = POP , .evaluate = evaluate0Parameter},
						 {.mnemonic = "push",.opcode = PUSH, .evaluate = evaluate0Parameter},
						 {.mnemonic = "reset",.opcode = RESET, .evaluate = evaluate0Parameter},
						 {.mnemonic = "sleep",.opcode = SLEEP, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblrd*",.opcode = TBLRD, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblrd*+",.opcode = TBLRD_POSTINC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblrd*–",.opcode = TBLRD_POSTDEC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblrd+*",.opcode = TBLRD_PREINC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblwt*",.opcode = TBLWT, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblwt*+",.opcode = TBLWT_POSTINC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblwt*–",.opcode = TBLWT_POSTDEC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "tblwt+*",.opcode = TBLWT_PREINC, .evaluate = evaluate0Parameter},
						 {.mnemonic = "bc", .opcode = BC, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bn", .opcode = BN, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bnc", .opcode = BNC, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bnn", .opcode = BNN, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bnov", .opcode = BNOV, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bnz", .opcode = BNZ, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bov", .opcode = BOV, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bra", .opcode = BRA, .evaluate = evaluate1Parameter},
						 {.mnemonic = "bz", .opcode = BZ, .evaluate = evaluate1Parameter},
						 {.mnemonic = "goto", .opcode = GOTO, .evaluate = evaluate1Parameter},
						 {.mnemonic = "rcall", .opcode = RCALL, .evaluate = evaluate1Parameter},
						 {.mnemonic = "retfie", .opcode = RETFIE, .evaluate = evaluate1Parameter},
						 {.mnemonic = "retlw", .opcode = RETLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "return", .opcode = RETURN, .evaluate = evaluate1Parameter},
						 {.mnemonic = "addlw", .opcode = ADDLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "andlw", .opcode = ANDLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "iorlw", .opcode = IORLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "movlb", .opcode = MOVLB, .evaluate = evaluate1Parameter},
						 {.mnemonic = "movlw", .opcode = MOVLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "mullw", .opcode = MULLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "retlw", .opcode = RETLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "sublw", .opcode = SUBLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "xorlw", .opcode = XORLW, .evaluate = evaluate1Parameter},
						 {.mnemonic = "call", .opcode = CALL, .evaluate = evaluate1Parameter},
						 {.mnemonic = "movff", .opcode = MOVFF, .evaluate = evaluate2Parameter},
						 {.mnemonic = "lfsr", .opcode = LFSR, .evaluate = evaluate2Parameter}};


int isLabel(String *word){
	int i;
	for(i =0 ; i<41 ; i++) {
		if(stringCompare(instructionTable[i].mnemonic, word)) {
			return 0;
		}
	}
	if(word->rawString[0] >= 'a' && word->rawString[0] <= 'z' )
		return 1;	
	else
		Throw(INVALID_LABEL);
}						 


