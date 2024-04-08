#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node * rchild;
};

struct node * getnode()  {
    return ((struct node *)malloc(sizeof(struct node)));
}

int max(int a,int b) {
    return a>b?a:b;
}

int height(struct node * root) {
    if(root)
        return max(height(root->lchild),height(root->rchild)) + 1;
}

int balfac(struct node * root) {
    return height(root->lchild)-height(root->rchild);
}

struct node * lchildrotate(struct node * x) {
    struct node * y=x->rchild;
    struct node * z=y->lchild;

    y->lchild=x;
    x->rchild=z;

    return y;
}

struct node * rchildrotate(struct node * x) {
    struct node * y=x->lchild;
    struct node * z=y->rchild;

    y->rchild=x;
    x->lchild=z;
    return y;
}

struct node * Insert_AVL(struct node * root,int item) {
    if (!root) {
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    if (item<root->data)
            root->lchild = Insert_AVL(root->lchild, item);
        else if (item>root->data)
            root->rchild = Insert_AVL(root->rchild, item);
        else
            return root;
    
    int bal=balfac(root);

    if (bal > 1 && item < root->lchild->data)
        return rchildrotate(root);
 
    if (bal < -1 && item > root->rchild->data)
        return lchildrotate(root);

    if (bal > 1 && item > root->lchild->data) {
        root->lchild =  lchildrotate(root->lchild);
        return rchildrotate(root);
    }
 
    if (bal < -1 && item < root->rchild->data) {
        root->rchild = rchildrotate(root->rchild);
        return lchildrotate(root);
    }
 
    return root;
}

struct node * create_AVL(struct node * root,int data) {
    int x;
    root=getnode();
    root->data=data;
    root->lchild=root->rchild=NULL;
    while(1) {
        printf("enter element: ");
        scanf("%d",&x);
        if(x==-1)
            break;
        root=Insert_AVL(root,x);
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
struct node * minValuenode(struct node* node) {
    struct node* current = node;
    while(current && current->lchild != NULL){
        current = current->lchild;
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
struct node *maxValuenode(struct node* node) {
    struct node* current = node;
    while (current && current->rchild != NULL){
        current = current->rchild;
    }
    return current;
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
            root = Insert_AVL(root, a);
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
