#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int isrt;          //1 if it has a child, 0 if it has thread
};

struct node* root = NULL;
struct node* head = NULL;

struct node* createnode(int key ) {
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("Memory allocation error!\n");
    exit(1);  // Or handle the error differently
  }
  newnode->data = key;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->isrt = 0;
  return newnode;
}


struct node* create()
{
    char y = 'y';
    do
    {
        int key;
        printf("enter key:");
        scanf("%d",&key);
        struct node* temp = createnode(key);
        if(root==NULL)
        {
            head = createnode(9999);
            root = temp;
            head->right = head;
            head->isrt = 1;
            root->right = head;
        }
        else
        {
            insert(root,temp);
        }
        printf("do you want more node, enter y?");
        scanf(" %c",&y);

    } while(y == 'y');

    return root;
}

void insert(struct node* root, struct node * temp)
{
    if(temp->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left = temp;
            temp->right = root;

        }
        else
        {
            insert(root->left,temp);
        }
    }

    if(temp->data>root->data)
    {
        if(root->right==NULL)
        {
            temp->right = root->right;
            root->right = temp;
            root->isrt = 1;
        }
        else
        {
            insert(root->right,temp);
        }
    }
}




void inorder(struct node* root)
{
    struct node* curr = root;
    while(curr->left != NULL)
    {
        curr = curr->left;
    }
<<<<<<< HEAD

=======
>>>>>>> 7a9e708a65f2287dc37b6bb8a0b22b07e942b6e7
    while(curr != head)
    {
        printf("%d ",curr->data);
        curr = curr->right;
    }
<<<<<<< HEAD
     printf("%d ",curr->left->data);
=======
    printf("%d",curr->left->data)
>>>>>>> 7a9e708a65f2287dc37b6bb8a0b22b07e942b6e7
}

int main()
{
    root = create();
    printf("Inorder traversal of the right-inthreaded binary tree: ");
    inorder(root);

    return 0;
}

