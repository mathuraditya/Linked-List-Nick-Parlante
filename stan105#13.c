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
    struct node* ptr= (struct node*) malloc(sizeof(struct node));
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
};

void incorporate(struct node** defactohead, struct node** newguy)
{
    struct node** temp=newguy;
    struct node** current=defactohead;
    struct node* ephemeral=(*current);
    (*current)= (*temp);
    (*current)->next=(ephemeral);
}


void shufflemerge(struct node** headrefa, struct node** headrefb)
{
        struct node** current=&((*headrefa)->next);
        struct node** nextinline=headrefb;
        struct node* temp;

        while((*nextinline)->next!=NULL)
        {
                //printf("a");
                temp=(*nextinline)->next;
                incorporate(current, nextinline);
                (*nextinline)=temp;
                current=&((*current)->next->next);
        }

}

int main()
{
    int a, i;
    printf("Give the no of elements in list A\n");
    scanf("%d", &a);
    printf("Give each element in A\n");
    struct node* heada=newnode();
    struct node* current=heada;
    for(i=1;i<a;i++)
    {
        current->next= newnode();
        current=current->next;
    }

    printf("Give the no of elements in list B\n");
    scanf("%d", &a);
    printf("Give each element in B\n");
    struct node* headb=newnode();
    current=headb;
    for(i=1;i<a;i++)
    {
        current->next= newnode();
        current=current->next;
    }

   // incorporate(&(heada->next->next), &headb);
    shufflemerge(&heada, &headb);

    current=heada;
    while(current!=NULL)
    {
        printf(" %d ", current->data);
        current=current->next;
    }
    return 0;
}
