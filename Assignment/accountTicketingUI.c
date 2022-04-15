
#include "accountTicketingUI.h"

void displayAccountDetailHeader(void)
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}

void displayAccountDetailRecord(const struct Account* account)
{
    
    struct Account accountInfo = *account;
    
    printf("%05d ", accountInfo.accountNum);
    
    if (accountInfo.accountType == 'A')
    {
        printf("%-9s ", "AGENT");
    }
    else
    {
        printf("%-9s ", "CUSTOMER");
    }
    
    printf("%-15s ", accountInfo.person.fullName);
    
    printf("%5d ", accountInfo.person.birthYear);
    
    printf("%11.2lf ", accountInfo.person.income);
    
    printf("%-10s ", accountInfo.person.nation);
    

    if (accountInfo.accountType  != 'C'){
         printf("%-10s ", accountInfo.userLogin.loginId);
    
         char password[sizeof(accountInfo.userLogin.passWord)];
         
         int i = 0;
         for (i = 0; i < sizeof(accountInfo.userLogin.passWord); i++)
         {
             if (i % 2 == 0)
             {
                 password[i] = accountInfo.userLogin.passWord[i];
             }
             else
             {
                 password[i] = '*';
             }
         }
         
         printf("%8s\n", password);
    }
    else{
         printf("%-10s ", "          ");
         printf("%8s\n", "        ");
    }
}

void applicationStartup(struct Account accounts[], int arrSize)
{
    
    while (1)
    {
        int index = menuLogin(accounts, arrSize);
        if (index == -1)
        {
            break;
        }
        else
        {
            menuAgent(accounts, arrSize, &accounts[index]);
        }
    }
    
    printf("==============================================\n");
    printf("Account Ticketing System - Terminated\n");
    printf("==============================================\n");
}

int menuLogin(const struct Account accounts[], int arrSize)
{
    
    int valid = 0;
    int index = -1;
    
    do
    {
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n\n");
        printf("Selection: ");
        
        if (getIntFromRange(0, 1) == 0)
        {
            
            printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
            char input = getCharOption("yYnN");
            if (input == 'y' || input == 'Y')
            {
                valid = 1;
            }
            printf("\n");
        }
        else
        {
            printf("\nEnter your account#: ");
            int input = getInteger();
            char accountType = ' ';
            
            int i = 0;
            for (i = 0; i < arrSize; i++)
            {
                
                if (accounts[i].accountNum == input)
                {
                    index = i;
                    accountType = accounts[i].accountType;
                    break;
                }
            }
            
            if (accountType != 'A')
            {
                
                printf("ERROR:  Login failed!\n\n");
                pauseExecution();
            }
            else
            {
                printf("\n");
                valid = 1;
            }
        }
    } while (!valid);
    
    return index;
}

void menuAgent(struct Account accounts[], int arrSize, const struct Account* account)
{
    
    struct Account accountInfo = *account;
    int option = -1;
    
    while (1)
    {
        printf("AGENT: %s", accountInfo.person.fullName);
        printf(" (%d)\n", accountInfo.accountNum);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n\n");
        printf("Selection: ");
        
        option = getIntFromRange(0, 4);
        printf("\n");
        
        if (option == 1)
        {
            int accountAdded = 0;
            
            int i = 0;
            for (i = 0; i < arrSize; i++)
            {
                if (accounts[i].accountNum == 0)
                {
                    struct Account account = { 0 };
                    
                    getAccount(&account);
                    
                    accounts[i] = account;
                    accountAdded = 1;
                    break;
                }
            }
            
            if (accountAdded)
            {
                printf("*** New account added! ***\n\n");
            }
            else
            {
                printf("ERROR: Account listing is FULL, call ITS Support!\n");
            }
            
            pauseExecution();
        }
        else if (option == 2)
        {
            int accountFound = 0;
            int index = -1;
            
            printf("Enter the account#: ");
            int input = getInteger();
            printf("\n");
            
            int i = 0;
            for (i = 0; i < arrSize; i++)
            {
                if (accounts[i].accountNum == input)
                {
                    accountFound = 1;
                    index = i;
                    break;
                }
            }
            
            if (accountFound)
            {
                updateAccount(&accounts[index]);
            }
            else {
                printf("ERROR: Account is not found!\n");
            }
        }
        else if (option == 3)
        {
            int accountFound = 0;
            int index = -1;
            
            printf("Enter the account#: ");
            int input = getInteger();
            //printf("\n");
            
            int i = 0;
            for (i = 0; i < arrSize; i++)
            {
                if (accounts[i].accountNum == input)
                {
                    index = i;
                    accountFound = 1;
                    break;
                }
            }
            
            if (accountFound)
            {
                if (accountInfo.accountNum != input)
                {
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&accounts[index]);
                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    char input = getCharOption("YN");
                    if (input == 'Y') {
                        accounts[index].accountNum = 0;
                        printf("\n*** Account Removed! ***\n\n");
                        pauseExecution();
                    }
                }
                else
                {
                    printf("\nERROR: You can't remove your own account!\n\n");
                    pauseExecution();
                }
            }
            else
            {
                printf("ERROR: Account is not found!\n");
            }
        }
        else if (option == 4)
        {
            displayAllAccountDetailRecords(accounts, arrSize);
            printf("\n");
            pauseExecution();
        }
        else if (option == 0)
        {
            printf("### LOGGED OUT ###\n\n");
            break;
        }
    }
}

int findAccountIndexByAcctNum(int accountNum, const struct Account accounts[], int maxNum, int isPrompt)
{
    
    int index = -1;
    
    if (isPrompt)
    {
        printf("Enter the account#: ");
        accountNum = getInteger();
    }
    
    int i = 0;
    for (i = 0; i < maxNum; i++)
    {
        if (accounts[i].accountNum == accountNum)
        {
            index = i;
            break;
        }
    }
    return index;
}

void displayAllAccountDetailRecords(const struct Account accounts[], int maxNum)
{
    
    displayAccountDetailHeader();
    
    int i = 0;
    for (i = 0; i < maxNum; i++)
    {
        if (accounts[i].accountNum > 0)
        {
            displayAccountDetailRecord(&accounts[i]);
        }
    }
}

void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}
