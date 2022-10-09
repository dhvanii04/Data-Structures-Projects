#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
 
int front, rear;
 
int main()
{
    int s;

    printf("+-------------------------------------------------+\n");
    printf("|                     DSA Quiz                    |\n");
    printf("+-------------------------------------------------+\n");
    
    printf("\nHow many Candidates are there for quiz : ");
    scanf("%d",&s);

    int c[s];
    char name[10];
    int ans;
    int score=0;
    int pri_que[s];
    float avg;

    create(); 

    for(int i=0;i<s;i++)
    {
        c[i]=0;
        printf("\n+-------------------------------------------------+\n");
        printf("\n%d. Enter the name : ",i+1);
        scanf("%s",name);
        
        printf("\nAnswer the following True/False. \n(1 for True, 0 for False)\n(Maximum marks = 3)\n");
        
        printf("\nQ1. AB+C-D/ is the Postfix expression of (A+B-C)/D : ");
        scanf("%d",&ans);
        if(ans==1)
        c[i]++;
        
        printf("\nQ2. Stack works on FIFO principle : ");
        scanf("%d",&ans);
        if(ans==0)
        c[i]++;
        
        printf("\nQ3. If top=0 then Stack is empty : ");
        scanf("%d",&ans);
        if(ans==0)
        c[i]++;
        
        printf("\n||Final Score of %s is : %d|| \n",name,c[i]);
        score=c[i];
        
        enqueue(score);
    }

    printf("\n+-------------------------------------------------+\n");

    printf("\nFinal Scores of Candidates from Highest to Lowest : \n");
    display();

    avg=sum/s;
    printf("\nAverage Score of Candidates is : %f\n",avg); 
}
 
