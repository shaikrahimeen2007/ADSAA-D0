#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;
int choice;

// Function prototypes
void insertMin(int);
void insertMax(int);
void deleteElementMin(int);
void deleteElementMax(int);
void minHeapify(int);
void maxHeapify(int);
void display();

// -------------------- MAIN --------------------

int main()
{
    int n, value, del, i;

    printf("1. Min Heap\n");
    printf("2. Max Heap\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if(choice == 1)
            insertMin(value);
        else
            insertMax(value);
    }

    printf("\nHeap after construction:\n");
    display();

    printf("\nEnter element to delete: ");
    scanf("%d", &del);

    if(choice == 1)
        deleteElementMin(del);
    else
        deleteElementMax(del);

    printf("\nHeap after deletion:\n");
    display();

    return 0;
}

// -------------------- INSERT MIN HEAP --------------------

void insertMin(int value)
{
    int i = size;

    heap[size++] = value;

    while(i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// -------------------- INSERT MAX HEAP --------------------

void insertMax(int value)
{
    int i = size;

    heap[size++] = value;

    while(i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// -------------------- MIN HEAPIFY --------------------

void minHeapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        minHeapify(smallest);
    }
}

// -------------------- MAX HEAPIFY --------------------

void maxHeapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] > heap[largest])
        largest = left;

    if(right < size && heap[right] > heap[largest])
        largest = right;

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        maxHeapify(largest);
    }
}

// -------------------- DELETE FROM MIN HEAP --------------------

void deleteElementMin(int value)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(heap[i] == value)
            break;
    }

    if(i == size)
    {
        printf("Element not found!\n");
        return;
    }

    heap[i] = heap[size - 1];
    size--;

    minHeapify(i);
}

// -------------------- DELETE FROM MAX HEAP --------------------

void deleteElementMax(int value)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(heap[i] == value)
            break;
    }

    if(i == size)
    {
        printf("Element not found!\n");
        return;
    }

    heap[i] = heap[size - 1];
    size--;

    maxHeapify(i);
}

// -------------------- DISPLAY --------------------

void display()
{
    int i;

    if(size == 0)
    {
        printf("Heap is empty.\n");
        return;
    }

    for(i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}