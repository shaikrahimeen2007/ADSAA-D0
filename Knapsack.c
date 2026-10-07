#include <stdio.h> 
int max(int a, int b) 
{ 
 if (a > b) 
 return a; 
 else 
 return b; 
} 
int main() 
{ 
 int n, W; 
 int weight[20], profit[20];
 int K[21][51]; 
 int i, w; 
 printf("Enter number of items: "); 
 scanf("%d", &n); 
 printf("Enter knapsack capacity: "); 
 scanf("%d", &W); 
 printf("\nEnter weight and profit of each item:\n"); 
 for (i = 1; i <= n; i++) 
 { 
 printf("Item %d: ", i); 
 scanf("%d %d", &weight[i], &profit[i]);  } 
 /* Initialize DP table */ 
 for (i = 0; i <= n; i++) 
 { 
 for (w = 0; w <= W; w++) 
 { 
 if (i == 0 || w == 0) 
 K[i][w] = 0; 
 else if (weight[i] <= w) 
 { 
 K[i][w] = max( 
 profit[i] + K[i - 1][w - weight[i]],  K[i - 1][w]
 ); 
 } 
 else 
 { 
 K[i][w] = K[i - 1][w]; 
 } 
 } 
 } 
 /* Display DP Table */ 
 printf("\nDP Table:\n"); 
 for (i = 0; i <= n; i++) 
 { 
 for (w = 0; w <= W; w++) 
 { 
 printf("%3d ", K[i][w]); 
 } 
 printf("\n"); 
 } 
 /* Display Maximum Profit */ 
 printf("\nMaximum Profit = %d\n", K[n][W]); 
 return 0; 
}
