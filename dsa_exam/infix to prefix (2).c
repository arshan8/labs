#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

int isempty()
{
    return top==-1;
}

int isfull()
{
    return top == 49;
}

void push(char a)
{
    if(isfull())
    {
        printf("stack overflow");

    }
    else{
        top++;
        stack[top]= a;
    }
}

char pop()
{
    if(isempty())
    {
        printf("nothing to pop");
    }
    else{
        char a = stack[top];
        top--;
        return a;
    }
}
void reversed(char a[])
{ int n = strlen(a);
    for(int i = 0; i<n/2;i++)
    {
        char temp = a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
}
int isoperand(char a)
{
    return isalpha(a)||isdigit(a);
}

int precdence(char a)
{
    if(a == '+'|| a == '-')
    {
        return 1;
    }
     if(a == '*'|| a == '/')
    {
        return 2;
    }
}

void infixtoprefix(char infix[], char prefix[])
{
    reversed(infix);
    int j = 0;

    for(int i = 0; infix[i];i++)
    {
        char ch = infix[i];
        if(isoperand(ch))
        {
            prefix[j++]=ch;
        }
        else if(ch == ')')
        {
            push(ch);
        }
         else if(ch == '(')
        {
            while(stack[top]!=')'&& !isempty() )
            {
                prefix[j++]=pop();
            }
            pop();
        }
        else
        {
            while(!isempty && precedence(ch)<=precedence(stack[top]))
            {
                prefix[j++]=pop();
            }
            push(ch);
        }

    }
    while(!isempty())
    {
        prefix[j++]=pop();
    }

    prefix[j] = '\0';
    reversed(prefix);
}

int main()
{
    char infix[50];
    char prefix[50];

    printf("enter infix expression: ");
    scanf("%s",infix);
   // gets(infix); //both are fine

    infixtoprefix(infix,prefix);

    printf("\n final : %s",prefix);
    return 0;
}
