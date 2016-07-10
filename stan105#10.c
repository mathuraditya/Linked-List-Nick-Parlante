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
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
};

int getlength(struct node** headref)
{
    int count=0;
    struct node** current= headref;
    while((*current)!=NULL)
    {
        current=(&(*current)->next);
        count++;
    }
    return count;
}

int thisisntrepeated(int* a, int n, int size)
{
    int count=0,flag=1;
    while(count<size)
    {
        if(a[count]==n)
        {flag=0;}
        count++;
    }
    return flag;

}



void noduplicates(struct node** headref)
{
    struct node** current=headref;
    struct node* temp=NULL;
    int n=getlength(current);
    int array[n];
    int a=0;
    while((*current)!=NULL)
    {
       if(thisisntrepeated(array, (*current)->data, n))
       {
            array[a]=(*current)->data; /* this actually worked*/
        a++;
        current=(&(*current)->next);
       }
       else
       {
            temp=(*current)->next;
            (*current)=temp;
       }
    }
}


int main()
{
    int i,n;
    printf("give no of elements\n");
    scanf("%d", &n);
    printf("give each element\n");
    struct node* head=newnode();
    struct node* current=head;
    for(i=1;i<n;i++)
    {
        current->next= newnode();
        current=current->next;
    }

    noduplicates(&head);

    current=head;
    while(current!=NULL)
    {
        printf("%d", current->data);
        current=current->next;
    }


}
