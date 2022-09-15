#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"
int main(){
    printf("+---------------------------------------------------+\n");
    printf("|                CodeForces Ranking System          |\n");
    printf("+---------------------------------------------------+\n");
int capacity;

int front=0;
    int rear=0;
    char name[20];
    int id;
int a[100];
int b[100];
int c[100];
int i;
int users=3;


while(users--){   //question 1 inputs
    printf("For submitting question 1A,please enter your id");
    scanf("%d",&id);
    a[100],rear=enqueue(a, id, rear);
    }
    
while(users--){ //question 2 inputs
printf("For submitting question 1B,please enter your id");
scanf("%d",&id);
b[100],rear=enqueue(b, id, rear);
}

while(users--){ //question 3 inputs
printf("For submitting question 1C,please enter your id");
scanf("%d",&id);
c[100],rear=enqueue(c, id, rear);
}

void Finalranks(int a[],int b[], int c[]){
    printf("-----------------------------");
    printf("Rating for questions are:");
    printf("|\nQuestion 1A\t\tQuestion 1B\t\tQuestion 3\n|");
    for(int i=0;i<users;i++){
        printf("|%d\t\t%d\t\t%d|\n",a[100],b[100],c[100]);
    }
    printf("---------------------------------------------");
}
}
