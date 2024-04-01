#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int depth;
};
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->depth = 1;
    return node;
}
int depth(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->depth;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->depth = max(depth(y->left), depth(y->right)) + 1;
    x->depth = max(depth(x->left), depth(x->right)) + 1;
    return x;
}
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->depth = max(depth(x->left), depth(x->right)) + 1;
    y->depth = max(depth(y->left), depth(y->right)) + 1;
    return y;
}
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return depth(N->left) - depth(N->right);
}
struct Node *insert(struct Node *node, int data) {
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->depth = 1 + max(depth(node->left), depth(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct Node * minValueNode(struct Node* node) {
    struct Node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}
int findSuccessor(struct Node* root, int data) {
    struct Node* current = root;
    struct Node* successor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            successor = current;
            current = current->left;
        }
        else if (current->data < data) {
            current = current->right;
        }
        else {
            if (current->right != NULL) {
                successor = minValueNode(current->right);
            }
            break;
        }
    }
    return successor->data;
}
struct Node *maxValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL){
        current = current->right;
    }
    return current;
}
int findPredecessor(struct Node* root, int data) {
    struct Node* current = root;
    struct Node* predecessor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            current = current->left;
        }
        else if(current->data < data){
            predecessor = current;
            current = current->right;
        }
        else{
            if (current->left != NULL){
                predecessor = maxValueNode(current->left);
            }
            break;
        }
    }
    return predecessor->data;
}
int main(){
    struct Node *root = NULL;
    int a, key, succ, pre;
    printf("Root Node : \n");
    do{
        printf("Input Value (Enter -1 to Exit): ");
        scanf(" %d",&a);
        if(a == -1){
        printf("Inorder traversal of AVL tree: ");
        inorder(root);
        }
        else{
            root = insert(root, a);
        }
    }while(a != -1);
    printf("\nInput Value to find Successor and Predecessor : ");
    scanf(" %d",&key);
    succ = findSuccessor(root, key);
    pre = findPredecessor(root, key);
    printf("Successor of %d : %d\n",key,succ);
    printf("Predecessor of %d : %d\n",key,pre);
    return 0;
}