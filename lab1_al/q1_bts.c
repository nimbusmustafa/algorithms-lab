#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} bst;

bst *root = NULL;
bst *searched;
int flag=0;

bst *create(bst *root1, int item)
{
    if (root1 == NULL)
    {
        root1 = (bst *)malloc(sizeof(bst));
        root1->data = item;
        root1->left = root1->right = NULL;
        return root1;
    }

    else if (item < root1->data)
    {
        root1->left = create(root1->left, item);
    }
    else if (item > root1->data)
    {
        root1->right = create(root1->right, item);
    }
    else
    {
        printf("Key Found\n");
        flag=1;
    }
    return root1;
}

void inorder(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main()
{
    int input, data;
    while (input != -1)
    {
        printf("Enter 1 to insert or 2 to display in-order traversal (-1 to exit): ");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("enter data: ");
            scanf("%d", &data);
            root = create(root, data);
            if(flag==0)
            printf("\nInserted %d successfully.\n", data);
            flag=0;
        }
        else if (input == 2)
        {
            printf("\nIn-Order Traversal:\n");
            inorder(root);
            printf("\n");
        }
    }
}