#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n;
int dist[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int bestTour[MAX_CITIES + 1];
int minCost = INT_MAX;

int firstMin(int city)
{
int min = INT_MAX;

for (int i = 0; i < n; i++)
{
if (i != city && dist[city][i] < min)
min = dist[city][i];
}

return min;

}

int secondMin(int city)
{
int first = INT_MAX, second = INT_MAX;

for (int i = 0; i < n; i++)
{
if (i == city)
continue;

if (dist[city][i] <= first)
{
second = first;
first = dist[city][i];
}
else if (dist[city][i] < second)
{
second = dist[city][i];
}
}

return second;
}

void TSPRec(int currentBound, int currentCost,
int level, int path[])

{
if (level == n)
{
if (dist[path[level - 1]][path[0]] != 0)
{
int totalCost =
currentCost +
dist[path[level - 1]][path[0]];

if (totalCost < minCost)
{
minCost = totalCost;

for (int i = 0; i < n; i++)
bestTour[i] = path[i];

bestTour[n] = path[0];
}
}

return;
}

for (int i = 0; i < n; i++)
{
if (!visited[i] &&
dist[path[level - 1]][i] != 0)

{
int newCost =
currentCost +
dist[path[level - 1]][i];

int newBound = currentBound;

if (level == 1)
newBound -=
(firstMin(path[level - 1]) +
firstMin(i)) / 2;
else
newBound -=
(secondMin(path[level - 1]) +
firstMin(i)) / 2;

if (newCost + newBound < minCost)
{
path[level] = i;
visited[i] = 1;

TSPRec(newBound, newCost,
level + 1, path);

visited[i] = 0;
}
}

}
}

void TSP()
{
int path[MAX_CITIES + 1];
int bound = 0;

for (int i = 0; i < n; i++)
{
visited[i] = 0;
bound += firstMin(i) + secondMin(i);
}

bound = (bound + 1) / 2;

for (int i = 0; i < n; i++)
visited[i] = 0;

visited[0] = 1;
path[0] = 0;

TSPRec(bound, 0, 1, path);

printf("\nOptimal Tour: ");

for (int i = 0; i <= n; i++)

printf("%d ", bestTour[i] + 1);

printf("\nTotal Distance: %d\n", minCost);
}

int main()
{
printf("Enter the number of cities: ");
scanf("%d", &n);

printf("Enter the distance matrix (0 for self-distance):\n");

for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
scanf("%d", &dist[i][j]);
}
}

TSP();

return 0;
}