#include <stdio.h>

// function to sort items by value-to-weight ratio in decreasing order
void sortByRatio(int weights[], int values[], int n) {
    int i, j, temp;
    double ratio1, ratio2;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            ratio1 = (double)values[i] / weights[i];
            ratio2 = (double)values[j] / weights[j];
            if (ratio1 < ratio2) {
                // swap weights
                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
                // swap values
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

// function to solve fractional knapsack problem and print the items added
double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    sortByRatio(weights, values, n);
    double totalValue = 0;
    int i;

    printf("Items added:\n");
    for (i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        }
        if (weights[i] <= capacity) {
            totalValue += values[i];
            capacity -= weights[i];
            printf("Item %d: weight = %d, value = %d\n", i + 1, weights[i], values[i]);
        }
        else {
            double fraction = (double)capacity / weights[i];
            totalValue += fraction * values[i];
            capacity = 0;
            printf("Item %d: weight = %d, value = %d (fraction = %.2f)\n", i + 1, weights[i], values[i], fraction);
        }
    }

    return totalValue;
}

// main function
int main() {
    int n, capacity, i;

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i+1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    double maxVal = fractionalKnapsack(weights, values, n, capacity);
    printf("The maximum value that can be obtained is: %.2f\n", maxVal);

    return 0;
}
