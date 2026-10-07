#include <stdio.h>

#include <stdlib.h>
#include <limits.h>

#define MAX_ROUTERS 100

typedef struct Router
{
int load;
int children[MAX_ROUTERS];
int childCount;
} Router;

Router routers[MAX_ROUTERS];

int minLoad = INT_MAX;
int bestRouter = -1;

// Function to calculate total load of a subtree
int calculateTotalLoad(int routerIndex)
{
int totalLoad = routers[routerIndex].load;

for (int i = 0; i < routers[routerIndex].childCount; i++)
{
int childIndex = routers[routerIndex].children[i];

totalLoad += calculateTotalLoad(childIndex);
}

return totalLoad;
}

// Function to find the optimal router
void findOptimalRouter(int n)
{
for (int i = 0; i < n; i++)
{
int totalLoad = calculateTotalLoad(i);

if (totalLoad < minLoad)
{
minLoad = totalLoad;
bestRouter = i;
}
}
}

int main()
{
int n;

// Number of routers
printf("Enter number of routers: ");
scanf("%d", &n);

// Input router loads
for (int i = 0; i < n; i++)
{
printf("Enter load for router %d: ", i);
scanf("%d", &routers[i].load);

routers[i].childCount = 0;

}

// Input tree connections
for (int i = 0; i < n - 1; i++)
{
int parent, child;

printf("Enter connection (parent child): ");
scanf("%d %d", &parent, &child);

routers[parent].children[
routers[parent].childCount++
] = child;
}

// Find optimal router
findOptimalRouter(n);

printf("\nOptimal router to connect the master server: ");
printf("Router %d with total load %d\n",
bestRouter, minLoad);

return 0;
}