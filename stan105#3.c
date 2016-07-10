#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* pre;
};

struct node* newnode(int value)
{
    //printf("c");
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    ptr->data=value;
    ptr-> next= NULL;
    ptr->pre=NULL;
    return ptr;
};


void deletelist(struct node** headref)
{
    struct node* current= *headref;
    printf("d");
    while(current->next!= NULL)
    {
        //printf("e");
        current=current->next;
        free(current->pre);

    }
    printf("a");

}

int main()
{
    int i, p;
    struct node* dummy= newnode(0);
    struct node* current;
    current = dummy;
    current->pre=NULL;

    for(i=1;i<10;i++)
    {
        scanf("%d", &p);
        current->next = newnode(p);
        current->next->pre= current;
        current=current->next;

    }
    printf("b");
    deletelist(&dummy->next);
    printf("f");
}
