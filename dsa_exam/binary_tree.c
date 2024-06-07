#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;

};

struct node*create()
{   int x;
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data (enter -1 to exit:");
    scanf("%d",&x);
    if(x==-1)
    {
        free(newnode);
        return NULL;
    }
    newnode->data = x;

    printf("ENTER LEFT CHILD OF %d:",x);
    newnode->left = create();

      printf("ENTER right CHILD OF %d:",x);
    newnode->right = create();

   return newnode;
};

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}
int main()
{ struct node* root = create();
  inorder(root);
    return 0;
}
