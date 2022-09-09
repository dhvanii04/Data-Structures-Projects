#include <stdio.h>

void fileWrite(int date[100], int transactionID[100], int debit[100], int credit[100], int top_date, int balance){
    FILE *fp;
    fp = fopen("file.csv", "w");
    fprintf(fp, "Date, Transaction ID, Debit, Credit, Balance \n");
    for(int i = 0; i < top_date; i++){
        balance = balance - debit[i] + credit[i];
        fprintf(fp, "%d,%d,%d,%d,%d\n", date[i], transactionID[i], debit[i], credit[i], balance);
    }
}

void fileWritetxt(int date[100], int transactionID[100], int debit[100], int credit[100], int top_date, int acc_number, int balance){
    FILE *fptr;
    fptr = fopen("file.txt", "w");
    fprintf(fptr, "\nAccount Number: %d \n", acc_number);
    fprintf(fptr, "Opening Balance: %d \n", balance);
    fprintf(fptr, "+------------------------------------------------------------------------------+\n");
    fprintf(fptr, "|\nDate\t\tTransaction ID\t\tDebit\t\tCredit\t\tBalance \n|");
    fprintf(fptr, "+------------------------------------------------------------------------------+\n");
    for(int i = 0; i < top_date; i++){
        balance = balance - debit[i] + credit[i];
        fprintf(fptr, "|%d\t\t%d\t\t%d\t\t%d\t\t%d\n|", date[i], transactionID[i], debit[i], credit[i], balance);
    }
    fprintf(fptr, "+------------------------------------------------------------------------------+\n");
}
