#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
};

struct node*  newnode(int value)
{
    struct node* ptr=(struct node*) malloc(sizeof(struct node));
    ptr->data= value;
    ptr->next= NULL;
    return ptr;
};

void sortedinsert(int val, struct node** headref)
{
    struct node** current = headref;
    struct node* temp;
    while((*current)!=NULL)
    {
        if(((*current)->data)>=val)
        {
            break;
        }
        else
        {
            current=&((*current)->next);
        }
    }
        temp=(*current);
        (*current)=newnode(val);
        (*current)->next=temp;

}


int main()
{
    int i,a;
    struct node* head= newnode(1);
    struct node* current= head;
     for(i=1;i<8;i++)
     {
         scanf("%d", &a);
         sortedinsert(a, &head);
     }

     current=head;
     while(current!=NULL)
     {
         printf("%d\n", current->data);
         current=current->next;
     }

}
