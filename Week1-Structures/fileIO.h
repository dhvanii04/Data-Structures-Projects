#include <stdio.h>
#include <time.h>

int fileIO(int qty0, int qty1, int qty2, int qty3, int qty4, int qty5){
    FILE* fp = fopen("file_path.csv", "a+");
    struct menu
    {
        int index;              //index
        int price;              //x=price
        int time;              //y=time
        char z[35];         //z=item name
    };
    struct menu m1 = {0,300,20,"Dal Makhani"};
    struct menu m2 = {1,235,10,"Naan"};
    struct menu m3 = {2,220,12,"Chhole Kulcha"};
    struct menu m4 = {3,215,14,"Pav Bhaji"};
    struct menu m5 = {4,260,18,"Gulab Jamun"};
    struct menu m6 = {5,180,10,"Iced Tea"};
    time_t t;
    time(&t);
    int bill = m1.price*qty0 + m2.price*qty1 + m3.price*qty2 + m4.price*qty3 + m5.price*qty4 + m6.price*qty5;
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    fprintf(fp, "|                              INVOICE                              |\n");
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    fprintf(fp, "| Time: %s                                    |\n", ctime(&t));
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    fprintf(fp, "| Name                         | Quantity           | Cost          |\n");
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    if(qty0!=0){
        fprintf(fp, "| Dal Makhani                  | %d                 | %d            |\n", qty0, m1.price*qty0);
    }
    if(qty1!=0){
        fprintf(fp, "| Naan                         | %d                 | %d            |\n", qty1, m2.price*qty1);
    }
    if(qty2!=0){
        fprintf(fp, "| Chhole Kulcha                | %d                 | %d            |\n", qty2, m3.price*qty2);
    }
    if(qty3!=0){
        fprintf(fp, "| Pav Bhaji                    | %d                 | %d            |\n", qty3, m4.price*qty3);
    }
    if(qty4!=0){
        fprintf(fp, "| Gulab Jamun                  | %d                 | %d            |\n", qty4, m5.price*qty4);
    }
    if(qty5!=0){
        fprintf(fp, "| Iced Tea                     | %d                 | %d            |\n", qty5, m6.price*qty5);
    }
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    fprintf(fp, "|                                       TOTAL COST: | %d           |\n", bill);
    fprintf(fp, "+-------------------------------------------------------------------+\n");
    fclose(fp);
}
