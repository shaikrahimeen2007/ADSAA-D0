#include <stdio.h> 
#define MAX 20 
int board[MAX][MAX]; 
int n; 
/* Check whether a queen can be placed */ int isSafe(int row, int col) 
{ 
 int i, j; 
 /* Check column */ 
 for (i = 0; i < row; i++) 
 { 
 if (board[i][col] == 1) 
 return 0; 
 } 
 /* Check upper-left diagonal */ 
 for (i = row - 1, j = col - 1; 
 i >= 0 && j >= 0; 
 i--, j--)
 { 
 if (board[i][j] == 1) 
 return 0; 
 } 
 /* Check upper-right diagonal */  for (i = row - 1, j = col + 1;  i >= 0 && j < n; 
 i--, j++) 
 { 
 if (board[i][j] == 1) 
 return 0; 
 } 
 return 1; 
} 
/* N-Queens using Backtracking */ void nQueens(int row) 
{ 
 int col; 
 /* All queens are placed */  if (row == n) 
 { 
 printf("\nSolution:\n"); 
 for (int i = 0; i < n; i++)  { 
 for (int j = 0; j < n; j++)  { 
 if (board[i][j] == 1)  printf("Q "); 
 else 
 printf(". "); 
 } 
 printf("\n");
 } 
 return; 
 } 
 /* Try every column */  for (col = 0; col < n; col++)  { 
 if (isSafe(row, col)) 
 { 
 board[row][col] = 1;  nQueens(row + 1); 
 /* Backtrack */ 
 board[row][col] = 0;  } 
 } 
} 
int main() 
{ 
 int i, j; 
 printf("Enter the value of N: ");  scanf("%d", &n); 
 /* Initialize board */ 
 for (i = 0; i < n; i++) 
 { 
 for (j = 0; j < n; j++)  { 
 board[i][j] = 0; 
 } 
 } 
 nQueens(0);
 return 0; 
} 
