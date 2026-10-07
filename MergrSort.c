#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void merge(int a[], int low, int mid, int high) 
{ 
 int i = low, j = mid + 1, k = low; 
 int b[100000]; 
 while (i <= mid && j <= high) 
 { 
 if (a[i] <= a[j]) 
 b[k++] = a[i++]; 
 else 
 b[k++] = a[j++]; 
 } 
 while (i <= mid) 
 b[k++] = a[i++]; 
 while (j <= high)
 b[k++] = a[j++]; 
 for (i = low; i <= high; i++) 
 a[i] = b[i]; 
} 
void mergeSort(int a[], int low, int high) { 
 if (low < high) 
 { 
 int mid = (low + high) / 2; 
 mergeSort(a, low, mid); 
 mergeSort(a, mid + 1, high); 
 merge(a, low, mid, high); 
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
 printf("1. Merge Sort\n"); 
 printf("2. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 if (choice == 1) 
 { 
 printf("\nEnter number of elements: ");  scanf("%d", &n); 
 /* Best Case - Sorted Array */ 
 for (i = 0; i < n; i++) 
 a[i] = i + 1; 
 if (n <= 20) 
 { 
 printf("\nBest Case - Before Sorting:\n");  display(a, n); 
 } 
 start = clock(); 
 mergeSort(a, 0, n - 1); 
 end = clock();
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
 if (n <= 20) 
 { 
 printf("Best Case - After Sorting:\n"); 
 display(a, n); 
 } 
 printf("Best Case Execution Time = %f seconds\n",  time_taken); 
 /* Average Case - Random Array */ 
 for (i = 0; i < n; i++) 
 a[i] = rand() % n; 
 if (n <= 20) 
 { 
 printf("\nAverage Case - Before Sorting:\n");  display(a, n); 
 } 
 start = clock(); 
 mergeSort(a, 0, n - 1); 
 end = clock(); 
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
 if (n <= 20) 
 {
 printf("Average Case - After Sorting:\n");  display(a, n); 
 } 
 printf("Average Case Execution Time = %f seconds\n",  time_taken); 
 /* Worst Case - Reverse Sorted Array */ 
 for (i = 0; i < n; i++) 
 a[i] = n - i; 
 if (n <= 20) 
 { 
 printf("\nWorst Case - Before Sorting:\n");  display(a, n); 
 } 
 start = clock(); 
 mergeSort(a, 0, n - 1); 
 end = clock(); 
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
 if (n <= 20) 
 { 
 printf("Worst Case - After Sorting:\n");  display(a, n); 
 } 
 printf("Worst Case Execution Time = %f seconds\n",
 time_taken); 
 printf("\nMerge Sort completed successfully.\n");  } 
 else if (choice == 2) 
 { 
 printf("\nExiting program...\n"); 
 break; 
 } 
 else 
 { 
 printf("\nInvalid choice! Please try again.\n");  } 
 } 
 return 0; 
} 
