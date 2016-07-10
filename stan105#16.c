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
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
};

struct node* newnode1(int n)
{
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
};


void push(struct node** headref, struct node** newguy)
{
    struct node** current;
    struct node* ptr=newnode1((*newguy)->data);
    (current)=headref;
    //printf("%d\n", (*newguy)->data);
    while((*current)!=NULL)
    {
       // printf("d\n");
        current=&((*current)->next);
    }
    (*current)= ptr;
    //current=&((*current)->next);
    //(*current)=NULL;
}

struct node* sortedintersect(struct node** heada, struct node** headb)
{
        struct node** rotor=heada;
        struct node** stator=headb;
        struct node* newlist=NULL;
        while((*rotor)!=NULL&&(*stator)!=NULL)
        {
           //printf("c\n");
            if((*rotor)->data>(*stator)->data)
            {
                stator=&(*rotor);
                rotor=&(*stator);
            }
            else if ((*rotor)->data==(*stator)->data)
            {
                push(&newlist, stator );
                stator=&((*stator)->next);
            }
            rotor=&((*rotor)->next);

        }
       // printf("b\n");
        return newlist;



};

int main()
{
    int i,a;
    printf("give no of elements in 1st list\n");
    scanf("%d",&i);

    struct node* head=newnode();
    struct node* current=head;
    for(a=1;a<i;a++)
    {
        current->next=newnode();
        current=current->next;
    }


    printf("give no of elements in 2nd list\n");
    scanf("%d",&i);

    struct node* headb=newnode();
    current=headb;
    for(a=1;a<i;a++)
    {
        current->next=newnode();
        current=current->next;
    }
   // printf("a\n");
   struct node* ptr= sortedintersect(&head,&headb);

    //printf("give new guy\n");
    //struct node* newguy=newnode();
    //push(&head,&newguy);
    current=ptr;
   // printf("e\n");
    while(current!=NULL)
    {
        //printf("f\n");
        printf(" %d ", current->data);
        current=current->next;
    }

}
