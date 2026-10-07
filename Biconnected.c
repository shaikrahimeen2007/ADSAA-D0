#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100 
// Structure for adjacency list 
struct Node 
{ 
 int vertex; 
 struct Node *next; 
}; 
struct Node *graph[MAX]; 
int disc[MAX], low[MAX], parent[MAX], bcc[MAX]; 
int timeCount = 0;
// Create a new node 
struct Node *createNode(int v) 
{ 
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));  newNode->vertex = v; 
 newNode->next = NULL; 
 return newNode; 
} 
// Add an edge to the graph 
void addEdge(int u, int v) 
{ 
 struct Node *newNode = createNode(v); 
 newNode->next = graph[u]; 
 graph[u] = newNode; 
 newNode = createNode(u); 
 newNode->next = graph[v]; 
 graph[v] = newNode; 
} 
// DFS function 
void DFS(int u)
{ 
 disc[u] = low[u] = ++timeCount;  int children = 0; 
 struct Node *temp = graph[u]; 
 while (temp != NULL) 
 { 
 int v = temp->vertex; 
 if (disc[v] == -1) 
 { 
 children++; 
 parent[v] = u; 
 DFS(v); 
 if (low[v] < low[u]) 
 low[u] = low[v]; 
 // Root articulation point 
 if (parent[u] == -1 && children > 1)  bcc[u] = 1;
 // Non-root articulation point 
 if (parent[u] != -1 && low[v] >= disc[u])  bcc[u] = 1; 
 } 
 else if (v != parent[u]) 
 { 
 if (disc[v] < low[u]) 
 low[u] = disc[v]; 
 } 
 temp = temp->next; 
 } 
} 
int main() 
{ 
 int n, e; 
 int i, u, v; 
 printf("Enter number of vertices: ");  scanf("%d", &n);
 printf("Enter number of edges: ");  scanf("%d", &e); 
 // Initialize graph 
 for (i = 0; i < n; i++) 
 graph[i] = NULL; 
 printf("Enter the edges:\n");  for (i = 0; i < e; i++) 
 { 
 scanf("%d%d", &u, &v);  addEdge(u, v); 
 } 
 // Initialize arrays 
 for (i = 0; i < n; i++) 
 { 
 disc[i] = -1; 
 low[i] = -1; 
 parent[i] = -1; 
 bcc[i] = 0; 
 }
 // DFS Traversal 
 for (i = 0; i < n; i++) 
 { 
 if (disc[i] == -1) 
 DFS(i); 
 } 
 // Display vertices belonging to bi-connected components 
 printf("\nVertices belonging to Bi-Connected Components (Articulation  Points):\n"); 
 for (i = 0; i < n; i++) 
 { 
 if (bcc[i]) 
 printf("%d ", i); 
 } 
 printf("\n"); 
 // Free memory 
 for (i = 0; i < n; i++) 
 { 
 struct Node *temp = graph[i]; 
 while (temp != NULL)
 { 
 struct Node *ptr = temp; 
 temp = temp->next; 
 free(ptr); 
 } 
 } 
 return 0; 
} 
