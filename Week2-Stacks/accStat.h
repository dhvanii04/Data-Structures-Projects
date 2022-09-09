#include <stdio.h>

void accStat(int acc_number, int balance, int debit[100], int credit[100], int transactionID[100], int date[100], int top_date){
    printf("\nAccount Number: %d \n", acc_number);
    printf("Opening Balance: %d \n", balance);
    printf("+------------------------------------------------------------------------------+\n");
    printf("|\nDate\t\tTransaction ID\t\tDebit\t\tCredit\t\tBalance \n|");
    printf("+------------------------------------------------------------------------------+\n");
    for(int i = 0; i < top_date; i++){
        balance = balance - debit[i] + credit[i];
        printf("|%d\t\t%d\t\t%d\t\t%d\t\t%d|\n", date[i], transactionID[i], debit[i], credit[i], balance);
    }
    printf("+------------------------------------------------------------------------------+\n");
}