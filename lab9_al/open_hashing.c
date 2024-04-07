#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    struct Node *next;
} Node;

void initializeHashTable(Node *hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(Node *hashTable[], int key) {
    int index = key % SIZE;

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
int search(Node *hashTable[], int key, int *numComparisons) {
    int index = key % SIZE;
    *numComparisons = 0;

    Node *current = hashTable[index];
    while (current != NULL) {
        (*numComparisons)++;
        if (current->key == key) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

void displayHashTable(Node *hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d:", i);
        Node *current = hashTable[i];
        while (current != NULL) {
            printf(" %d", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node *hashTable[SIZE];
    initializeHashTable(hashTable);

    int numKeys;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    printf("Enter %d keys:\n", numKeys);
    for (int i = 0; i < numKeys; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, key);
    }

  displayHashTable(hashTable);
    int keyToSearch;
    printf("Enter key to search: ");
    scanf("%d", &keyToSearch);
    
    int comparisons = 0;
    int found = search(hashTable, keyToSearch, &comparisons);
    if (found) {
        printf("Key found. Total comparisons: %d\n", comparisons);
    } else {
        printf("Key not found. Total comparisons: %d\n", comparisons);
    }

    return 0;
}