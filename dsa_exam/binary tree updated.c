#include<stdio.h>
#include<stdlib.h>

struct node
{
    long long int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node *createNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation error!\n");
        exit(1); // Exit program on allocation failure
    }

    printf("Enter data: ");
    scanf("%lld", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

struct node* create()
{
struct node* root = NULL;
char y = 'y';
    do
    {   struct node* newnode = createNode();
        if(root==NULL)
        {
            root = newnode;
        }
        else{

            insert(root,newnode);
        }
        printf("do you wanna add more node? (y/n) : ");
        scanf(" %c",&y);
    }while(y=='y');
    return root;
};

void insert(struct node* root, struct node* temp)
{
    char x;
    printf("enter l for left and r for right of root %d:",root->data);
    scanf(" %c",&x);

    if(x == 'l')
    {  if(root->left == NULL)
        {
            root->left = temp;
        }
       else{
        insert(root->left,temp);
       }
    }
    if(x=='r')
    {  if(root->right == NULL)
        {
            root->right = temp;
        }
       else{
        insert(root->right,temp);
         }
    }
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d-->",root->data);
        inorder(root->right);
    }
}

int main()
{
    printf("hello world \n");
    root = create();
    inorder(root);
    return -69;
}
