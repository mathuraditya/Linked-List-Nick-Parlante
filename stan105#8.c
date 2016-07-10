#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* newnode()
{
    int a;
    scanf("%d", &a);
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data=a;
    ptr->next=NULL;
    return ptr;
};

void append(struct node** ahref, struct node** bhref)
{
    struct node** current=ahref;
    while((*current)!=NULL)
    {
        current=&((*current)->next);
    }
    (*current)=(*bhref);
    *bhref=NULL;
}

int main()
{
    int count=0;
    printf("Give all values of A\n");
    struct node* headA= newnode();
    struct node* currentA= headA;

    while(count<3)
    {
        currentA->next=newnode();
        currentA=currentA->next;
        count++;
    }

    count=0;
    printf("Give all values of B\n");
    struct node* headB=newnode();
    struct node* currentB=headB;
    while(count<3)
    {
        currentB->next=newnode();
        currentB=currentB->next;
        count++;
    }
   // printf("a");
    append(&headA, &headB);

    currentA= headA;
    while(currentA!=NULL)
    {
        printf("%d\n", currentA -> data);
        currentA=currentA->next;
    }
}
