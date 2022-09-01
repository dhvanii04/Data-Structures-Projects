#include<stdio.h>
#include<string.h>
void display()
{
    struct menu
    {
        int w;              //index
        int x;              //x=price
        int y;              //y=time
        char z[35];         //z=item name
    };
    struct menu m1 = {0,300,20,"Dal Makhani"};
    struct menu m2 = {1,235,10,"Naan"};
    struct menu m3 = {2,220,12,"Chhole Kulcha"};
    struct menu m4 = {3,215,14,"Pav Bhaji"};
    struct menu m5 = {4,260,18,"Gulab Jamun"};
    struct menu m6 = {5,180,10,"Iced Tea"};
    printf("                Welcome to our Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf(" Please enter code of the food you would like to purchase \n");
    printf("[%d] %s - Rs %d \n", m1.w, m1.z, m1.x);
    printf("[%d] %s - Rs %d \n", m2.w, m2.z, m2.x);
    printf("[%d] %s - Rs %d \n", m3.w, m3.z, m3.x);
    printf("[%d] %s - Rs %d \n", m4.w, m4.z, m4.x);
    printf("[%d] %s - Rs %d \n", m5.w, m5.z, m5.x);
    printf("[%d] %s - Rs %d \n", m6.w, m6.z, m6.x);
}