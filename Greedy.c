#include <stdio.h>

// Function to calculate the minimum number of notes
// using the greedy strategy
void minNotes(int N)
{
    int i;

    // Available denominations
    int notes[] = {500, 200, 100, 50, 20, 10};
    int noteCount[6] = {0};

    // Iterate through each denomination
    // starting from the largest
    for (i = 0; i < 6; i++)
    {
        // Find how many notes of this denomination are needed
        if (N >= notes[i])
        {
            noteCount[i] = N / notes[i];

            // Remaining amount
            N = N % notes[i];
        }
    }

    // Check whether the exact amount can be formed
    if (N == 0)
    {
        printf("Minimum number of notes required:\n");

        for (i = 0; i < 6; i++)
        {
            if (noteCount[i] > 0)
            {
                printf("%d notes of Rs %d\n",
                       noteCount[i], notes[i]);
            }
        }
    }
    else
    {
        printf("It is not possible to form the exact amount "
               "with the given denominations.\n");
    }
}

int main()
{
    int N;

    printf("Enter the amount to be given: ");
    scanf("%d", &N);

    // Call the function
    minNotes(N);

    return 0;
}