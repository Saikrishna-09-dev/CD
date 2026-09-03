#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to simulate a heap block
typedef struct HeapBlock {
    int id;
    size_t size;
    void *address;
    struct HeapBlock *next;
} HeapBlock;
HeapBlock *heapList = NULL; // linked list to track allocations
int blockCounter = 0;
// Function to allocate memory
void* allocateHeap(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Heap allocation failed!\n");
        return NULL;
    }
    HeapBlock *newBlock = (HeapBlock*)malloc(sizeof(HeapBlock));
    newBlock->id = ++blockCounter;
    newBlock->size = size;
    newBlock->address = ptr;
    newBlock->next = heapList;
    heapList = newBlock;
    printf("Allocated Block ID %d of size %zu bytes at %p\n", newBlock->id, size,ptr);
    return ptr;

}
// Function to free memory
void freeHeap(void *ptr) {
    HeapBlock *prev = NULL, *curr = heapList;
    while (curr != NULL) {
        if (curr->address == ptr) {
            if (prev == NULL) {
                heapList = curr->next;
            } else {
                prev->next = curr->next;
            }
            printf("Freed Block ID %d of size %zu bytes at %p\n", curr->id, curr->size,
            ptr);
            free(curr->address);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Pointer %p not found in heap list!\n", ptr);
}
// Function to display heap status
void displayHeap() {
HeapBlock *curr = heapList;
    printf("\n--- Heap Status ---\n");
    while (curr != NULL) {
        printf("Block ID %d | Size: %zu | Address: %p\n", curr->id, curr->size, curr->address);
        curr = curr->next;
    }
    printf("-------------------\n");

}
int main() {
    // Example usage
    int *arr = (int*)allocateHeap(5 * sizeof(int));
    char *str = (char*)allocateHeap(20 * sizeof(char));
    strcpy(str, "Heap Allocation Demo");
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    displayHeap();
    freeHeap(arr);
    freeHeap(str);
    displayHeap();
    return 0;
}