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

//typedef struct node *NODE;

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}


struct node * create_tree(char postfix[], int *index) {
    if (*index < 0) {
        return NULL;
    }

    char symbol = postfix[*index];
    (*index)--;

    struct node * temp = (struct node *)malloc(sizeof(struct node));
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

float eval(struct node * root) {
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



int main() {
    char postfix[20];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int index = strlen(postfix) - 1; // Start from the end of the string
   struct node * root = create_tree(postfix, &index);

    float result = eval(root);
    printf("Result = %f\n", result);

    printf("\n INFIX: ");
    inorder(root);

    return 0;
}

