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
        printf("Duplicates not allowed");
    }
    return root1;
}

void inorder(bst *root1)
{
    if (root1 == NULL)
    {
        return;
    }
    else
    {
        inorder(root1->left);
        printf("%d\t", root1->data);
        inorder(root1->right);
    }
}

bst *search(bst *root1, int key)
{
    if (root1 == NULL)
    {
        return NULL;
    }
    else if (key == root1->data)
    {
        return root1;
    }
    else if (key < root1->data)
    {
        return search(root1->left, key);
    }
    else
    {
        return search(root1->right, key);
    }
}


int main()
{
    int input, data;
    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            printf("enter data: ");
            scanf("%d", &data);
            root = create(root, data);
            printf("%d", root->data);
        }

        else if (input == 2)
        {
            inorder(root);
        }
        else if (input == 3)
        {
            searched = search(root, 5);
            if (searched != NULL)
            {
                printf("Found %d", searched->data);
            }
            else
            {
                printf("not found");
            }
        }
        else
        {
            input == -1;
        }
    }
}