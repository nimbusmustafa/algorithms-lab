#include <stdio.h>
#include <string.h>

void main() {
    char s1[50], s2[50];
    int i, j, ind, flag = 0;
    
    printf("Enter string 1: ");
    fgets(s1, sizeof(s1), stdin);
    
    printf("Enter string 2: ");
    fgets(s2, sizeof(s2), stdin);
    
    for (i = 0; i < strlen(s1) - strlen(s2) + 1; i++) {
        for (ind = 0; ind < strlen(s2); ind++) {
            if (s2[ind] != s1[i + ind])
                break;
        }
        if (ind == strlen(s2))
            break;
    }
    if (ind == strlen(s2))
        printf("Substring is at index %d. Count : %d", i, i + ind);
    else
        printf("String 1 does not have substring 2. Count : %d", i);
}
