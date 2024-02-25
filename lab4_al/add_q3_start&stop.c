#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10
#define NO_CONNECTION -1

int calculateTotalDistance(int tour[], int numCities, int distances[MAX_CITIES][MAX_CITIES]) {
    int totalDistance = 0;
    for (int i = 0; i < numCities - 1; ++i) {
        if (distances[tour[i]][tour[i + 1]] != NO_CONNECTION) {
            totalDistance += distances[tour[i]][tour[i + 1]];
        }
    }
    if (distances[tour[numCities - 1]][tour[0]] != NO_CONNECTION) {
        totalDistance += distances[tour[numCities - 1]][tour[0]]; // Return to the starting city
    }
    return totalDistance;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int tour[], int numCities, int distances[MAX_CITIES][MAX_CITIES], int *minDistance, int *bestTour, int startCity, int goalCity) {
    if (numCities == 1) {
        int currentDistance = calculateTotalDistance(tour, 1, distances);
        if (currentDistance < *minDistance && tour[0] == startCity && tour[0] == goalCity) {
            *minDistance = currentDistance;
            bestTour[0] = tour[0];
        }
    } else {
        for (int i = 0; i < numCities; ++i) {
            swap(&tour[0], &tour[i]);
            generatePermutations(tour + 1, numCities - 1, distances, minDistance, bestTour, startCity, goalCity);
            swap(&tour[0], &tour[i]);
        }
    }
}

int main() {
    int numCities, startCity, goalCity;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    if (numCities > MAX_CITIES) {
        printf("Number of cities exceeds the maximum limit.\n");
        return 1;
    }

    int distances[MAX_CITIES][MAX_CITIES];

    // Initialize distances to NO_CONNECTION
    for (int i = 0; i < MAX_CITIES; ++i) {
        for (int j = 0; j < MAX_CITIES; ++j) {
            distances[i][j] = NO_CONNECTION;
        }
    }

    printf("Enter the distances between connected cities (use -1 for no connection):\n");
    for (int i = 0; i < numCities; ++i) {
        for (int j = i + 1; j < numCities; ++j) {
            printf("Distance from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &distances[i][j]);
            distances[j][i] = distances[i][j]; 
        }
    }

    int tour[MAX_CITIES];
    int minDistance = INT_MAX;
    int bestTour[MAX_CITIES];

    for (int i = 0; i < numCities; ++i) {
        tour[i] = i;
    }

    printf("Enter the start city: ");
    scanf("%d", &startCity);

    printf("Enter the goal city: ");
    scanf("%d", &goalCity);

    generatePermutations(tour, numCities, distances, &minDistance, bestTour, startCity, goalCity);

    printf("Best Tour: ");
    for (int i = 0; i < numCities; ++i) {
        printf("%d ", bestTour[i]);
    }
    printf("\nMinimum Distance: %d\n", minDistance);

    return 0;
}
