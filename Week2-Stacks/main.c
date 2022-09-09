#include <stdio.h>
#include "stack.h"
#include "fileIO.h"
#include "accStat.h"
#include "popRecords.h"

int main(){
    printf("+---------------------------------------------------+\n");
    printf("|                Account Statement                  |\n");
    printf("+---------------------------------------------------+\n");
    int acc_number;
    printf("\nEnter Your account Number: ");
    scanf("%d", &acc_number);
    int date[100];
    int transactionID[100];
    int debit[100];
    int credit[100];
    int top_date = 0;
    int top_transactionID = 0;
    int top_debit = 0;
    int top_credit = 0;
    int counter_variable = 1;
    printf("\nEnter the current balance: ");
    int balance = 0;
    scanf("%d", &balance);
    while(counter_variable == 1){
        printf("\nEnter the transaction date: ");
        int transact_date = 0;
        scanf("%d", &transact_date);
        date[100],top_date = push(date, transact_date, top_date);
        printf("\nEnter the transaction ID: ");
        int transact_ID = 0;
        scanf("%d", &transact_ID);
        transactionID[100],top_transactionID = push(transactionID, transact_ID, top_transactionID);
        int opt;
        printf("\nEnter 1 for Debit, 2 for Credit: ");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            printf("\nEnter the amount to be debited: ");
            int debit_amt = 0;
            scanf("%d", &debit_amt);
            credit[100],top_credit = push(credit, 0, top_credit);
            debit[100],top_debit = push(debit, debit_amt, top_debit);
            break;
        case 2:
            printf("\nEnter the amount to be credited: ");
            int credit_amt = 0;
            scanf("%d", &credit_amt);
            credit[100],top_credit = push(credit, credit_amt, top_credit);
            debit[100],top_debit = push(debit, 0, top_debit);
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
        printf("\nDo you want to enter a new transaction? Enter 1 for Yes, 0 for No: ");
        scanf("%d", &counter_variable);
        switch (counter_variable){
        case 1:
            continue;
        case 0:
            break;
        }
    }

    fileWrite(date, transactionID, debit, credit, top_date, balance);
    fileWritetxt(date, transactionID, debit, credit, top_date, acc_number, balance);
    accStat(acc_number, balance, debit, credit, transactionID, date, top_date);
    popRecords(date, top_date);
    popRecords(transactionID, top_transactionID);
    popRecords(debit, top_debit);
    popRecords(credit, top_credit);
    return 0;
}
