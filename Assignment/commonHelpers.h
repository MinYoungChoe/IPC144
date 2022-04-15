#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_
#include <time.h>
#include "account.h"
#define MAX_LETTERS 30
 
int currentYear(void);

void clearStandardInputBuffer(void); //clear the value

int getInteger(void);

int getPositiveInteger(void);

int getIntFromRange(int lowValue, int upValue);

double getDouble(void);

double getPositiveDouble(void);

char getCharOption(const char validChar[]);

void getCString(char cString[], int min, int max);

void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person);

#endif // !COMMON_HELPERS_H_
