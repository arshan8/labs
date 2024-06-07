#include <stdio.h>
#include <stdlib.h>
#define null NULL
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* getnode() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = newnode->next = NULL;
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    return newnode;
}

void insertbeg()
{
    struct node* newnode = getnode();
    if(head == null)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertend()
{

    struct node* newnode = getnode();
    if(head == null)
    {
        head = newnode;
        return;
    }

    struct node* temp = head;
    while(temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void deletebeg()
{
    if(head == null)
    {
        printf("empty \n");
        return;
    }
    if(head->next == null)
    {
        printf("only one left");
        free(head);
        head = null;
        return;
    }
    struct node* temp = head;
    head->next->prev = null;
    head = head->next;
    free(temp);

}

void deleteend()
{if(head == null)
    {
        printf("empty \n");
        return;
    }
    struct node* temp = head;

    if (head->next == NULL) { // Step 2: Check if the list has only one node
        printf("only one left: %d removed, now the list is empty\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while(temp->next->next!=null)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = null;

}

void display()
{
    struct node* temp = head;
    while(temp!=null)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int lenghthis()
{
    int count =0;
    struct node* temp = head;
    while(temp !=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void deleteatpos()
{
    int count = lenghthis();
    int pos;
    printf("enter position to delete:");
    scanf("%d",&pos);
    if(pos<1||pos>count)
    {
        printf("Invalid position");
        return;
    }
    if(pos==1)
    {
        deletebeg();
        return;
    }
    if(pos==count)
    {
        deleteend();
        return;
    }
    int i =1;
    struct node* temp = head;
    while(i<pos)
    {
        temp = temp->next;
        i++;
    }
    printf("%d deleted",temp->data);
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    return;
}

void insertatpos()
{
    int count = lenghthis();
    int pos;
    printf("enter pos: \n");
    scanf("%d",&pos);
    if(pos>count+1)
    { printf("invalid pos \n");
        return;
    }
    else if(pos==1)
    {
        insertbeg();  //this will be like before first one, but we want after
    }
     else if(pos==count+1)
    {
        insertend();
    }
    else{
        struct node* temp = head;
        struct node* newnode= getnode();
        int i =1;
    while(i<pos-1) //i<pos adds ele after the pos, this add at the given pos
    {  temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    newnode->prev = temp;
    temp->next->prev=newnode;
    temp->next = newnode;

    }
}

int main()
{
    int choice;
    //int i = 1;
    while(1)
    {
        printf("\n 1. insertbeginning \n 2. insertend \n 3. insertatpos \n 4. exi  \n 5.display \n 6.deleteFIRST \n 7. delete last \n 8. delete at pos \n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertatpos();
                break;
            case 4:
                exit(0);
            case 5:
                display();
                break;
            case 6:
                deletebeg();
                break;
            case 7:
                deleteend();
                break;
           case 8:
                deleteatpos();
                break;
        }
        //i++;
    }
    return 0;
}








