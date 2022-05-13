/*
Assignment #1 Milestone #4
Min Young Choe
ID : 133607218 Email:mchoe@myseneca.ca
IPC144/ZBB
*/

#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_

#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"

void displayAccountDetailHeader(void);
void displayAccountDetailRecord(const struct Account* account);
void applicationStartup(struct Account accounts[], int arrSize);
int menuLogin(const struct Account accounts[], int arrSize);
void menuAgent(struct Account accounts[], int arrSize, const struct Account* account);
int findAccountIndexByAcctNum(int accountNum, const struct Account accounts[], int maxNum, int isPrompt);
void displayAllAccountDetailRecords(const struct Account accounts[], int maxNum);
// Pause execution until user enters the enter key
void pauseExecution(void);


#endif /* accountTicketingUI_h */
