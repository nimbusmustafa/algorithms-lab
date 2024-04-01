#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
    int key,val;
    struct node * next;
} Node;

void insertList(Node ** list, int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->key = x;
    Node * prev = NULL;
    Node * iter = *list;

    while (iter != NULL && iter -> key < x ) {
        prev = iter;
        iter = iter->next;
    }
    if (prev == NULL) {
        new->next = *list;
        *list = new;
    }
    else {
        new->next = prev->next;
        prev->next = new;
    }
}

void insertHashTable(Node * hashTable[], int x, int m) {
    int key = x % m;
    insertList(&(hashTable[key]),x);
}

int getHashTable(Node * hashTable[], int x, int m) {
    int key = x % m, count = 0;
    Node * iter = hashTable[key];
    while (iter != NULL) {
        count++;
        if (iter->key == x) 
            return count;
        if (iter->key > x)
            return -count;
        iter = iter -> next;
    }
    return -count;
}


void main() {
    int m,n;
    printf("enter m and n\n");
    scanf("%d%d", &m,&n);
    Node * hashTable[m];
    int i, x, comparisonsSuccess = 0, comparisonsFail = 0, countSuccess = 0, countFail = 0;
    time_t t;
    srand((unsigned) time(&t));

    for (i = 0; i < m; i++) 
        hashTable[i] = NULL;


    for(i = 0; i < n; i++) {
        x = rand() % 100;
        insertHashTable(hashTable, x,m);
    }
    
    for(i = 0; i < n; i++) {
        x = rand() % 100;
        x = getHashTable(hashTable, x,m);
        if (x < 0) {
            comparisonsFail += -x;
            countFail++;
        }
        else {
            comparisonsSuccess += x;
            countSuccess++;
        }
    }
    
    if (countSuccess == 0 || countFail == 0)
        printf("Please rerun");
    else
        printf("Average number of key comparisons in successful search: %d\nAverage number of key comparisons in unsuccessful search: %d\n",(comparisonsSuccess/countSuccess),(comparisonsFail/countFail));

}