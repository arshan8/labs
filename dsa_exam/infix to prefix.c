#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(char item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Function to get precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

// Function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    // Reverse the infix expression
    reverseString(infix);

    int i, j = 0;
    for (i = 0; infix[i]!='\0'; i++) {
        char ch = infix[i];
        if (isOperand(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            push(ch);
        }

        else if (ch == '(')
        {
            while (!isEmpty() && stack[top] != ')') {
                prefix[j++] = pop();
            }
            pop(); // Pop the ')'
        }

        else
           {
             while (!isEmpty() && precedence(ch) <= precedence(stack[top])) {
                prefix[j++] = pop();
               }
              push(ch);
           }
    }

    // Pop remaining operators from stack
    while (!isEmpty()) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';  // Null-terminate the string

    reverseString(prefix); // Reverse the prefix expression to get the final result
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("Infix expression: %s\n", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

