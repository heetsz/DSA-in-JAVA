#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int data){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    return head;
}

struct node* deleteindex(struct node* head, int ind){
    struct node* curr = head;
    if(ind == 0){
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    for(int i = 0; i < ind - 1 && curr != NULL; i++){
        curr = curr->next; 
    }
    if(curr == NULL || curr->next == NULL){
        printf("out of bounds\n");
        return head;
    }
    struct node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

struct node* duplicates(struct node* head){
    struct node* curr = head;
    int i;
    while(curr != NULL){
        struct node* curr2 = head;
        i = 0;
        while(curr2 != NULL){
            if(curr != curr2 && curr2->data == curr->data){
                head = deleteindex(head, i);
                 curr2 = head; // Reset curr2 after deletion to avoid skipping nodes
                i = 0; // Reset index as list has changed
            } else {
                curr2 = curr2->next;
                i++;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printList(struct node* head){
    struct node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = create(4);
    head->next = create(3);
    head->next->next = create(3);
    head->next->next->next = create(4);
    head->next->next->next->next = create(4);

    printf("Original List: ");
    printList(head);

    head = duplicates(head);
    
    printf("List After Removing Duplicates: ");
    printList(head);

    return 0;
}
