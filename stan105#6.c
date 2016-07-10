#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

 struct node
 {
     int data;
     struct node* next;
 };

 struct node* newnode(int a)
 {
     struct node* ptr= (struct node*) malloc(sizeof(struct node));
     ptr->next= NULL;
     ptr->data= a;
     return ptr;
 };

/*void sortedinsert(int value, struct node** headref)
{
        struct node** current= headref;
        struct node* ptr= *current;
        struct node* temp;

        while(ptr!=NULL)
        {
            if((ptr->data)>= value)
            {
                break;
            }
            else
            {
                current=&(ptr->next);
                ptr=(*current);
            }
        }
        temp=(*current);
        (*current)= newnode(value);
        (*current)->next=temp;

}
*/

void sortedinsert(int val, struct node** headref)
{
    struct node** current = headref;
    struct node* temp;
    while((*current)!=NULL)
    {
        if(((*current)->data)>=val)
        {
            break;
        }
        else
        {
            current=&((*current)->next);
        }
    }
        temp=(*current);
        (*current)=newnode(val);
        (*current)->next=temp;

}




int main()
{
    int i;
    struct node* head= newnode(1);
    struct node* current=head;

    for(i=2;i<10;i++)
    {
        current->next=newnode(i);
        current = current->next;
    }

    sortedinsert(5,&head);

    current= head;
    while(current!=NULL)
    {
        printf("%d\n", current->data);
        current=current->next;
    }
}
