#include <stdio.h>
#include "stack2.h"

int main(){
    int acc_sheet[100][4];
    printf("+---------------------------------------------------+");
    printf("|                Account Statement                  |");
    printf("+---------------------------------------------------+");
    int acc_number;
    printf("\nEnter Your account Number: ");
    scanf("%d", &acc_number);
    int date[100];
    int transactionID[100];
    int debit[100];
    int credit[100];
    int top_date = -1;
    int top_transactionID = -1;
    int top_debit = -1;
    int top_credit = -1;
    int counter_variable = 1;
    printf("Enter the current balance: ");
    int balance = 0;
    scanf("%d", &balance);
    while(counter_variable == 1){
        printf("Enter the transaction date: ");
        int transact_date = 0;
        scanf("%d", &transact_date);
        date[100],top_date = push(date, transact_date, top_date);
        printf("Enter the transaction ID: ");
        int transact_ID = 0;
        scanf("%d", &transact_ID);
        transactionID[100],top_transactionID = push(transactionID, transact_ID, top_transactionID);
        int opt;
        printf("Enter 1 for Debit, 2 for Credit: ");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            printf("Enter the amount to be debited: ");
            int debit_amt = 0;
            scanf("%d", &debit_amt);
            credit[100],top_credit = push(credit, 0, top_credit);
            debit[100],top_debit = push(debit, debit_amt, top_debit);
            break;
        case 2:
            printf("Enter the amount to be credited: ");
            int credit_amt = 0;
            scanf("%d", &credit_amt);
            credit[100],top_credit = push(credit, credit_amt, top_credit);
            debit[100],top_debit = push(debit, 0, top_debit);
            break;
        default:
            printf("Invalid Choice");
            break;
        }
        printf("Do you want to enter a new transaction? Enter 1 for Yes, 0 for No: ");
        scanf("%d", &counter_variable);
        switch (counter_variable){
        case 1:
            continue;
        case 0:
            break;
        }
    }
}
