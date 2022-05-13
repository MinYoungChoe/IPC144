#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commonHelpers.h"
#include "account.h"

void getAccount(struct Account* account)
{
    
    struct Account accountInfo;
    
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    
    printf("Enter the account number: ");
    accountInfo.accountNum = getInteger();
    printf("\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    accountInfo.accountType = getCharOption("AC");
    printf("\n");
    
    getPerson(&accountInfo.person);
    if (accountInfo.accountType == 'A')
    {
        getUserLogin(&accountInfo.userLogin);
    }
    else
    {
        struct UserLogin userLogin = { {0}, {0} };
        accountInfo.userLogin = userLogin;
    }
    
    *account = accountInfo;
}

void getPerson(struct Person* person)
{
    
    struct Person customerInfo;
    
    printf("Person Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter the person's full name (30 chars max): ");
    scanf("%30[^\n]", customerInfo.fullName);
    printf("Enter birth year (current age must be between 18 and 110): ");
    currentYear();
    customerInfo.birthYear = getIntFromRange(1911, 2003);
    printf("Enter the household Income: $");
    customerInfo.income = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    scanf("%30[^\n]", customerInfo.nation);
    clearStandardInputBuffer();
    printf("\n");
    
    *person = customerInfo;
}

void getUserLogin(struct UserLogin* userLogin)
{
    
    struct UserLogin loginInfo;
    
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter user login (10 chars max): ");
    getCString(loginInfo.loginId, 1, 10);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(loginInfo.passWord, 8, 8);
    printf("\n");
    
    *userLogin = loginInfo;
}

void updateAccount(struct Account* account)
{
    
    struct Account accountInfo = *account;
    int option = -1;
    
    while (1) {
        printf("Update Account: %d (%s)\n", accountInfo.accountNum, accountInfo.person.fullName);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", accountInfo.accountType);
        printf("2) Person\n");
        printf("3) Login\n");
        printf("0) Done\n");
        printf("Selection: ");
        
        option = getIntFromRange(0, 3);
        printf("\n");
        
        if (option == 1)
        {
            printf("Enter the account type (A=Agent | C=Customer): ");
            char input = getCharOption("AC");
            if (input == 'A')
            {
                account->accountType = input;
                printf("\nAgent type accounts require a user login.  Please enter this information now:\n\n");
                getUserLogin(&account->userLogin);
                accountInfo = *account;
            }
            else {
                printf("\n");
                account->accountType = input;
                accountInfo = *account;
                
            }
        }
        else if (option == 2)
        {
            updatePerson(&account->person);
            accountInfo = *account;
        }
        else if (option == 3)
        {
            if (accountInfo.accountType == 'C')
            {
                printf("ERROR:  Customer account types don't have user logins!\n\n");
            } else {
                updateUserLogin(&account->userLogin);
                accountInfo = *account;
            }
        }
        else if (option == 0)
        {
            break;
        }
    }
}

void updatePerson(struct Person* person)
{
    
    struct Person personInfo = *person;
    int option = -1;
    
    while (1)
    {
        printf("Person Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Full name (current value: %s)\n", personInfo.fullName);
        printf("2) Household Income (current value: $%.2lf)\n",personInfo.income);
        printf("3) Country (current value: %s)\n", personInfo.nation);
        printf("0) Done\n");
        printf("Selection: ");
        
        option = getIntFromRange(0, 3);
        printf("\n");
        
        if (option == 1)
        {
            printf("Enter the person's full name (30 chars max): ");
            scanf("%30[^\n]", personInfo.fullName);
            printf("\n");
        }
        else if (option == 2)
        {
            printf("Enter the household Income: $");
            personInfo.income = getPositiveDouble();
            printf("\n");
        }
        else if (option == 3)
        {
            printf("Enter the country (30 chars max.): ");
            scanf("%30[^\n]", personInfo.nation);
            printf("\n");
        }
        else if (option == 0)
        {
            break; // exit the while loop
        }
    }
    *person = personInfo;
}

void updateUserLogin(struct UserLogin* userLogin)
{
    
    struct UserLogin userInfo = *userLogin;
    int option = -1;
    
    while (1)
    {
        printf("User Login: %s - Update Options\n", userInfo.loginId);
        printf("----------------------------------------\n");
        printf("1) Password\n");
        printf("0) Done\n");
        printf("Selection: ");
        
        option = getIntFromRange(0, 1);
        printf("\n");
        
        if (option == 1)
        {
            printf("Enter the password (must be 8 chars in length): ");
            getCString(userInfo.passWord, 8, 8);
            printf("\n");
        }
        else if (option == 0)
        {
            break; // exit the while loop
        }
    }
    *userLogin = userInfo;
}
