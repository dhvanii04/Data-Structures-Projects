#include<stdio.h>

// priority queue library
void create(); 
void enqueue(int data);
void check(int data);
void display();
 
int pri_que[100];
int front, rear;
float sum;
  
// Function to create an empty priority queue
void create()
{
    front = rear = -1;
}
 
// Function to insert value into priority queue
void enqueue(int data)
{
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
 
// Function to check priority and place element 
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
 
// Function to display queue elements 
void display()
{
    for (; front <= rear; front++)
    {
        printf(" %d\n", pri_que[front]);
        sum=sum+pri_que[front];
    }
    front = 0;
}
