#include <stdio.h>
#include <time.h>


void printInvoice(int qty0, int qty1, int qty2, int qty3, int qty4, int qty5){
    time_t t;
    time(&t);
    int bill = 300*qty0 + 235*qty1 + 220*qty2 + 215*qty3 + 260*qty4 + 180*qty5;
    printf("+-------------------------------------------------------------------+\n");
    printf("|                              INVOICE                              |\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("| Time: %s                                    |\n", ctime(&t));
    printf("+-------------------------------------------------------------------+\n");
    printf("| Name                         | Quantity           | Cost          |\n");
    printf("+-------------------------------------------------------------------+\n");
    if(qty0!=0){
        printf("| Dal Makhani                  | %d                 | %d            |\n", qty0, 300*qty0);
    }
    if(qty1!=0){
        printf("| Naan                         | %d                 | %d            |\n", qty1, 235*qty1);
    }
    if(qty2!=0){
        printf("| Chhole Kulcha                | %d                 | %d            |\n", qty2, 220*qty2);
    }
    if(qty3!=0){
        printf("| Pav Bhaji                    | %d                 | %d            |\n", qty3, 215*qty3);
    }
    if(qty4!=0){
        printf("| Gulab Jamun                  | %d                 | %d            |\n", qty4, 260*qty4);
    }
    if(qty5!=0){
        printf("| Iced Tea                     | %d                 | %d            |\n", qty5, 180*qty5);
    }
    printf("+-------------------------------------------------------------------+\n");
    printf("|                                       TOTAL COST: | %d           |\n", bill);
    printf("+-------------------------------------------------------------------+\n");
}
void exportTOtext(qty0,qty1,qty2,qty3,qty4,qty5)
{
FILE *text;
int i;
text=fopen("Bill.txt","w");
fprintf(text,"food:%s\n price:%d\nMax time taken:",z[i].menu,x.menu,y.menu)
fclose(text);
}
