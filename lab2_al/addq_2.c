#include <stdio.h>

void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}
