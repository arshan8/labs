#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node* createNode(int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->left = newNode->right = NULL;
    newNode->data = key;
    return newNode;
}

// Function to create a BST interactively
struct node* create() {
    struct node* root = NULL;

    char y = 'y';
    do {
        int key;
        printf("Enter key: ");
        scanf("%d", &key);

        struct node* temp = createNode(key);

        if (root == NULL) {
            root = temp;
        } else {
            insert(root, temp);
        }

        printf("Do you want to add more nodes (y/n)? ");
        scanf(" %c", &y);
    } while (y == 'y' || y == 'Y');

    return root;
}

// Function to insert a node into the BST
void insert(struct node* root, struct node* temp) {
    if (temp->data < root->data) {
        if (root->left == NULL) {
            root->left = temp;
        } else {
            insert(root->left, temp);
        }
    } else {
        if (root->right == NULL) {
            root->right = temp;
        } else {
            insert(root->right, temp);
        }
    }
}

// Function to perform in-order traversal on the BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to find the minimum value node in a tree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with the given key
struct node* deleteNode(struct node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If the key is the same as the root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node* root = create();

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
  char y = 'y';
do{
    int keyToDelete;
    printf("\n Enter key to delete: ");
    scanf("%d", &keyToDelete);

    // Call delete function here (once implemented)
    root = deleteNode(root, keyToDelete);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    printf(" \n enter y to continue y/n ");
    scanf(" %c",&y);
}while(y=='y');



    return 0;
}
