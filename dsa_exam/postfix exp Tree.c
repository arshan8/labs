#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
struct node {
    char data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE create_tree(char postfix[], int *index);
float eval(NODE root);

int main() {
    char postfix[20];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int index = strlen(postfix) - 1; // Start from the end of the string
    NODE root = create_tree(postfix, &index);

    float result = eval(root);
    printf("Result = %f\n", result);

    return 0;
}

NODE create_tree(char postfix[], int *index) {
    if (*index < 0) {
        return NULL;
    }

    char symbol = postfix[*index];
    (*index)--;

    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = symbol;
    temp->left = temp->right = NULL;

    if (isalnum(symbol)) {
        return temp;
    } else {
        temp->right = create_tree(postfix, index);
        temp->left = create_tree(postfix, index);
        return temp;
    }
}

float eval(NODE root) {
    float num;
    switch (root->data) {
        case '+': return eval(root->left) + eval(root->right);
        case '-': return eval(root->left) - eval(root->right);
        case '/': return eval(root->left) / eval(root->right);
        case '*': return eval(root->left) * eval(root->right);
        case '^': return pow(eval(root->left), eval(root->right));
        default:
            if (isalpha(root->data)) {
                printf("Enter the value of %c\n", root->data);
                scanf("%f", &num);
                return num;
            } else {
                return (root->data - '0');
            }
    }
}


