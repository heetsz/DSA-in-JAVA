#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete duplicate elements from a sorted linked list
void deleteDuplicates(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return; // If the list is empty or has only one node, no duplicates exist
    }

    struct node* curr = head;

    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            // Remove the duplicate node
            struct node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp); // Free memory of the removed node
        } else {
            curr = curr->next; // Move to the next node
        }
    }
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the deleteDuplicates function
int main() {
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> NULL
    struct node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(1);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(3);

    printf("Original list:\n");
    printList(head);

    // Remove duplicates
    deleteDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
