#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// (name, home town, mobile number)
struct node
{
 char name[20],home[20],mob[11];
   struct node *link;
};
 struct node * create_node()
 {
      struct node * newn=( struct node * )malloc(sizeof(struct node));
     if(newn==NULL)
         printf("Memmory is not allocated\n");
     else
     {
         scanf("%s%s%s",newn->name,newn->home,newn->mob);
         newn->link=newn;
     }
     return newn;
 }
struct node * insert_end(struct node * head,struct node*newn)
{

    struct node * cur=NULL;
    if(head==NULL)
        head=newn;
    else
    {
        cur=head;
        while(cur->link!=head)
        cur=cur->link;
        cur->link=newn;
        newn->link=head;
    }
    return head;
}
int count_list(struct node * head)
{
    struct node * cur=NULL;
    int count=0;
    if(head==NULL)
        return count;
    else
    {
        cur=head;
     do
       {
           count++;
           cur=cur->link;
       }
        while(cur!=head);
    }

    return count;
}

struct node* delete_front(struct node* head)
{
    struct node* cur=NULL,*temp=NULL;
    if(head==NULL)
    printf("List after drop out: Empty.");
    if(head->link==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        while(cur->link!=head)
        cur=cur->link;

        temp=head;
        cur->link=head->link;
        head=head->link;
        free(temp);

    }
    return head;
}
void display_csll( struct node * head)
{
     struct node * cur=NULL;
    if(head==NULL)
        printf("Empty.\n");
    else
    {
        cur=head;
        do
        {
         printf("%s %s %s\n",cur->name,cur->home,cur->mob);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
struct node* merge_list(struct node* head,struct node*list2)
{
    struct node* cur=NULL;
    if(head==NULL&& list2==NULL)
     return NULL;
       else if(head==NULL)
            return list2;
    else if(list2==NULL)
        return head;

    else
    {
        cur=head;
        while(cur->link!=head)
        cur=cur->link;
        cur->link=list2;
        cur=list2;
        while(cur->link!=list2)
        cur=cur->link;
        cur->link=head;
    }
    return head;
}

int main()
{
    struct node * head=NULL,*list2=NULL;
    int i;
    int n,k,l;
    scanf("%d",&n);
    if(n>0)
    {

    for(i=0;i<n;i++)
    {
    struct node * newn=create_node();
       head=insert_end(head,newn);
    }


         scanf("%d",&k);
       for(int i=0;i<k;i++)
        head=delete_front(head);
         scanf("%d",&l);

       for(int i=0;i<l;i++)
       {
         struct node * newn=create_node();
         list2=insert_end(list2,newn);
       }
        printf("List after drop out: \n");
         display_csll(head);
       head=merge_list(head,list2);
        printf("\nList after new additions:\n");
        display_csll(head);
        int c=count_list(head);
        printf("\nTotal people going on trip is: %d",c);
     }
    else
        printf("Invalid input");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
