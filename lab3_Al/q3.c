#include <stdio.h>
#include <stdbool.h>

int calculateArraySum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

bool subsetSumUtil(int ind, int target, int arr[] ) {
    if (target == 0) {
       
        return true;
    }

    if (ind == 0) {
        if (arr[0] == target) {
            return true;
        } else {
            return false;
        }
    }

    bool notTaken = subsetSumUtil(ind - 1, target, arr);

    bool taken = false;
    if (arr[ind] <= target) {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr  );
    }

    return notTaken || taken;
}

bool partitionIntoTwoEqualSubsets(int n, int arr[]) {
    int totalSum = calculateArraySum(arr, n);
    if (totalSum % 2 != 0) {
        return false;
    }
    int targetSum = totalSum / 2;

    if (!subsetSumUtil(n - 1, targetSum, arr)) {
        return false; 
    }

   
    return true;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (!partitionIntoTwoEqualSubsets(n, arr))
        printf("No such subsets found\n");
        else printf("partitions found");

    return 0;
}
