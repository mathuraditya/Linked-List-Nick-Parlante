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
        int value;
        scanf("%d", &value);
    struct node* ptr= (struct node* ) malloc (sizeof(struct node));

    ptr->data=value;
    ptr->next = NULL;
    //printf("1");
    return ptr;

};



int main()
{
    int i,a, count=0;
    struct node* current;
    struct node* head = newnode();
    current=head;


    for(i=0; i<10; i++)
    {
        current-> next = newnode();
        current=current->next;
    }
     current=head;

    printf("Enter Key\n");
    scanf("%d", &a);

    while(current!=NULL)
    {
        if(current->data==a)
        {
            count+=1;
        }
        current=current->next;
    }
    printf("\n%d\n", count);




}
