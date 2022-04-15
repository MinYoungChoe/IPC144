#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#define MAX_NAME 30
#define MAX_NATION 30
#define MAX_ID 10
#define MAX_PW 8
#include <stdio.h>


struct Person
{
    char fullName[MAX_NAME + 1];
    int birthYear;
    double income;
    char nation[MAX_NATION + 1];
};

struct  UserLogin
{
    char loginId[MAX_ID + 1];
    char passWord[MAX_PW + 1];
};

struct  Account
{
    int accountNum;
    char accountType;
    struct Person person;
    struct UserLogin userLogin;
};

void getAccount(struct Account* account);
void getPerson(struct Person* person);
void getUserLogin(struct UserLogin* userLogin);
void updateAccount(struct Account* account);
void updatePerson(struct Person* person);
void updateUserLogin(struct UserLogin* userLogin);

#endif
