#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],place[20],vehicle[20];
    int lapse;
    struct node * link;
};
 struct node * create_node()
 {
      struct node * newn=( struct node * )malloc(sizeof(struct node));
     if(newn==NULL)
         printf("Memmory is not allocated\n");
     else
     {
         scanf("%s%s%s%d",newn->name,newn->place,newn->vehicle,&newn->lapse);
         newn->link=newn;
     }
     return newn;
 }
 struct node * insert_end( struct node * head)
 {
      struct node * newn=create_node();
      struct node * cur=NULL;
     if(head==NULL)
         head=newn;
     else
     {
         cur=head;
      while(cur->link!=head)
      {
         cur=cur->link;
      }
         cur->link=newn;
         newn->link=head;
     }
     return head;
 }
void display_csll( struct node * head)
{
     struct node * cur=NULL;
    if(head==NULL)
        printf("empty.");
    else
    {
        cur=head;
        do
        {
             if(strcmp(cur->place,"dharwad")==0&&strcmp(cur->place,"hubli")==0)
             {
                  printf("%s %s %s %d\n",cur->name,cur->place,cur->vehicle,cur->lapse);
             }

            cur=cur->link;
        }
        while(cur!=head);
    }
}
void display_list( struct node * head)
{
     struct node * cur=NULL;
    if(head==NULL)
        printf("empty.\n");
    else
    {
        cur=head;
        do
        {
             if(strcmp(cur->place,"dharwad")!=0&&strcmp(cur->place,"hubli")!=0)
             {
           printf("%s %s %s %d\n",cur->name,cur->place,cur->vehicle,cur->lapse);
             }

            cur=cur->link;
        }
        while(cur!=head);
    }
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
struct node *search_hero(struct node *head)
{
  struct node *temp,*cur,*prev;
 if(head==NULL)
        printf("list is empty\n");
else if(head->link==head&&strcmp(head->vehicle,"hero")!=0)
{
    free(head);
    head=NULL;
}
else if(strcmp(head->vehicle,"hero")!=0)
{
    temp=head;
    head=head->link;
    free(temp);
}
 else
 {
     cur=head;
     do
     {
        if(strcmp(cur->vehicle,"hero")!=0)
         break;
     prev=cur;
     cur=cur->link;
     }while(cur!=head);
     if(cur==head)
        printf("you are disqualified\n");
    else
        {
            prev->link=cur->link;
            free(cur);
        }
}
return head;
}
void max_laps(struct node*head)
{
    int max=-1;
    struct node *cur=NULL,*high;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        do
        {
           if(cur->lapse>max)
           {
               max=cur->lapse;
                high=cur;
           }
                cur=cur->link;
        }while(cur!=head);
        printf("The winner\n");
          printf("%s %s %s %d\n",high->name,high->place,high->vehicle,high->lapse);
    }
}
/*
a dharwad hero 2
d hubli honda 99
e dharwad hero 34
g haveri hero 67
f tadas hero 89
*/
int main()
{
    struct node* head=NULL,*cur;
    int n,i,m;
    printf("Enter n and m values\n");
    scanf("%d%d",&m,&n);
    if(m>0&&n>0)
    {
        printf("enter name,place,vehicle,lapse\n");
        for(i=0;i<m;i++)
        {
            head=insert_end(head);
        }
        for(i=0;i<n;i++)
            {

            head=insert_end(head);


            }
            printf("Hubli list:\n");
             display_csll(head);
            printf("Dharward list:\n");
            display_list(head);
            int count=count_list(head);
            printf("number of participants are:%d\n",count);
            head=search_hero(head);
             display_csll(head);
           max_laps(head);
    }
    return 0;
}
