#include<stdio.h>
//queue library
int capacity;
  int a[capacity];
    int front=0;
    int rear=0;
    int choice;
void enqueue(int x)
{
    if(rear==capacity-1)
    {
        printf("Queue is full");
    }
    else
    {
        a[rear]=x;
        rear++;
    }
}

void dequeue()
{
   if (front==0 || front>rear)
   {
       printf("Queue is empty");
   }
   else
   {
       front++;
   if(front>rear)
   {
       front=rear=0;
   }
   }

void display()
{ if(rear==0)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<rear;i++)
        {
            printf("%d ",a[i]);
        }
    }
}
