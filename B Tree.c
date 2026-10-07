#include <stdio.h> 
#include <stdlib.h> 
#define MAX 4 
#define MIN 2 
typedef struct BTreeNode 
{ 
 int val[MAX + 1], count; 
 struct BTreeNode *link[MAX + 2]; 
} node; 
node *root = NULL;
// Create Node 
node *createNode(int val, node *child) { 
 node *newNode; 
 newNode = (node *)malloc(sizeof(node));  newNode->val[1] = val; 
 newNode->count = 1; 
 newNode->link[0] = root; 
 newNode->link[1] = child; 
 for (int i = 2; i <= MAX + 1; i++) 
 newNode->link[i] = NULL; 
 return newNode; 
} 
// Search position 
int searchNode(int val, node *myNode, int *pos) { 
 if (val < myNode->val[1]) 
 { 
 *pos = 0; 
 return 0; 
 }
 *pos = myNode->count; 
 while ((val < myNode->val[*pos]) && *pos > 1)  (*pos)--; 
 if (val == myNode->val[*pos]) 
 return 1; 
 return 0; 
} 
// Split Node 
void splitNode(int val, int *pval, int pos, node *myNode,  node *child, node **newNode) 
{ 
 int median, j; 
 if (pos > MIN) 
 median = MIN + 1; 
 else 
 median = MIN; 
 *newNode = (node *)malloc(sizeof(node));  j = median + 1;
 while (j <= MAX) 
 { 
 (*newNode)->val[j - median] = myNode->val[j];  (*newNode)->link[j - median] = myNode->link[j];  j++; 
 } 
 myNode->count = median; 
 (*newNode)->count = MAX - median; 
 if (pos <= MIN) 
 { 
 j = myNode->count; 
 while (j > pos) 
 { 
 myNode->val[j + 1] = myNode->val[j];  myNode->link[j + 1] = myNode->link[j];  j--; 
 } 
 myNode->val[j + 1] = val; 
 myNode->link[j + 1] = child; 
 myNode->count++; 
 } 
 else 
 {
 j = (*newNode)->count; 
 while (j > (pos - median)) 
 { 
 (*newNode)->val[j + 1] = (*newNode)->val[j];  (*newNode)->link[j + 1] = (*newNode)->link[j];  j--; 
 } 
 (*newNode)->val[j + 1] = val; 
 (*newNode)->link[j + 1] = child; 
 (*newNode)->count++; 
 } 
 *pval = myNode->val[myNode->count]; 
 (*newNode)->link[0] = myNode->link[myNode->count];  myNode->count--; 
} 
// Insert value 
int setValue(int val, int *pval, 
 node *myNode, node **child) 
{ 
 int pos; 
 if (!myNode)
 { 
 *pval = val; 
 *child = NULL; 
 return 1; 
 } 
 if (searchNode(val, myNode, &pos))  { 
 printf("Duplicate Key\n"); 
 return 0; 
 } 
 if (setValue(val, pval, myNode->link[pos], child))  { 
 if (myNode->count < MAX) 
 { 
 int j = myNode->count; 
 while (j > pos) 
 { 
 myNode->val[j + 1] = myNode->val[j];  myNode->link[j + 1] = myNode->link[j];  j--; 
 } 
 myNode->val[j + 1] = *pval;
 myNode->link[j + 1] = *child; 
 myNode->count++; 
 return 0; 
 } 
 splitNode(*pval, pval, pos, myNode, *child, child);  return 1; 
 } 
 return 0; 
} 
// Insert 
void insert(int val) 
{ 
 int flag, i; 
 node *child; 
 flag = setValue(val, &i, root, &child); 
 if (flag) 
 root = createNode(i, child); 
} 
// Search
void search(node *myNode, int val) { 
 int pos; 
 if (!myNode) 
 { 
 printf("Key not found\n"); 
 return; 
 } 
 if (searchNode(val, myNode, &pos))  { 
 printf("Key %d Found\n", val);  return; 
 } 
 search(myNode->link[pos], val); } 
// Display 
void display(node *myNode) 
{ 
 if (myNode) 
 { 
 for (int i = 0; i < myNode->count; i++)  {
 display(myNode->link[i]); 
 printf("%d ", myNode->val[i + 1]);  } 
 display(myNode->link[myNode->count]);  } 
} 
// Simplified deletion 
void deleteKey(node *myNode, int key) { 
 if (myNode == NULL) 
 { 
 printf("Key not found\n"); 
 return; 
 } 
 int pos; 
 if (searchNode(key, myNode, &pos))  { 
 printf("Deleted %d (logical deletion)\n", key);  myNode->val[pos] = -1; 
 return; 
 }
 deleteKey(myNode->link[pos], key); 
} 
int main() 
{ 
 int arr[100]; 
 // Generate 100 random elements 
 printf("Random Elements:\n"); 
 for (int i = 0; i < 100; i++) 
 { 
 arr[i] = rand() % 1000; 
 printf("%d ", arr[i]); 
 insert(arr[i]); 
 } 
 int ch, key; 
 while (1) 
 { 
 printf("\n\n1.Search\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");  printf("Enter Choice: "); 
 scanf("%d", &ch); 
 switch (ch)
 { 
 case 1: 
 printf("Enter Key: ");  scanf("%d", &key); 
 search(root, key); 
 break; 
 case 2: 
 printf("Enter Key: ");  scanf("%d", &key); 
 insert(key); 
 break; 
 case 3: 
 printf("Enter Key: ");  scanf("%d", &key); 
 deleteKey(root, key);  break; 
 case 4: 
 printf("B-Tree Elements:\n");  display(root); 
 printf("\n"); 
 break;
 case 5: 
 exit(0); 
 default: 
 printf("Invalid Choice\n"); 
 } 
 } 
 return 0; 
} 