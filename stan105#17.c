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
    struct node* ptr=(struct node* ) malloc (sizeof(struct node));
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
};

void poke(struct node** headref, struct node** pokee)
{
    struct node* temp=(*headref);
    (*headref)=(*pokee);
    (*headref)->next=temp;
}

void reverse(struct node** headref)
{
   struct node** current=&((*headref)->next);

  while((*current)!=NULL)
   {
       struct node* temp=(*current)->next;
       poke(headref,current);
       (*current)=temp;
   }

}



int main()
{
    printf("Give no of elements in the list\n");
    int n,i;
    scanf("%d", &n);

    struct node* head=newnode();
    struct node* current=head;

    for(i=1;i<n;i++)
    {
        current->next=newnode();
        current=current->next;
    }
//printf("%d", i);
    reverse(&head);

    current=head;
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }
}
