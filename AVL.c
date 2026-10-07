#include<stdio.h>
#include<stdlib.h>

#include<direct.h> /* needed to find current folder */

/* Structure of an AVL Node */
struct Node {
int data;
struct Node *left;
struct Node *right;
int height;
};

struct Node *root = NULL;

/* Returns maximum of two numbers */
int max(int a, int b) {
if (a > b) return a;
return b;
}

/* Step 2: Calculate Height */
int Height(struct Node *node) {
if (node == NULL) return 0;
return node->height;
}

/* Step 3: Calculate Balance Factor */
int BalanceFactor(struct Node *node) {
if (node == NULL) return 0;
return Height(node->left) - Height(node->right);
}

/* Step 1: Create an AVL Node */
struct Node* CreateNode(int value) {
struct Node *node = (struct Node*)malloc(sizeof(struct Node));

node->data = value;
node->left = NULL;
node->right = NULL;
node->height = 1;
return node;
}

/* Step 4: Right Rotation (LL Rotation) */
struct Node* RightRotate(struct Node *y) {
struct Node *x = y->left;
struct Node *T2 = x->right;

x->right = y;
y->left = T2;

y->height = max(Height(y->left), Height(y->right)) + 1;
x->height = max(Height(x->left), Height(x->right)) + 1;

return x;
}

/* Step 5: Left Rotation (RR Rotation) */
struct Node* LeftRotate(struct Node *x) {
struct Node *y = x->right;
struct Node *T2 = y->left;

y->left = x;
x->right = T2;

x->height = max(Height(x->left), Height(x->right)) + 1;
y->height = max(Height(y->left), Height(y->right)) + 1;

return y;

}

/* Step 8: Insert Operation */
struct Node* Insert(struct Node *root, int key) {
if (root == NULL) return CreateNode(key);

if (key < root->data)
root->left = Insert(root->left, key);
else if (key > root->data)
root->right = Insert(root->right, key);
else
return root; /* duplicate values not allowed */

root->height = max(Height(root->left), Height(root->right)) + 1;

int balance = BalanceFactor(root);

/* LL Rotation */
if (balance > 1 && key < root->left->data)
return RightRotate(root);

/* RR Rotation */
if (balance < -1 && key > root->right->data)
return LeftRotate(root);

/* LR Rotation */
if (balance > 1 && key > root->left->data) {
root->left = LeftRotate(root->left);
return RightRotate(root);
}

/* RL Rotation */
if (balance < -1 && key < root->right->data) {

root->right = RightRotate(root->right);
return LeftRotate(root);
}

return root;
}

/* Finds the node with smallest value (used in Delete) */
struct Node* MinValueNode(struct Node *node) {
struct Node *current = node;
while (current->left != NULL)
current = current->left;
return current;
}

/* Step 9: Delete Operation */
struct Node* Delete(struct Node *root, int key) {
if (root == NULL) return root;

if (key < root->data)
root->left = Delete(root->left, key);
else if (key > root->data)
root->right = Delete(root->right, key);
else {
/* Node with no child or one child */
if (root->left == NULL || root->right == NULL) {
struct Node *temp = root->left ? root->left : root->right;

if (temp == NULL) {
temp = root;
root = NULL;
} else {
*root = *temp; /* copy child's contents into root */

}
free(temp);
}
/* Node with two children */
else {
struct Node *temp = MinValueNode(root->right);
root->data = temp->data;
root->right = Delete(root->right, temp->data);
}
}

if (root == NULL) return root;

root->height = max(Height(root->left), Height(root->right)) + 1;

int balance = BalanceFactor(root);

/* LL Rotation */
if (balance > 1 && BalanceFactor(root->left) >= 0)
return RightRotate(root);

/* LR Rotation */
if (balance > 1 && BalanceFactor(root->left) < 0) {
root->left = LeftRotate(root->left);
return RightRotate(root);
}

/* RR Rotation */
if (balance < -1 && BalanceFactor(root->right) <= 0)
return LeftRotate(root);

/* RL Rotation */
if (balance < -1 && BalanceFactor(root->right) > 0) {

root->right = RightRotate(root->right);
return LeftRotate(root);
}

return root;
}

/* Step 10: In-order Traversal - print on screen */
void InOrderDisplay(struct Node *root) {
if (root != NULL) {
InOrderDisplay(root->left);
printf("%d ", root->data);
InOrderDisplay(root->right);
}
}

/* Step 10: In-order Traversal - write into file */
void InOrder(struct Node *root, FILE *file) {
if (root != NULL) {
InOrder(root->left, file);
fprintf(file, "%d ", root->data);
InOrder(root->right, file);
}
}

/* Reads values from students.txt and builds the AVL tree */
struct Node* ReadFromFile(struct Node *root) {
FILE *fp = fopen("students.txt", "r");
int value;

if (fp == NULL) {
printf("students.txt not found. Starting with empty tree.\n");
return root;

}

while (fscanf(fp, "%d", &value) != EOF)
root = Insert(root, value);

fclose(fp);
return root;
}

/* Main function - Menu driven program */
int main() {
int choice, value;
FILE *outFile;
char folder[260];

/* This shows which folder the program is looking in for students.txt */
_getcwd(folder, sizeof(folder));
printf("Looking for students.txt in this folder:\n%s\n\n", folder);
printf("Make sure students.txt is placed in the above folder.\n\n");

root = ReadFromFile(root);
printf("AVL Tree constructed successfully from students.txt\n");

do {
printf("\n---------- AVL TREE MENU ----------\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display Inorder Traversal\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

if (choice == 1) {

printf("Enter value to insert: ");
scanf("%d", &value);
root = Insert(root, value);
printf("Value %d inserted successfully.\n", value);
}
else if (choice == 2) {
printf("Enter value to delete: ");
scanf("%d", &value);
root = Delete(root, value);
printf("Value %d deleted (if it existed).\n", value);
}
else if (choice == 3) {
printf("\nInorder Traversal: ");
InOrderDisplay(root);
printf("\n");

outFile = fopen("output.txt", "w");
if (outFile == NULL) {
printf("Error creating output.txt\n");
} else {
InOrder(root, outFile);
fclose(outFile);
printf("Inorder traversal written to output.txt\n");
}
}
else if (choice == 4) {
printf("Exiting program. Goodbye!\n");
}
else {
printf("Invalid choice! Please enter between 1 and 4.\n");
}

} while (choice != 4);

return 0;
}
