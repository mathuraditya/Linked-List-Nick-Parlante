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
    int a;
    scanf("%d", &a);
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=a;
    return ptr;
}

void movenode(struct node** headrefa, struct node** headrefb)
{
    struct node* temp1;
    struct node* temp2;
    temp1= (*headrefa);
    (*headrefa)=(*headrefb);
    temp2=(*headrefa)->next;
    (*headrefa)=temp2;
    (*headrefb)->next=temp1;
}

int main()
{
    int a,i;
    printf("give no of elements in list A\n");
    scanf("%d", &a);
    printf("give all elements of a\n");
    struct node* heada=newnode();
    struct node* current=heada;
    for(i=1;i<a;i++)
    {
        current->next=newnode();
        current=current->next;
    }

     int b,p;
    printf("give no of elements in list B\n");
    scanf("%d", &b);
    printf("give all elements of B\n");
    struct node* headb=newnode();
    struct node* currentb=headb;
    for(p=1;p<b;p++)
    {
        currentb->next=newnode();
        currentb=currentb->next;
    }

    movenode(&heada, &headb);
    current=heada;
    currentb=headb;
    printf("the revised list A is-\n");
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }
    printf("\n");
    printf("The revised list B is-\n");
    while(currentb!=NULL)
    {
        printf("%d", currentb->data);
        currentb=currentb->next;
    }
}
