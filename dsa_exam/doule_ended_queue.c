#include <stdio.h>
#include <stdlib.h>
# define null 0
struct node
{
    int data;
    struct node* link;

};struct node *head = null;

struct node* createnode()
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> link =null;
    printf("enter data:");
    scanf("%d",&newnode->data);
    return newnode;
};

void enque_rear()
{
    if(head == null)
    { struct node* newnode = createnode();
        newnode->link = null;
        head = newnode;
    }
    else
    {
    struct node* newnode = createnode();
    struct node* temp = head;
    while(temp->link != null)
    {
       temp = temp->link;
    }
    temp->link = newnode;
    }
}

void deletefront()
{
    if(head == null)
    {
        printf("empty");
        return;
    }
    struct node* temp = head;
    head = head->link;
    free(temp);
}

void traverse()
{
    struct node* temp = head;
    while(temp != null)
    {
        printf("%d --> ",temp->data);
        temp = temp->link;
    }
}

void enque_front()
{
 if(head == null)
 {
     struct node * newnode = createnode();
    newnode->link = head;
     head = newnode;
 }
 else{
    struct node * newnode = createnode();
    newnode->link = head;
    head = newnode;
 }
}

void delete_rear()
{
      if(head == null)
    {
        printf("empty");
        return;
    }
    struct node* temp = head;
    while(temp->link->link!= null)
    {
        temp = temp->link;
    }
    printf("deleted %d",temp->link->data);
   free(temp->link);
    temp->link = NULL;
//optional

}

int main()
{
   printf("1)add front 2)add back 3)delete front 4)delete back 5)display 6) stop ");
   int c;

   while(1)
   { printf("\n enter :");
   scanf("%d",&c);
       if(c==1)
       {
           enque_front();
       }
        if(c==2)
       {
           enque_rear();
       }
        if(c==3)
       {
           deletefront();
       }
        if(c==4)
       {
           delete_rear();
       }
       if(c==5)
       {
           traverse();

       }
       if(c==6)
       {
           exit(0);
       }
   }
}
