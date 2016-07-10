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
    int a;
    scanf("%d", &a);
    struct node* ptr= (struct node*) malloc ( sizeof(struct node));
    ptr-> data = a;
    ptr->next=NULL;
    return ptr;
};

void insertNth( int n, struct node** headref)
{
    int count=1;
    struct node* temp= (struct node*) malloc ( sizeof(struct node));
    struct node** current = (struct node**) malloc (sizeof(struct node*));
    current = (headref);

    do
    {
        current=&((*current)->next);
        count ++;
    }while(count <n);

     temp=(*current);
     printf("Give the value that you want at n\n");

     *current=newnode();
     (*current)->next=temp;
}

int main()
{
    int i,val,N;
    struct node* head= (struct node*) malloc (sizeof(struct node));
    head=newnode();
    struct node* current = head;

    for(i=0;i<10;i++)
    {
        current -> next = newnode();
        current = current -> next;
    }

    printf("Give N \n");
    scanf("%d", &N);

    insertNth( N , &head);
    //printf("%d", head->data);
    current = head;


       while(current!=NULL)
    {
        printf("%d\n", current->data);
        current  = current-> next;
    }

}
