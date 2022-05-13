/*
Assignment #1 Milestone #4
Min Young Choe
ID : 133607218 Email:mchoe@myseneca.ca
IPC144/ZBB
*/

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#include <time.h>
#include "account.h"

// macros
#define MAX_LETTERS 30

//1. currentYear
// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system 
int currentYear(void);

//2. clearStandardInputBuffer
void clearStandardInputBuffer(void); //clear the value

//3. validate only interger value
int getInteger(void);

//4. validate only positive interger value 
int getPositiveInteger(void);

//5. validate only interger value between ranges
int getIntFromRange(int lowValue, int upValue);

//6. validate only double value
double getDouble(void);

//7. validate only positive double value
double getPositiveDouble(void);

//8. 
char getCharOption(const char validChar[]);

//9.
void getCString(char cString[], int min, int max);

//10.
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person);

#endif // !COMMON_HELPERS_H_
