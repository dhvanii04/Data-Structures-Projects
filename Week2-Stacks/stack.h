#include <stdio.h>

int push(int arr[100], int data, int top)
{
    arr[top] = data;
    top++;
    return arr[100], top;
}

int pop(int arr[100], int top)
{
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        arr[top] = 0;
        top--;
        return arr[100], top;
    }
}

int peek(int arr[100], int top)
{
    return arr[top - 1];
}
