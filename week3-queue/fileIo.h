#include<stdio.h>

void fileIo(int a[],int b[],int c[]) {
    FILE *fp;
    fp=fopen("file.txt","w");
    fprintf(fp,"Question1A,Question1B,Question1c");
    for(int i=0;i<9;i++) {
        fprintf(fp,"%d,%d,%d",a[i],b[i],c[i]);
    }
    
}
