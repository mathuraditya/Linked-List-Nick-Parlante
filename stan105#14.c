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
    scanf("%d",&n);
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
};

void incorporate(struct node** defactohead, struct node** newguy)
{
    struct node** current=defactohead;
    struct node** nextinline=newguy;
    struct node* temp=(*current);
    (*current)=(*nextinline);
    (*nextinline)->next=(temp);

}

void sortedmerge(struct node** headrefa, struct node** headrefb)
{
    struct node** current=headrefa;
    struct node** nextinline=headrefb;
    struct node* temp;
    while((*nextinline)!=NULL)
    {
        if((*nextinline)->data<(*current)->data)
        {
            temp=(*nextinline)->next;
            incorporate(current,nextinline);
            (*nextinline)=temp;
            current=&((*current)->next);
        }
        else
        {
            current=&((*current)->next);
        }
    }
};


int main()
{
    int a, i;
    printf("How many elements in the larger list?\n");
    scanf("%d", &a);
    printf("Give all elements of the larger list\n");
    struct node* heada=newnode();
    struct node* current= heada;
    for(i=1;i<a;i++)
    {
        current->next=newnode();
        current=current->next;
    }
    ///////////////////////////////////////////////


    printf("How many elements in the smaller list?\n");
    scanf("%d", &a);
    printf("Give all elements of the smaller list\n");
    struct node* headb=newnode();
    current= headb;
    for(i=1;i<a;i++)
    {
        current->next=newnode();
        current=current->next;
    }

    ///////////////////////////////////////////
    sortedmerge(&heada, &headb);
   // incorporate(&(heada->next->next), &headb);

    current=heada;

    while(current!=NULL)
    {
        printf(" %d ", current->data);
        current=current->next;
    }
}
