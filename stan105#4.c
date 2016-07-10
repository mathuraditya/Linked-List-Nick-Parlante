#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*  next ;
};

struct node* newnode()
{
    int value;
    scanf("%d", &value);
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    ptr->data= value;
    ptr->next=NULL;
    return ptr;
};

    int pop(struct node** headref)
    {
        struct node* ptr= *headref;
        struct node* temp=ptr;
        int a= (*headref)->data;
        *headref = (*headref)->next;
        free(temp);

        return a;
    }

int main()
{
    int i;
    struct node* tip= newnode();
    struct node* current= tip;

    for(i=0;i<10;i++)
    {
        current-> next = newnode();
        current=current ->next;
    }

    printf("%d\n", pop(&tip));
    printf("%d", pop(&tip));



}
