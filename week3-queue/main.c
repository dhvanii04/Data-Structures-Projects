#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue1.h"
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
    printf("-----------------------------")
    printf("Rating for questions are:")
    printf("|\nQuestion 1A\t\tQuestion 1B\t\tQuestion 3\n|")
    for(int i=0;i<users;i++){
        printf("|%d\t\t%d\t\t%d|\n",a[100],b[100],c[100]);
    }
    printf("---------------------------------------------")
}
    
// {  
//     int a[100];
    
//     int choice;
//     printf("Enter the number of elements in the queue : ");
//     scanf("%d",&n);
//     printf("Enter the elements in the queue : "); 
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//         rear++;
//     }
//     printf("The elements in the queue are : ");
//     for(i=front;i<rear;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     printf(" ");
//     printf("Enter 1 to insert an element in the queue :  ");
//     printf("Enter 2 to delete an element from the queue :  ");
//     printf("Enter 3 to display the elements in the queue :  ");
//     printf("Enter 4 to exit :  ");
//     scanf("%d",&choice);
//     while(choice!=4)
//     {
//         switch(choice)
//         {
//             case 1:
//             {
//                 int x;
//                 printf("Enter the element to be inserted : ");
//                 scanf("%d",&x);
//                 a[rear]=x;
//                 rear++;
//                 printf("The elements in the queue are : ");
//                 for(i=front;i<rear;i++)
//                 {
//                     printf("%d ",a[i]);
//                 }
//                 printf(" ");
//                 break;
//             }
//             case 2:
//             {
//                 printf("The element deleted is %d ",a[front]);
//                 front++;
//                 printf("The elements in the queue are : ");
//                 for(i=front;i<rear;i++)
//                 {
//                     printf("%d ",a[i]);
//                 }
//                 printf(" ");
//                 break;
//             }
//             case 3:
//             {
//                 printf("The elements in the queue are : ");
//                 for(i=front;i<rear;i++)
//                 {
//                     printf("%d ",a[i]);
//                 }
//                 printf(" ");
//                 break;
//             }
//             default:
//             {
//                 printf("Invalid choice ");
//                 break;
            
//             }
//         }
//         if(front==-1 && rear==-1)
//         {
//             printf("queue is empty");
//         }

//         printf("Enter 1 to insert an element in the queue : \n");
//         printf("Enter 2 to delete an element from the queue : \n");
//         printf("Enter 3 to display the elements in the queue : \n");
//         printf("Enter 4 to exit : ");
//         scanf("%d",&choice);
//     }
    
// }