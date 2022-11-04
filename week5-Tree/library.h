#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *constructTreeUtil(int pre[], int *preIndex, int low, int high, int size){
    if (*preIndex >= size || low > high)
        return NULL;
    struct node *root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
    if (low == high)
        return root;
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
    root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);
    return root;
}

void input(char s[]){
    FILE *fptr;
    int i;
    char d[100];

    fptr = fopen(s, "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter data: ");
    fgets(d, 100, stdin);

    for (i = 0; i < d[i]; i++)
        fputc(d[i], fptr);
    fclose(fptr);
}
struct node *constructTree(int pre[], int size){
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1, size);
}
void printInorder(struct node *node){
    FILE *fptr;
    fptr = fopen("output.txt", "w");
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    fprintf(fptr, "%c ", node->data);
    printInorder(node->right);
    fclose(fptr);
}