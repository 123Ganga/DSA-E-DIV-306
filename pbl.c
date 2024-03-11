#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
struct node* insert_end(struct node*head)
{
 struct node*newn=create_node();
 if(head==NULL)
        head=newn;
 else
 {
    struct node* cur=head;
     while(cur->link!=NULL)
        cur=cur->link;
     cur->link=newn;
 }
 return head;
}
void display_nodes(struct node *head)
{
       struct node*cur=NULL;
    if(head==NULL)
        printf("printf list is empty\n");
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
void split_nodes(struct node*head)
{
    struct node*cur=NULL,*list2=NULL,*list1=NULL,*cur2=NULL,*cur3=NULL,*newn;
    if(head==NULL)
    printf("list is empty\n");
    else
        {
           cur=head;
    while(cur!=NULL)
    {
        if(cur->data%2 !=0)
        {
             newn=(struct node*)malloc(sizeof(struct node));
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
 display_nodes(list1);
}
void split_list(struct node*head)
{
    struct node*cur=NULL,*list2=NULL,*list1=NULL,*cur2,*cur3,*newn;
    if(head==NULL)
    printf("Original list is empty\n");
    else
        {
           cur=head;
    while(cur!=NULL)
    {
        if(cur->data%2 !=0)
        {
             newn=(struct node*)malloc(sizeof(struct node));
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
             newn->price=cur->price;
             newn->link=NULL;
             if(list2==NULL)
                list2=newn;
             else
             {
                 cur3=list2;
                 while(cur3->link!=NULL)
                    cur3=cur3->link;
                 cur3->link=newn;
             }
        }
        cur=cur->link;
    }

}
 display_nodes(list2);
}

int main()
{
   struct node *head=NULL;
   int n,i;
   printf("enter n value\n");
   scanf("%d",&n);
   if(n>1)
   {
       printf("enter data\n");
       for(i=0;i<n;i++)
        head=insert_end(head);
        printf("original nodes\n");
        display_nodes(head);
        printf("\nlist 1:\n");
       split_nodes(head);
       printf("\nlist 2:\n");
       split_list(head);

   }
   else
    printf("Invalid input");
   return 0;
}
