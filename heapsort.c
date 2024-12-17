#include <stdio.h>
#include <stdlib.h>

// Define MaxHeap structure
struct MaxHeap {
    int array[100];
    int capacity;
    int size;
};

// Create MaxHeap
struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Swap two elements in the heap
void swap(struct MaxHeap* heap, int i, int j) {
    int temp = heap->array[i];
    heap->array[i] = heap->array[j];
    heap->array[j] = temp;
}

// Heapify Down to maintain the max-heap property
void heapifyDown(struct MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;
    if (largest != index) {
        swap(heap, index, largest);
        heapifyDown(heap, largest);
    }
}

// Heapify Up to maintain the max-heap property
void heapifyUp(struct MaxHeap* heap, int index) {
    while (index > 0 && heap->array[(index - 1) / 2] < heap->array[index]) {
        swap(heap, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

// Insert an element into the heap
void insert(struct MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Cannot insert more elements.\n");
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Extract the maximum element from the heap
int extractMax(struct MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    int maxVal = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return maxVal;
}

// Heap Sort function
void heapSort(int arr[], int n) {
    struct MaxHeap* heap = createMaxHeap(n);
    
    // Build the max heap
    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }

    // Extract the max elements one by one and place them in the sorted order
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(heap);
    }

    // Free the heap memory
    free(heap);
}

// Function to find the k largest elements
void findKLargest(int* nums, int n, int k) {
    struct MaxHeap* heap = createMaxHeap(n);
    for (int i = 0; i < n; i++) {
        insert(heap, nums[i]);
    }
    printf("The %d largest elements are: ", k);
    for (int i = 0; i < k; i++) {
        int maxVal = extractMax(heap);
        printf("%d ", maxVal);
    }
    printf("\n");
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Input array size
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);

    // Input array elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Heap Sort the array
    heapSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    // Find k largest elements
    printf("Enter k: ");
    int k;
    scanf("%d", &k);
    findKLargest(arr, n, k);

    return 0;
}
