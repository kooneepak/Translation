#ifndef __ERROR_H__
#define __ERROR_H__

typedef enum {INVALID_IDENTIFIER, UNKNOWN_OPERATOR, INVALID_ARGUMENT, INVALID_LABEL , INVALID_SYMBOL} Error;

typedef struct{
	char *rawString;
	int position;
	char *message;
} ErrorMessage;

extern ErrorMessage errorMessage;

#endif //__ERROR_H__