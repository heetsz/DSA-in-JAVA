#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev; // Optional for doubly linked lists
};

// Function to find the minimum data in the remaining list from a given node
struct node* findMinNode(struct node* start) {
    struct node* minNode = start;
    while (start != NULL) {
        if (start->data < minNode->data) {
            minNode = start;
        }
        start = start->next;
    }
    return minNode;
}

// Function to sort the linked list using Selection Sort
void sort(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        // Find the minimum node in the remaining unsorted list
        struct node* minNode = findMinNode(curr);

        // Swap the data between the current node and the minimum node
        if (curr->data != minNode->data) {
            int temp = curr->data;
            curr->data = minNode->data;
            minNode->data = temp;
        }

        curr = curr->next; // Move to the next node
    }
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // Optional for doubly linked lists
    return newNode;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate sorting
int main() {
    // Create a sample doubly linked list: 4 <-> 3 <-> 1 <-> 2
    struct node* head = createNode(4);
    head->next = createNode(3);
    head->next->prev = head; // Optional
    head->next->next = createNode(1);
    head->next->next->prev = head->next; // Optional
    head->next->next->next = createNode(2);
    head->next->next->next->prev = head->next->next; // Optional

    printf("Original list:\n");
    printList(head);

    sort(head);

    printf("Sorted list:\n");
    printList(head);

    return 0;
}
