#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node * rchild;
};

struct node * getnode() {
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

struct node * leftrotate(struct node * x) {
    struct node * y=x->rchild;
    struct node * z=y->lchild;

    y->lchild=x;
    x->rchild=z;

    return y;
}

struct node * rightrotate(struct node * x) {
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
        return rightrotate(root);
 
    if (bal < -1 && item > root->rchild->data)
        return leftrotate(root);

    if (bal > 1 && item > root->lchild->data) {
        root->lchild =  leftrotate(root->lchild);
        return rightrotate(root);
    }
 
    if (bal < -1 && item < root->rchild->data) {
        root->rchild = rightrotate(root->rchild);
        return leftrotate(root);
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

void preorder(struct node * root) {
    if(root) {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void main() {
    struct node * root=NULL;
    int data;
    printf("enter root: ");
    scanf("%d",&data);
    root=create_AVL(root,data);
    printf("\n");
    preorder(root);
    printf("\n");
}