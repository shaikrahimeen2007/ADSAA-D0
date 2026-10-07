#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;

}

int partition(int a[], int low, int high)
{
int pivot = a[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (a[j] <= pivot)
{
i++;
swap(&a[i], &a[j]);
}
}

swap(&a[i + 1], &a[high]);

return i + 1;
}

void quickSort(int a[], int low, int high)
{
if (low < high)
{
int pivotIndex;

pivotIndex = partition(a, low, high);

quickSort(a, low, pivotIndex - 1);

quickSort(a, pivotIndex + 1, high);
}
}

void display(int a[], int n)
{
int i;

for (i = 0; i < n; i++)
printf("%d ", a[i]);

printf("\n");
}

int main()
{
int choice, n, i;
int a[100000];
clock_t start, end;
double time_taken;

while (1)
{
printf("\n----- MENU -----\n");
printf("1. Quick Sort\n");
printf("2. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

if (choice == 1)
{

printf("\nEnter number of elements: ");
scanf("%d", &n);

/* Best Case
Last element as pivot.
Middle value is kept as pivot to get
nearly equal partitions.
*/
for (i = 0; i < n; i++)
a[i] = i + 1;

if (n > 1)
swap(&a[n - 1], &a[n / 2]);

if (n <= 20)
{
printf("\nBest Case - Before Sorting:\n");
display(a, n);
}

start = clock();
quickSort(a, 0, n - 1);
end = clock();

time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

if (n <= 20)
{
printf("Best Case - After Sorting:\n");
display(a, n);
}

printf("Best Case Execution Time = %f seconds\n",
time_taken);

/* Average Case - Random Array */
for (i = 0; i < n; i++)
a[i] = rand() % n;

if (n <= 20)
{
printf("\nAverage Case - Before Sorting:\n");
display(a, n);
}

start = clock();
quickSort(a, 0, n - 1);
end = clock();

time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

if (n <= 20)
{
printf("Average Case - After Sorting:\n");
display(a, n);
}

printf("Average Case Execution Time = %f seconds\n",
time_taken);

/* Worst Case - Sorted Array
Since last element is selected as pivot,
sorted array gives worst case.
*/
for (i = 0; i < n; i++)
a[i] = i + 1;

if (n <= 20)
{
printf("\nWorst Case - Before Sorting:\n");
display(a, n);
}

start = clock();
quickSort(a, 0, n - 1);
end = clock();

time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

if (n <= 20)
{
printf("Worst Case - After Sorting:\n");
display(a, n);
}

printf("Worst Case Execution Time = %f seconds\n",
time_taken);

printf("\nQuick Sort completed successfully.\n");
}
else if (choice == 2)

{
printf("\nExiting program...\n");
break;
}
else
{
printf("\nInvalid choice! Please try again.\n");
}
}

return 0;
}