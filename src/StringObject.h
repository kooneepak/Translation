#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

typedef struct {
char *rawString;
int startIndex;
int length;
} String;

// Function Prototype
String *stringCreate(char *expression) ;
int stringCompare(char *expectString, String *stringObject);
char *stringCopy(String *source, int relStartIndex, int length);
void stringLeftTrim(String* string);
void stringRightTrim(String *string);

String *getWordAndUpdate(String *line, char *delimiter);

#endif // __STRING_OBJECT_H__