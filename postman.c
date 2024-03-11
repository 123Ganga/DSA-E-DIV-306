#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//(House owner name, house number, street number, number of letters.)
struct node
{
    char owner[15],house[10];
    int street,letter;
    struct node *link;
};
struct node * create_node()
{
    struct node * newn=(struct node *)malloc(sizeof(struct node));
    if(newn==NULL)
    printf("Memmory is not allocated\n");
    else
    {
        scanf("%s%s%d%d",newn->owner,newn->house,&newn->street,&newn->letter);
        newn->link=newn;
    }
    return newn;
}
struct node * insert_end(struct node * head)
{
    struct node * newn=create_node();
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
void display_csll(struct node * head)
{
    struct node * cur=NULL;
    if(head==NULL)
        printf("CSLL is empty\n");
    else
    {
        cur=head;
        do
        {
         printf("%s %s %d %d\n",cur->owner,cur->house,cur->street,cur->letter);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
void display_letters(struct node * head)
{

    if(head==NULL)
        printf("no house with letter zero\n");
    else
    {
   struct node * cur=head;
    do
    {
        if(cur->letter>5)
             printf("%s %s %d %d\n",cur->owner,cur->house,cur->street,cur->letter);
            cur=cur->link;
    }
    while(cur!=head);
    }
}


struct node * delete_letter(struct node * head)
{
    struct node *cur=NULL,*prev=NULL,*temp=NULL;
    int status=0;
    if(head==NULL)
        return NULL;
   else if(head->link==head&&head->letter==0)
   {
      printf("%s\t%s\t%d %d\n",head->owner,head->house,head->street,head->letter);

       free(head);
       head=NULL;
   }
    else if(head->letter==0)
  {
        cur=head;
        while(cur->link!=head)
        cur=cur->link;

        temp=head;
         cur->link=head->link;
       head=head->link;
        status=1;
        free(temp);
    }
    else
    {
        cur=head;
        do
        {
            if(cur->letter==0)
            {

                status=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
        while(cur!=head);
    }
    if(cur==head)
       status=0;
    else
    {
          printf("%s %s %d %d\n",cur->owner,cur->house,cur->street,cur->letter);
        status=1;
        prev->link=cur->link;
    }
    if(status==0)
    {
      printf("No house to delete.\n");
    }


   return head;
  }

int main()
{
    struct node * head=NULL;
    int n;
    scanf("%d",&n);
    if(n>1)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        printf("Houses postman visits:\n");
        display_csll(head);
         printf("\nDeleted house:\n");
        head=delete_letter(head);
        printf("\nUpdated houses list:\n");
        display_csll(head);
        printf("\nHouses with more than 5 letters:\n");
        display_letters(head);

    }
    else
        printf("Invalid input");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
