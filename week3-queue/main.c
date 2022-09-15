#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"
int main(){
    printf("+---------------------------------------------------+\n");
    printf("|                CodeForces Ranking System                 |\n");
    printf("+---------------------------------------------------+\n");
int capacity;

int front=0;
    int rear=0;
    char name[20];
    int roll_no;
    printf("Enter the number of participants: \n");
    scanf("%d", &capacity);
int a[capacity];
int b[capacity];
int i;
for(i=0; i<capacity; i++){
    
    printf("Enter your name: \n");
    gets(name);

    printf("Enter your roll number: \n");
    scanf("%d", &roll_no);

    insq(a, &rear, name);
}
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