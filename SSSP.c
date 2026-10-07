#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#include <time.h> 
#define MAX 50 
struct Node 
{ 
 int vertex; 
 int weight; 
 struct Node *next; 
}; 
void dijkstraMatrix(int graph[MAX][MAX], int n, int src) { 
 int dist[MAX], visited[MAX]; 
 int i, j, u, min; 
 for (i = 0; i < n; i++) 
 { 
 dist[i] = INT_MAX; 
 visited[i] = 0; 
 } 
 dist[src] = 0; 
 for (i = 0; i < n - 1; i++) 
 { 
 u = -1;
 min = INT_MAX; 
 for (j = 0; j < n; j++) 
 { 
 if (!visited[j] && dist[j] < min)  { 
 min = dist[j]; 
 u = j; 
 } 
 } 
 if (u == -1) 
 break; 
 visited[u] = 1; 
 for (j = 0; j < n; j++) 
 { 
 if (graph[u][j] != 0 && 
 !visited[j] && 
 dist[u] + graph[u][j] < dist[j])  { 
 dist[j] = dist[u] + graph[u][j];  } 
 } 
 }
 printf("\nAdjacency Matrix Result:\n"); 
 for (i = 0; i < n; i++) 
 printf("%d -> %d = %d\n", src, i, dist[i]); } 
void dijkstraList(struct Node *adj[], int n, int src) { 
 int dist[MAX], visited[MAX]; 
 int i, j, u, min; 
 struct Node *p; 
 for (i = 0; i < n; i++) 
 { 
 dist[i] = INT_MAX; 
 visited[i] = 0; 
 } 
 dist[src] = 0; 
 for (i = 0; i < n - 1; i++) 
 { 
 u = -1; 
 min = INT_MAX; 
 for (j = 0; j < n; j++) 
 {
 if (!visited[j] && dist[j] < min)  { 
 min = dist[j]; 
 u = j; 
 } 
 } 
 if (u == -1) 
 break; 
 visited[u] = 1; 
 p = adj[u]; 
 while (p != NULL) 
 { 
 if (dist[u] + p->weight < dist[p->vertex])  dist[p->vertex] = dist[u] + p->weight; 
 p = p->next; 
 } 
 } 
 printf("\nAdjacency List Result:\n"); 
 for (i = 0; i < n; i++) 
 printf("%d -> %d = %d\n", src, i, dist[i]);
} 
int main() 
{ 
 int graph[MAX][MAX] = {0};  struct Node *adj[MAX] = {NULL}; 
 int n, e, i; 
 int u, v, w, src; 
 clock_t start, end; 
 printf("Enter number of vertices: ");  scanf("%d", &n); 
 printf("Enter number of edges: ");  scanf("%d", &e); 
 printf("Enter edges (u v weight):\n"); 
 for (i = 0; i < e; i++) 
 { 
 scanf("%d %d %d", &u, &v, &w); 
 graph[u][v] = w; 
 graph[v][u] = w; 
 struct Node *newNode;
 newNode = (struct Node *)malloc(sizeof(struct Node));  newNode->vertex = v; 
 newNode->weight = w; 
 newNode->next = adj[u]; 
 adj[u] = newNode; 
 newNode = (struct Node *)malloc(sizeof(struct Node));  newNode->vertex = u; 
 newNode->weight = w; 
 newNode->next = adj[v]; 
 adj[v] = newNode; 
 } 
 printf("Enter source vertex: "); 
 scanf("%d", &src); 
 start = clock(); 
 dijkstraMatrix(graph, n, src); 
 end = clock(); 
 printf("Matrix Time = %f seconds\n", 
 (double)(end - start) / CLOCKS_PER_SEC); 
 start = clock(); 
 dijkstraList(adj, n, src); 
 end = clock();
 printf("List Time = %f seconds\n", 
 (double)(end - start) / CLOCKS_PER_SEC); 
 return 0; 
} 
