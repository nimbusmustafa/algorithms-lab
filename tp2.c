#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

int max(int a, int b){
    return (a>b)?a:b;
}

int height(struct node *root){
    if(root!=NULL)
    return max(height(root->lchild),height(root->rchild)) +1;
}

int balfac(struct node *root){
    if(root!=NULL)
    return( height(root->lchild)-height(root->rchild));
}

struct node *getnode(int data){
     struct node * newnode= (struct node *)malloc(sizeof(struct node));
     newnode->data=data;
     newnode->rchild=newnode->rchild=NULL;
     return newnode;
}

struct node *leftrotate(struct node *root){

    struct node * y=root->rchild;
    struct node * z=y->lchild;

    y->lchild=root;
    root->rchild=z;
    return y;
}

struct node *rightrotate(struct node *root){

    struct node * y=root->lchild;
    struct node * z=y->rchild;

    y->rchild=root;
    root->lchild=z;
    return y;
}

struct node *insertAVL(struct node *root, int data){
    if(root==NULL){
        root=getnode(data);
        return root;
    }

        if (data<root->data)
            root->lchild = insertAVL(root->lchild, data);
        else if (data>root->data)
            root->rchild = insertAVL(root->rchild, data);
        else
            return root;
int bal=balfac(root);
                if (bal > 1 && data < root->lchild->data)
        return rightrotate(root);
 
    if (bal < -1 && data > root->rchild->data)
        return leftrotate(root);

    if (bal > 1 && data > root->lchild->data) {
        root->lchild =  leftrotate(root->lchild);
        return rightrotate(root);
    }
 
    if (bal < -1 && data < root->rchild->data) {
        root->rchild = rightrotate(root->rchild);
        return leftrotate(root);
    }
    return root;
}

struct node * create_AVL(struct node * root,int data) {
    int x;
    root=getnode(data);
 
    while(1) {
        printf("enter element: ");
        scanf("%d",&x);
        if(x==-1)
            break;
        root=insertAVL(root,x);
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}
struct node * minValuenode(struct node* root) {
    struct node* current = root;
    while(current && current->lchild != NULL){
        current = current->lchild;
    }
    return current;
}

struct node * maxValuenode(struct node* root) {
    struct node* current = root;
    while(current && current->rchild != NULL){
        current = current->rchild;
    }
    return current;
}

int findSuccessor(struct node* root, int data) {
    struct node* current = root;
    struct node* successor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            successor = current;
            current = current->lchild;
        }
        else if (current->data < data) {
            current = current->rchild;
        }
        else {
            if (current->rchild != NULL) {
                successor = minValuenode(current->rchild);
            }
            break;
        }
    }
    return successor->data;
}

int findPredecessor(struct node* root, int data) {
    struct node* current = root;
    struct node* predecessor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            current = current->lchild;
        }
        else if(current->data < data){
            predecessor = current;
            current = current->rchild;
        }
        else{
            if (current->lchild != NULL){
                predecessor = maxValuenode(current->lchild);
            }
            break;
        }
    }
    return predecessor->data;
}
int main(){
    struct node *root = NULL;
    int a, key, succ, pre;
    printf("Root node : \n");
    do{
        printf("Input Value (Enter -1 to Exit): ");
        scanf(" %d",&a);
        if(a == -1){
        printf("Inorder traversal of AVL tree: ");
        inorder(root);
        }
        else{
            root = insertAVL(root, a);
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