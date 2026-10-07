#include <stdio.h> 
struct Job 
{ 
 char id; 
 int deadline; 
 int profit; 
}; 
int main() 
{ 
 struct Job job[20], temp; 
 int n, i, j; 
 int maxDeadline = 0; 
 int totalProfit = 0; 
 char slot[20];
  
 printf("Enter number of jobs: "); 
 scanf("%d", &n); 
 printf("Enter Job ID, Deadline and Profit:\n"); 
 for (i = 0; i < n; i++) 
 { 
 scanf(" %c %d %d", 
 &job[i].id, 
 &job[i].deadline, 
 &job[i].profit); 
 if (job[i].deadline > maxDeadline)  maxDeadline = job[i].deadline;  } 
 /* Sort jobs in descending order of profit */  for (i = 0; i < n - 1; i++) 
 { 
 for (j = i + 1; j < n; j++) 
 { 
 if (job[i].profit < job[j].profit)  { 
 temp = job[i]; 
 job[i] = job[j]; 
 job[j] = temp; 
 } 
 } 
 } 
 /* Initialize slots */ 
 for (i = 0; i < maxDeadline; i++) 
 slot[i] = '-'; 
 /* Schedule jobs */ 
 for (i = 0; i < n; i++) 
 { 
 for (j = job[i].deadline - 1; j >= 0; j--)  { 
 if (slot[j] == '-') 
 { 
 slot[j] = job[i].id; 
 totalProfit += job[i].profit;  break; 
 } 
 } 
 } 
 printf("\nJob Sequence:\n"); 
 for (i = 0; i < maxDeadline; i++) 
 { 
 if (slot[i] != '-') 
 printf("%c ", slot[i]); 
 }
 printf("\n\nTotal Profit = %d\n", totalProfit); 
 return 0; 
} 
