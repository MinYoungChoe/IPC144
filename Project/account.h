/*
Assignment #1 Milestone #4
Min Young Choe
ID : 133607218 Email:mchoe@myseneca.ca
IPC144/ZBB
*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <stdio.h>

#define MAX_NAME 30
#define MAX_NATION 30
#define MAX_ID 10
#define MAX_PW 8

//This structure called person and has fullName, birthYear, income, country.
struct Person
{   //c string person's full name should be able to store up to 30chars.
    char fullName[MAX_NAME + 1];
    //interger type that represents birthyear
    int birthYear;
    //double floating-point type that represents income.
    double income;
    //c string thatt contain prson's country up to 30 characters.
    char nation[MAX_NATION + 1];
};

//This structure called userLogin and has loginId and passWord.
struct  UserLogin
{
    // C string that contain user login name up to 10 characters.
    char loginId[MAX_ID + 1];
    // C string that represents the password for user, up to 8 characters.
    char passWord[MAX_PW + 1];
};

//This structure called Account and has account number and accoun type.
struct  Account
{
    //An interger type that represents the account number associated to customer.
    int accountNum;
    //A single character type that represents the account type
    //A means customer service agent, C means customer.
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
