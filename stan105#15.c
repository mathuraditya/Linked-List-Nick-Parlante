#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
    int data;
    struct node* next;
};

struct node* newnode()
{
    int n;
    scanf("%d", &n);
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
};


int getlength(struct node** headref)
{
    struct node** current=headref;
    int count=0;
    while((*current)!=NULL)
    {
        count++;
        current=&((*current)->next);
    }
    return count;
}

struct node* frontbacksplit(struct node** headref)
{
    struct node** current=headref;
    int n= getlength(headref);

    int a=0;
    if((n%2)==0)
    {
        while(a<n/2)
        {
            current=&((*current)->next);
        }
        struct node** headb=(struct node**)malloc(sizeof(struct node*));
        (*headb)->next=(*current);
        (*current)=NULL;
        return (*headb);
    }
    else
    {
        while(a<(n/2)+1)
        {
            current=&((*current)->next);
        }
        struct node** headb=(struct node**)malloc(sizeof(struct node*));
        (*headb)->next=(*current);
        (*current)=NULL;
        return (*headb);
    }
};

void incorporate(struct node** actinghead, struct node** newguy)
{
    struct node* temp;
    struct node** current=actinghead;
    struct node** nextin=newguy;
    temp=(*current);
    (*current)=(*nextin);
    (*nextin)->next=temp;

}


void sortedmerge(struct node** headrefa, struct node** headrefb)
{
        struct node** current=headrefa;
        struct node** nextin = headrefb;
        struct node* temp=NULL;

        while((*nextin)!=NULL)
        {
            if((*current)->data>(*nextin)->data)
            {
                temp=(*nextin)->next;
                incorporate(current,nextin);
                current=&((*current)->next);
                (*nextin)=temp;
            }
            else
            {
                current=&((*current)->next);
            }
        }
}


void mergesort(struct node** headref)
{
    struct node*= (*current);
    if(current->next!=NULL)
    {

    }


}

int main()
{
    int a, i;
    printf("Give no of elements\n");
    scanf("%d", &a);
    printf("give each element\n");
    struct node* head=newnode();
    struct node* current=head;
    for(i=1;i<a;i++)
    {
        current->next=newnode();
        current=current->next;
       // printf("A");
    }
    mergesort(&head);
    current=head;
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }
}
