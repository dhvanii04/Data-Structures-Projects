#include<stdio.h>
//queue library
  
int enqueue(int a[100], int data, int rear)
{  
    a[rear] = data;
    rear++;
    return a[rear-1], rear;
}
int dequeue(int a[100], int front)
{
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        a[front] = 0;
        front++;
        return front;
    }
}
     
