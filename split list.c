#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*link;
};
struct node * create_node()
{
    struct node * newn=(struct node *)malloc(sizeof(struct node * ));
    if(newn==NULL)
    printf("memory is not allocated\n");
    else
    {

        scanf("%d",&newn->data);
        newn->link=NULL;
    }
   return newn;
}
struct node * insert_end(struct node* head)
{
     struct node * newn=create_node();
     struct node * cur;
    if(head==NULL)
        head=newn;
    else
    {
        cur=head;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=newn;

    }
    return head;

}
void display_list( struct node * head)
{
     struct node * cur;
    if(head==NULL)
        printf("LIst is empty\n");
    else
    {
        cur=head;
         while(cur!=NULL)
         {
             printf("%d ",cur->data);
             cur=cur->link;
         }
    }

}

void split_list(struct node*head)
{
    struct node *list1=NULL;
    struct node *list2=NULL;
     struct node * newn;
     struct node * cur;

    struct node * cur2;
    struct node * cur3;
    if(head==NULL)
        printf("Original list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data%2 !=0)
            {
                newn=(struct node *)malloc(sizeof(struct node));
                newn->data=cur->data;
                newn->link=NULL;
                if(list1==NULL)
                    list1=newn;
                else
                {
                 cur2=list1;
                    while(cur2->link!=NULL)

                        cur2=cur2->link;
                    cur2->link=newn;
                }
            }
            else
            {
                newn=(struct node*)malloc(sizeof(struct node));
                newn->data=cur->data;
                newn->link=NULL;
                if(list2==NULL)
                    list2=newn;
                else
                {
                    cur3=list2;
                    while(cur3->link!=NULL)
                    {
                        cur3=cur3->link;
                    }
                        cur3->link=newn;
                }


        }
            cur=cur->link;

      }

    }
   display_list(list1);


}
void splitlist2(struct node*head)
{
    struct node *list1=NULL;
    struct node *list2=NULL;
     struct node * newn;
     struct node * cur;

    struct node * cur2;
    struct node * cur3;
    if(head==NULL)
        printf("Original list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data%2 !=0)
            {
                newn=(struct node *)malloc(sizeof(struct node));
                newn->data=cur->data;
                newn->link=NULL;
                if(list1==NULL)
                    list1=newn;
                else
                {
                 cur2=list1;
                    while(cur2->link!=NULL)

                        cur2=cur2->link;
                    cur2->link=newn;
                }
            }
            else
            {
                newn=(struct node*)malloc(sizeof(struct node));
                newn->data=cur->data;
                newn->link=NULL;
                if(list2==NULL)
                    list2=newn;
                else
                {
                    cur3=list2;
                    while(cur3->link!=NULL)
                    {
                        cur3=cur3->link;
                    }
                        cur3->link=newn;
                }


        }
            cur=cur->link;

      }

    }
   display_list(list2);


}
int main()
{
   struct node*head=NULL;
    int n,i;
    scanf("%d",&n);
    if(n>1)
    {
        for(i=0;i<n;i++)
        head=insert_end(head);
        printf("Original list is:\n");
        display_list(head);
         printf("\n\n");
         printf("List 1 is: \n");
         split_list(head);
         printf("\n\n");
        printf("List 2 is: \n");
        splitlist2(head);

    }
    else
        printf("Invalid input\n");
    return 0;
}
