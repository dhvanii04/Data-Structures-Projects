#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// A structure to represent a stack
struct Stack {
    int top;
    int size_of_stack;
    int* arr;
};
  
//function to initialize stack 
struct Stack* createStack(int size_of_stack)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size_of_stack = size_of_stack;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size_of_stack * sizeof(int));
    return stack;
}
  
// Stack is full when top=size_of_stack-1
int isFull(struct Stack* stack)
{
    return stack->top == stack->size_of_stack - 1;
}
  
// Stack is empty when top=-1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
  
// Function to push an value to stack.  It increases top by 1
void push(struct Stack* stack, int value)
{
    if (isFull(stack))
        return;
    stack->arr[++stack->top] = value;
    printf("%d pushed\n", value);
}
  
// Function to remove an value from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return 1;
    return stack->arr[stack->top--];
  
}
  
// Function to print the top value of stack(peek)
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return 1;
    return stack->arr[stack->top];
}
