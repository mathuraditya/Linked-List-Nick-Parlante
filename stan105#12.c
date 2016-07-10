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
    int n;
    scanf("%d", &n);
    struct node* ptr=(struct node*) malloc (sizeof(struct node));
    ptr->data=n;
    ptr->next= NULL;
    return ptr;
};

struct node* alternatesplit(struct node** headref)
{
    struct node** currenta=headref;
    struct node** headb=(struct node**)malloc(sizeof(struct node*));
    (*headb)= (*headref)->next;
    struct node** currentb=headb;

    while((*currentb)->next!=NULL&&(*currenta)->next!=NULL)
    {
    (*currenta)->next= (*currenta)->next->next;
    (*currentb)->next=(*currentb)->next->next;
    (currenta)=&((*currenta)->next);
    (currentb)=&((*currentb)->next);
    }
    //printf("a");
    return (*headb);
};


int main()
{
    int a, i;
    printf("Give no of elements in the list\n");
    scanf("%d",&a);
    printf("Give each element of the list\n");
    struct node* head=newnode();
    struct node* current=head;
    for(i=1;i<a;i++)
    {
        current->next=newnode();
        current=current->next;
    }

    struct node* headb=alternatesplit(&head);
    struct node* currentb=headb;
    current=head;
    while(current!=NULL)
    {
       // printf("b");
        printf("%d", current->data);
        current=current->next;
        //printf("p");
    }
    printf("\n");
    //printf("h");
    while(currentb!=NULL)
    {
      //  printf("g");
        printf("%d", currentb->data);
        currentb=currentb->next;
    }
}
