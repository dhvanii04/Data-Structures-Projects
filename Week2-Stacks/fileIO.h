#include <stdio.h>

void fileWrite(int date[100], int transactionID[100], int debit[100], int credit[100], int top_date){
    FILE *fp;
    fp = fopen("file.csv", "w");
    fprintf(fp, "Date, Transaction ID, Debit, Credit, Balance \n");
    int balance = 0;
    for(int i = 0; i < top_date; i++){
        balance = balance - debit[i] + credit[i];
        fprintf(fp, "%d,%d,%d,%d,%d\n", date[i], transactionID[i], debit[i], credit[i], balance);
    }
}