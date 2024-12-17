#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* naya = (struct node*)malloc(sizeof(struct node));
    naya->data = data;
    naya->next = NULL;
    return naya;
}

struct node* reverse(struct node* head) {
    struct node* curr = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* add(struct node* a, struct node* b) {
    struct node* h1 = a;
    struct node* h2 = b;
    struct node* res = NULL;  // Result list head
    struct node* tail = NULL; // Pointer to track the last node
    int carry = 0;

    while (h1 != NULL || h2 != NULL || carry > 0) {
        int sum = carry;
        if (h1 != NULL) {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL) {
            sum += h2->data;
            h2 = h2->next;
        }
        
        carry = sum / 10;
        int digit = sum % 10;

        struct node* newNode = create(digit);

        if (res == NULL) {
            res = newNode; // Initialize the result list
        }
        else {
            tail->next = newNode; // Append to the result list
        }
        tail = newNode; // Move the tail
    }
    return res;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* h1 = create(7);
    h1->next = create(2);
    h1->next->next = create(3);
    h1->next->next->next = create(3);

    struct node* h2 = create(5);
    h2->next = create(7);
    h2->next->next = create(4);

    // Reverse the input lists
    h1 = reverse(h1);
    h2 = reverse(h2);

    // Add the two lists
    struct node* h3 = add(h1, h2);

    // Reverse the result list to get the final answer
    h3 = reverse(h3);

    // Print the result
    printList(h3);

    return 0;
}
