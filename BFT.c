#include <stdio.h>

int a[10][10], visited[10], q[10], front, rear, n;

// Breadth First Search
void bfs(int s)
{
int i;

front = 0;
rear = -1;

q[++rear] = s;
visited[s] = 1;

while(front <= rear)
{

s = q[front++];
printf("%d ", s);

for(i = 0; i < n; i++)
{
if(a[s][i] == 1 && visited[i] == 0)
{
q[++rear] = i;
visited[i] = 1;
}
}
}
}

// Depth First Search using Stack
void dfs(int s)
{
int stack[10], top = -1, i;

stack[++top] = s;
visited[s] = 1;

while(top != -1)
{
s = stack[top--];
printf("%d ", s);

for(i = n - 1; i >= 0; i--)
{
if(a[s][i] == 1 && visited[i] == 0)
{
stack[++top] = i;
visited[i] = 1;
}
}
}
}

int main()
{
int i, j, ch, s;
char c;

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for(i = 0; i < n; i++)
{
for(j = 0; j < n; j++)
{
scanf("%d", &a[i][j]);
}
}

do
{
for(i = 0; i < n; i++)
visited[i] = 0;

printf("\n1. BFS\n2. DFS\n");
printf("Enter your choice: ");
scanf("%d", &ch);

printf("Enter source vertex: ");
scanf("%d", &s);

if(ch == 1)
{
printf("BFS Traversal: ");
bfs(s);
}
else if(ch == 2)
{
printf("DFS Traversal: ");
dfs(s);
}
else
{
printf("Invalid Choice");
}

printf("\nDo you want to continue (Y/N): ");
scanf(" %c", &c);

} while(c == 'Y' || c == 'y');

return 0;
}