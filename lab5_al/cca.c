#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} bt;

bt* create() {
    int x;
    printf("Enter data (or -1 for NULL): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    bt* newnode = (bt*)malloc(sizeof(bt));
    newnode->data = x;

    printf("Enter left child of %d:\n", x);
    newnode->left = create();

    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

void inorder(bt* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

bt* findCCA(bt* root, int n1, int n2, int* nodeCount) {
    if (root == NULL) {
        return NULL;
    }

    (*nodeCount)++; 

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    bt* leftCCA = findCCA(root->left, n1, n2, nodeCount);
    bt* rightCCA = findCCA(root->right, n1, n2, nodeCount);

    if (leftCCA != NULL && rightCCA != NULL) {
        return root;
    }

    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

int main() {
    printf("Create Binary Tree:\n");
    bt* root = create();

    printf("\nInorder Traversal:\n");
    inorder(root);

    int node1, node2;
    printf("\nEnter two nodes for which you want to find the Closest Common Ancestor: ");
    scanf("%d %d", &node1, &node2);

    int nodeCount = 0;
    bt* cca = findCCA(root, node1, node2, &nodeCount);

    if (cca != NULL) {
        printf("Closest Common Ancestor of %d and %d is: %d\n", node1, node2, cca->data);
        printf("Number of nodes visited: %d\n", nodeCount);
    } else {
        printf("No Common Ancestor found\n");
    }

    return 0;
}
