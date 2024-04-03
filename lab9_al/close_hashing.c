#include <stdio.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
} Entry;

void initializeTable(Entry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1; // Initialize all keys to -1 (indicating empty)
    }
}

void insert(Entry table[], int key) {
    int index = key % TABLE_SIZE;
    int i = index;
    while (table[i].key != -1) {
        i = (i + 1) % TABLE_SIZE; // Linear probing
        if (i == index) {
            printf("Hash table is full. Unable to insert key %d\n", key);
            return;
        }
    }
    table[i].key = key;
}

int search(Entry table[], int key, int *comparisons) {
    int index = key % TABLE_SIZE;
    int i = index;
    while (table[i].key != -1) {
        (*comparisons)++;
        if (table[i].key == key) {
            return 1; // Found
        }
        i = (i + 1) % TABLE_SIZE; // Linear probing
        if (i == index) {
            break; // Reached original index, meaning key is not present
        }
    }
    return 0; // Not found
}

void displayTable(Entry table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (table[i].key != -1) {
            printf("%d", table[i].key);
        }
        printf("\n");
    }
}

int main() {
    Entry table[TABLE_SIZE];
    int numKeys, keyToSearch;

    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    initializeTable(table);

    printf("Enter %d keys:\n", numKeys);
    for (int i = 0; i < numKeys; i++) {
        int key;
        scanf("%d", &key);
        insert(table, key);
    }

    printf("Enter the key to search: ");
    scanf("%d", &keyToSearch);

    int totalSuccessComparisons = 0;
    int found = search(table, keyToSearch, &totalSuccessComparisons);
    if (found) {
        printf("Key found.\n");
    } else {
        printf("Key not found.\n");
    }

    printf("Number of key comparisons in successful search: %d\n", totalSuccessComparisons);

    // Display the hash table
    displayTable(table);

    return 0;
}
