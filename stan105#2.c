#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    int position;

};

struct node* newnode( int position)
{
   int value;
   scanf("%d", &value);
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    ptr -> data= value;
    ptr->position= position;
    ptr-> next= NULL;

     return ptr;
};

int main()
{
    int n,i;

    struct node* head = newnode(0);
    struct node* current = head;

    for(i=1;i<11;i++)
    {
        current->next = newnode(i);

        current=current->next;
    }

    current = head;
    printf("Which element do you want?\n");
    scanf("%d", &n);
    while(current->position != n)
    {
        assert(n<=9);
        current=current->next;
    }

    printf("\n%d", current->data);
}
