#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to reverse a linked list
struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
int isPalindrome(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // An empty list or single node is a palindrome
    }

    // Find the middle of the linked list
    // struct node* slow = head;
    // struct node* fast = head;
    // while (fast != NULL && fast->next != NULL) {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // // Reverse the second half of the list
    // struct node* second_half = reverse(slow);
    // struct node* first_half = head;
struct node*rev = reverse(head);
    // Compare the two halves
    while (head != NULL) {
        if (head->data != rev->data) {
            return 0; // Not a palindrome
        }
        rev = rev->next;
        head = head->next;
    }

    return 1; // Palindrome
}

int main() {
    struct node* head = NULL;
    struct node* curr = NULL;

    printf("Enter nodes (-1 to stop): ");
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == -1) break;

        struct node* new_node = createnode(n);
        if (head == NULL) {
            head = new_node;
            curr = head;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }
    }

    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}
