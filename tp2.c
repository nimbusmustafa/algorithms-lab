#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *lchild;
    struct node* rchild;
}avl;

avl *getnode(){
    return((avl*)malloc(sizeof(avl)));
}
int max(int a, int b){
    return a>b?a:b;
}

int height(avl *root){
        if(root)

    return max(height(root->rchild),height(root->lchild))+1;
}

int balfac(avl *root){
    return height(root->lchild)-height(root->rchild);}

avl *leftrotate(avl *root){
    avl *y=root->rchild;
    avl *z= y->lchild;

    y->lchild=root;
    root->rchild=z;
    return y;
}


avl *rightrotate(avl *root){
    avl *y=root->lchild;
    avl *z= y->rchild;

    y->rchild=root;
    root->lchild=z;
    return y;
}

avl *insertAVL(avl *root, int item){
    if (!root) {
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    if (item<root->data)
            root->lchild = insertAVL(root->lchild, item);
        else if (item>root->data)
            root->rchild = insertAVL(root->rchild, item);
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


avl * create_AVL(avl* root,int data) {
    int x;
    root=getnode();
    root->data=data;
    root->lchild=root->rchild=NULL;
    while(1) {
        printf("enter element: ");
        scanf("%d",&x);
        if(x==-1)
            break;
        root=insertAVL(root,x);
    }
    return root;
}

void preorder(avl * root) {
    if(root) {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void main() {
    avl* root=NULL;
    int data;
    printf("enter root: ");
    scanf("%d",&data);
    root=create_AVL(root,data);
    printf("\n");
    preorder(root);
    printf("\n");
}
