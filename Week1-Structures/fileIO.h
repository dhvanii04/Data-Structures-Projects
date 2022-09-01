#include <stdio.h>

void exportTotext(int qty0, int qty1, int qty2, int qty3, int qty4, int qty5){
    time_t t;
    time(&t);
    FILE *fptr;
    int bill = 300*qty0 + 235*qty1 + 220*qty2 + 215*qty3 + 260*qty4 + 180*qty5;
    fopen("C:\\Users\\Dell\\DS-Projects\\Week1-Structures\\bill.txt", "w+");
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
    fprintf(fptr,"|                              INVOICE                              |\n");
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
    fprintf(fptr,"| Time: %s                                    |\n", ctime(&t));
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
    fprintf(fptr,"| Name                         | Quantity           | Cost          |\n");
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
    if(qty0!=0){
        fprintf(fptr,"| Dal Makhani                  | %d                 | %d            |\n", qty0, 300*qty0);
    }
    if(qty1!=0){
        fprintf(fptr,"| Naan                         | %d                 | %d            |\n", qty1, 235*qty1);
    }
    if(qty2!=0){
        fprintf(fptr,"| Chhole Kulcha                | %d                 | %d            |\n", qty2, 220*qty2);
    }
    if(qty3!=0){
        fprintf(fptr,"| Pav Bhaji                    | %d                 | %d            |\n", qty3, 215*qty3);
    }
    if(qty4!=0){
        fprintf(fptr,"| Gulab Jamun                  | %d                 | %d            |\n", qty4, 260*qty4);
    }
    if(qty5!=0){
        fprintf(fptr,"| Iced Tea                     | %d                 | %d            |\n", qty5, 180*qty5);
    }
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
    fprintf(fptr,"|                                       TOTAL COST: | %d           |\n", bill);
    fprintf(fptr,"+-------------------------------------------------------------------+\n");
}
