#include <stdio.h>

#define MAX_ITEMS 100

// Function to calculate the maximum value
// of items that can fit in the knapsack
int knapsack(int weights[], int values[], int n, int capacity)
{
    // If no items are left or capacity is 0
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    // If the weight of the nth item is more than capacity
    if (weights[n - 1] > capacity)
    {
        return knapsack(weights, values, n - 1, capacity);
    }
    else
    {
        // Include the nth item
        int includeItem = values[n - 1] +
                          knapsack(weights, values, n - 1,
                                   capacity - weights[n - 1]);

        // Exclude the nth item
        int excludeItem = knapsack(weights, values, n - 1, capacity);

        // Return maximum of the two
        return (includeItem > excludeItem) ? includeItem : excludeItem;
    }
}

int main()
{
    int values[MAX_ITEMS], weights[MAX_ITEMS];
    int n, capacity;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input values
    printf("Enter the values of the items:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    // Input weights
    printf("Enter the weights of the items:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // Input capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate maximum value
    int maxValue = knapsack(weights, values, n, capacity);

    printf("Maximum value in the knapsack: %d\n", maxValue);

    return 0;
}