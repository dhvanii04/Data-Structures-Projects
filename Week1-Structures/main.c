#include <stdio.h>
#include <string.h>
#include <math.h>
#include "displaymenu.h"
#include "printBill.h"
#include "fileIO.h"

int qty0=0, qty1=0, qty2=0, qty3=0, qty4=0, qty5=0;
int bill;

int main(){
    display();
    int tst = 1;
    while(tst==1){
        printf("Enter the code for the required dish: ");
        int code;
        scanf("%d", &code);
        switch (code){
            case 0:
                printf("Enter the quantity: ");
                scanf("%d", &qty0);
                break;
            case 1:
                printf("Enter the quantity: ");
                scanf("%d", &qty1);
                break;
            case 2:
                printf("Enter the quantity: ");
                scanf("%d", &qty2);
                break;
            case 3:
                printf("Enter the quantity: ");
                scanf("%d", &qty3);
                break;
            case 4:
                printf("Enter the quantity: ");
                scanf("%d", &qty4);
                break;
            case 5:
                printf("Enter the quantity: ");
                scanf("%d", &qty5);
                break;
        }
        if(code>5){
            printf("Please enter a valid value!!");
        }
        else{
            printf("Do you want to order more? (Yes[1]/No[0]) - ");
            int resp;
            scanf("%d", &resp);
            if(resp == 0){
                printInvoice(qty0,qty1,qty2,qty3,qty4,qty5);
                fileIO(qty0,qty1,qty2,qty3,qty4,qty5);
                break;
            }
            else if (resp > 1){
                printf("Please enter a valid value!!");
            }
        }
    }
}
