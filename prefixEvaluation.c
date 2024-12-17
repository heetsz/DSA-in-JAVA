#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the stack structure
struct Stack {
    int* arr; // Dynamic array for stack
    int top;
    int size;
};

// Function to create and initialize a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* prefix) {
    int length = strlen(prefix);
    struct Stack* stack = createStack(length);

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, push it onto the stack
        if (isdigit(ch)) {
            push(stack, ch - '0');
        }
        // If the character is an operator, pop two operands, perform the operation, and push the result
        else {
            int op1 = pop(stack);
            int op2 = pop(stack);

            switch (ch) {
                case '+':
                    push(stack, op1 + op2);
                    break;
                case '-':
                    push(stack, op1 - op2);
                    break;
                case '*':
                    push(stack, op1 * op2);
                    break;
                case '/':
                    push(stack, op1 / op2);
                    break;
            }
        }
    }

    // The result of the expression will be the only element in the stack
    int result = pop(stack);

    // Free allocated memory
    free(stack->arr);
    free(stack);

    return result;
}

int main() {
    char prefix[100];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);

    printf("Result of the prefix expression: %d\n", result);

    return 0;
}
