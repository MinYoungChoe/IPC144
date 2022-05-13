/*
Assignment #1 Milestone #4
Min Young Choe
ID : 133607218 Email:mchoe@myseneca.ca
IPC144/ZBB
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commonHelpers.h"
// Uses the time.h library to obtain current year information // Get the current 4-digit year from the system
#include <time.h>

int valid;
int i;
int value;
double dbValue;
char newLine = 'x';

int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

void clearStandardInputBuffer(void)
{
    while (getchar() != '\n') //scanf("%c", &variable) without assiging, just return a single character from buffer
    {
        ; // On purpose: do nothing
    }
}

int getInteger(void)
{
    value = 0;
    newLine = 0;
    
    do
    {
        scanf("%d%c", &value, &newLine);
        
        if (newLine != '\n') // invalid integer
        {
            valid = 0;
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else
        {
            valid = 1;
        }
    } while (!valid);
    
    return value;
}

int getPositiveInteger(void) //%c
{
    value = 0;
    newLine = 0;
    do
    {
        scanf("%d%c", &value, &newLine);
        
        if (newLine != '\n') // invalid integer
        {
            valid = 0;
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else
        {
            if (value > 0)
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                printf("ERROR: Value must be a positive integer greater than zero: ");
            }
        }
    } while (!valid);
    
    return value;
}

double getDouble(void)
{
    dbValue = 0.0;
    newLine = 0;
    
    do
    {
        scanf("%lf%c", &dbValue, &newLine);
        
        if (newLine != '\n') // invalid integer //the last element of char array in the buffer is "\n"
        {
            valid = 0;
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else
        {
            valid = 1;
        }
    } while (!valid);
    
    return dbValue;
}

double getPositiveDouble(void)
{
    dbValue = 0.0;
    newLine = 0;
    do
    {
        scanf("%lf%c", &dbValue, &newLine);
        
        if (newLine != '\n') // invalid integer
        {
            valid = 0;
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else
        {
            if (dbValue > 0)
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                printf("ERROR: Value must be a positive double floating-point number: ");
            }
        }
    } while (!valid);
    return dbValue;
}

int getIntFromRange(int lowValue, int upValue)
{
    value = 0;
    
    do
    {
        newLine = 0;
        scanf("%d%c", &value, &newLine);
        
        if (newLine != '\n')
        {
            valid = 0;
            clearStandardInputBuffer(); //fix scanf
            printf("ERROR: Value must be an integer: ");
        }
        else
        {
            if (value < lowValue || value > upValue)
            {
                valid = 0;
                printf("ERROR: Value must be between %d and %d inclusive: ", lowValue, upValue);
            }
            else
            {
                valid = 1;
            }
        }
    } while (!valid);
    
    return value;
}

char getCharOption(const char validChar[]) //we dont know size const char* charArr
{
    char userChar[MAX_LETTERS + 1];
    int length;
    
    do
    {
        valid = 0;
        // check if it's a single character
        scanf("%30[^\n]", userChar);
        clearStandardInputBuffer();
        //validChar={'v','a','l','i','d'}; //char array
        //validChar={'v','a','l','i','d','\0'}; //c-string
        //validChar="valid"; //c-string
        
        // get the length of user input
        for (length = 0; userChar[length] != '\0'; length++)
        {
            ;
        }
        
        // check if the length is eqaul to one (a single character)
        if (length == 1)
        {
            // set valid to 0 by default | if(matching data not found AND have data left)
            for (i = 0, valid = 0; !valid && validChar[i] != '\0'; i++)
            {
                if (userChar[0] == validChar[i])
                {
                    valid = 1;
                }
            }
        }
        
        if (!valid)
        {
            printf("ERROR: Character must be one of [%s]: ", validChar);
        }
    } while (!valid);
    
    return userChar[0];
}

// 메모리 error 가능성 : userChar의 사이즈가 정해지지 않아 생길 수 있음.
void getCString(char cString[], int min, int max)
{
    newLine = 0; //char symbolic -- integral 'a':65 
    char userChar[MAX_LETTERS + 1]; // temporary array for user input
    int length;
    
    do
    {
        // scanf : get user input --> buffer(char[]) --> store into a variable in our program
        // Seneca College --> buffer : char[]= {'S','E', ....}-->
        // 1) %s : extracts values from buffer until it finds whitespace 
        // 2) attempt to store whatever however :dhsfdsahdsjfkhdsfskfjhsdsfddkhhhhh : exceeds the size of array
        scanf("%30[^\n]", userChar);
        clearStandardInputBuffer(); //clear \n in the buffer
        
        //printf("ERROR: 1111  %s , max: %d\n", cString, max);
        
        for (length = 0; userChar[length] != '\0'; length++)
        {
            ;//printf("ERROR: 222 String length  : %d , max: %d\n", length, max);
        } // length becomes the length of userChar before when it exits the iteration
        
        //printf("ERROR: 222 String length  : %d , max: %d\n", length, max);
        
        if ((min == max) && (length != min)) // min == max
        {
            valid = 0; //make it false
            //display an error message
            printf("ERROR: String length must be exactly %d chars: ", min);
        }
        else if (length > max)
        {
            valid = 0; //make it false
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (length < min)
        {
            valid = 0; //make it false
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        // 1st : if min and max are the same value, it requires the exact number of chars
        // 2nd : if the exact number is not equal to the length of user input
        else
        {
            valid = 1;
            // return a C string via the cStirng[] pointer
            
            //1) *cString = userChar; //ab (X)
            //2) *cString = {'a', 'b'}; //ab (X)
            //3) for-loop (O)
            
            for (i = 0; i < length; i++)
            {
                cString[i] = userChar[i];
            }
            // add the null terminator
            cString[length] = '\0';
        }
        /*
         // validate if it's within the range(min~max)
         if (length > max)
         {
         valid = 0; //make it false
         printf("ERROR: String length must be no more than %d chars: ", max);
         }
         else if (length < min)
         {
         valid = 0; //make it false
         printf("ERROR: String length must be between %d and %d chars: ", min, max);
         }
         // 1st : if min and max are the same value, it requires the exact number of chars
         // 2nd : if the exact number is not equal to the length of user input
         else if ((min == max) && (length != min)) // min == max
         {
         valid = 0; //make it false
         //display an error message
         printf("ERROR: String length must be exactly %d chars: ", min);
         }
         else
         {
         valid = 1;
         // return a C string via the cStirng[] pointer
         
         //1) *cString = userChar; //ab (X)
         //2) *cString = {'a', 'b'}; //ab (X)
         //3) for-loop (O)
         for (i = 0; i < length; i++)
         {
         cString[i] = userChar[i];
         }
         // add the null terminator
         cString[length] = '\0';
         }
         */
    } while (!valid);
}

