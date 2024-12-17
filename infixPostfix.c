#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack {
    int top;
    int size;
    char* arr; // Fixed typo in your declaration
};

struct stack* createstack(int size) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char*)malloc(size * sizeof(char));
    return stack;
}

void push(struct stack* stack, char ch) {
    if (stack->top == stack->size - 1) {
        printf("Overflow\n");
        return;
    }
    stack->arr[++stack->top] = ch;
}

char pop(struct stack* stack) {
    if (stack->top == -1) {
        printf("Underflow\n");
        return '\0'; // NULL replaced with '\0' for characters
    }
    return stack->arr[stack->top--];
}

char peek(struct stack* stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[stack->top];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void postfix(char* infix) {
    struct stack* s = createstack(strlen(infix));
    char result[strlen(infix) + 1]; // Extra space for null terminator
    int res = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the result
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            result[res++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(s, ch);
        }
        // If the character is ')', pop and append until '(' is encountered
        else if (ch == ')') {
            while (!s->top == -1 && peek(s) != '(') {
                result[res++] = pop(s);
            }
            pop(s); // Remove the '('
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (s->top != -1 && precedence(peek(s)) >= precedence(ch)) {
                result[res++] = pop(s);
            }
            push(s, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (s->top != -1) {
        result[res++] = pop(s);
    }

    result[res] = '\0'; // Null-terminate the postfix expression

    printf("Postfix Expression: %s\n", result);

    // Free allocated memory
    free(s->arr);
    free(s);
}

int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    postfix(infix);

    return 0;
}
