//Library to accoomodate the linked list functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//Structure to hold the data
struct node
{
    int data;
    struct node *next;
};

//Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a new node at the beginning of the list
struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

//Function to insert a new node at the end of the list
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//Function to insert a new node at a given position
struct node *insertAtPosition(struct node *head, int data, int position)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

//Function to delete a node from the beginning of the list
struct node *deleteFromBeginning(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

//Function to delete a node from the end of the list
struct node *deleteFromEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

//Function to delete a node from a given position
struct node *deleteFromPosition(struct node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    if (position == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

//Function to print the list
void printList(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Function to reverse the list
struct node *reverseList(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//Function to find the middle element of the list
void findMiddle(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is %d", slow->data);
}

//Function to find the nth element from the end of the list
void findNthFromEnd(struct node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count < n)
    {
        printf("Invalid position");
        return;
    }
    temp = head;
    for (int i = 0; i < count - n; i++)
    {
        temp = temp->next;
    }
    printf("Element at position %d from end is %d", n, temp->data);
}

//Function to find the nth element from the beginning of the list
void findNthFromBeginning(struct node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    printf("Element at position %d from beginning is %d", n, temp->data);
}

//Function to find the number of times a given integer occurs in the list
void findOccurences(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            count++;
        }
        temp = temp->next;
    }
    printf("Number of times %d occurs is %d", data, count);
}

//Function to find the number of nodes in the list
void findLength(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Length of the list is %d", count);
}

//Function to check if the list is empty
void isEmpty(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("List is not empty");
}

//Function to check if the list is sorted
void isSorted(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            printf("List is not sorted");
            return;
        }
        temp = temp->next;
    }
    printf("List is sorted");
}

//Function to remove duplicates from the list
struct node *removeDuplicates(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            struct node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

//Function to check if the list is a palindrome
void isPalindrome(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node *prev = NULL;
    struct node *current = slow;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    struct node *temp1 = head;
    struct node *temp2 = prev;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            printf("List is not a palindrome");
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    printf("List is a palindrome");
}

//Function to remove the nth node from the end of the list
struct node *removeNthFromEnd(struct node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count < n)
    {
        printf("Invalid position");
        return head;
    }
    temp = head;
    for (int i = 0; i < count - n - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

//Function to remove the nth node from the beginning of the list
struct node *removeNthFromBeginning(struct node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *temp = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

//Function to reverse the list
struct node *reverse(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
