#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* create_node()
{
   struct node *newn=(struct node*)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("Memory is not allocated\n");
    else
    {
         scanf("%d",&newn->data);
         newn->link=NULL;
    }
    return newn;
}
struct node* insert_front(struct node *head)
{
   struct node* newn=create_node();
    if(head==NULL)
    head=newn;
    else
    {
        newn->link=head;
       head=newn;
    }
    return head;
}
void display_list(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
        printf("List is empty\n");
    else
        cur=head;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->link;
    }
    printf("\n");
}
struct node* reverse_list(struct node *head)

{
    struct node *prev,*cur,*next;
    if(head==NULL)
        printf("SLL is empty\n");
    else if(head->link==NULL)
        return head;
    else
    {
        prev=NULL;
        cur=head;
        while(cur!=NULL)
        {
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
        }
        head=prev;
    }
    return head;
}

int main()
{
    int n;
    struct node *head = NULL;
    scanf("%d",&n);
    if(n>1)
    {
        for(int i=0;i<n;i++)
        head=insert_front(head);
        printf("List is:\n");
        display_list(head);
        printf("\n");
        head=reverse_list(head);
        printf("Reversed list is:\n");
        display_list(head);

    }
    else
        printf("Invalid input\n");
    return 0;
}

