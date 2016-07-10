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
    struct node* ptr= (struct node*) malloc (sizeof(ptr));
    ptr->data= a;
    ptr->next=NULL;
    return ptr;
};

int getlength(struct node* head)
{
    int n, count=0;
    struct node* current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

struct node* frontbacksplit(struct node** headref)
{
    int n=getlength(*headref), count=0;
    //printf("%d", n);
    struct node** current=headref;
    struct node** temp=(struct node** ) malloc(sizeof(struct node*));

    if(n<2)
    {
        return;
    }
    int i=n%2;
    switch(i)
    {
        case 0:
            {
                int a=n/2;
                while(count<a)
                {
                    current=(&(*current)->next);
                    count++;
                }
                (*temp)=(*current);
                (*current)=NULL;
                return (*temp);

            }

        case 1:
            {
                int a=(n/2)+1;
                //printf("%d",a);
                while(count<a)
                {
                    current=&((*current)->next);
                    count++;
                }
                (*temp)=(*current);
                (*current)=NULL;
                return(*temp);
            }
    }

}

int main()
{
    int i,n;
    printf("Give n, the number of elements in the list\n");
    scanf("%d", &n);
    printf("give all the elements of the list\n");
    struct node* head=newnode();
    struct node* current=head;
    for(i=1;i<n;i++)
    {
        current->next= newnode();
        current=current->next;
    }

    struct node* headB=frontbacksplit(&head);
    current=head;
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }
    printf("\n");
    current=headB;
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }

}
