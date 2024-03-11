# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<math.h>
struct node
{
    char name[20];
    int points;
    struct node*link;
};
struct node *create_node()
{
 struct node *newn=(struct node*)malloc(sizeof(struct node));
 if(newn==NULL)
        printf("Memmory is not allocated\n");
 else
 {
     scanf("%s%d",newn->name,&newn->points);
     newn->link=newn;
 }
 return newn;
}
 struct node *insert_end( struct node *head)
 {
      struct node *cur=NULL;
   struct node *newn=create_node();
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
  struct node *insert_front( struct node *head)
  {
       struct node *cur=NULL;
       struct node*newn=create_node();
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
        head=newn;
       }
    return head;
  }
  int count_nodes( struct node *head)
  {
      int count=0;
      if(head==NULL)
        return count;
      else
      {
         struct node * cur=head;
          do
        {
            count++;
            cur=cur->link;
        }while(cur!=head);
      }
      return count;
  }
  void display_nodes( struct node *head)
  {

      if(head==NULL)
        printf("list is empty\n");
      else
      {
          struct node *cur=head;
          do
        {
            printf("%s %d\n",cur->name,cur->points);
            cur=cur->link;
        }while(cur!=head);
      }
  }
   struct node *insert_pos( struct node *head, struct node *newn,int pos)
  {
       struct node *cur=NULL;
       int count=count_nodes(head);
       if(head==NULL)
        head=newn;
       else if(pos==1)
       {
           cur=head;
           while(cur->link!=head)
           {
               cur=cur->link;
           }
           cur->link=newn;
        newn->link=head;
        head=newn;
       }
       else if(pos==count+1)
       {
            cur=head;
           while(cur->link!=head)
           {
               cur=cur->link;
           }
           cur->link=newn;
        newn->link=head;
       }
       else if(pos>1&&pos<=count)
       {
           cur=head;
           for(int i=1;i<pos-1;i++)
            cur=cur->link;
           newn->link=cur->link;
           cur->link=newn;
       }
       return head;
  }
   struct node *delete_pos( struct node *head,int pos)
  {
       struct node *cur=NULL,*temp,*prev;
       int count= count_nodes(head);
       if(head==NULL)
        return NULL;
        else if(head->link==head&&pos==1)
        {
            free(head);
            head=NULL;
        }
       else if(pos==1)
       {
           cur=head;
           while(cur->link!=head)
           {
               cur=cur->link;
           }
          temp=head;
          cur->link=head->link;
          head=head->link;
          free(temp);
       }
       else if(pos==count)
       {
            cur=head;
           while(cur->link!=head)
           {
               prev=cur;
               cur=cur->link;
           }
        prev->link=head;
        free(cur);
       }
       else if(pos>1&&pos<count)
       {
           cur=head;
           for(int i=1;i<pos;i++)
            {
                prev=cur;
                cur=cur->link;
            }
            prev->link=cur->link;
            free(cur);
       }
       return head;
  }
  struct node *delete_lowest(struct node *head)
  {
      struct node *cur=NULL,*prev=NULL,*temp;
      if(head==NULL)
        printf("list is empty\n");
        else if(head->link==head&&head->points<20)
        {
            free(head);
            head=NULL;
        }
        else if(head->points<20)
        {
             cur=head;
           while(cur->link!=head)
           {
               cur=cur->link;
           }
          temp=head;
          cur->link=head->link;
          head=head->link;
          free(temp);
        }
      else
      {
          cur=head;
          do
          {
              if(cur->points<20)
              break;
              prev=cur;
              cur=cur->link;
          }while(cur!=head);
          if(cur==head)
            printf("no people wiyh point 20\n");
            else
            {
                prev->link=cur->link;
                free(cur);
            }
      }
      return head;
  }
int main()
{
    struct node*head=NULL;
    int i,n,p,q;
    printf("enter n values\n");
    scanf("%d",&n);
    if(n>1)
    {
        printf("enter name and data\n");
        for(i=0;i<n;i++)
         head=insert_end(head);
         printf("list is:\n");
         display_nodes(head);
         printf("\nenter position\n");
        scanf("%d",&p);
      struct node *newn=create_node();
         head=insert_pos(head,newn,p);
        printf("\nlist after insertion\n");
         display_nodes(head);
        printf("\nenter position\n");
        scanf("%d",&q);
         printf("\nlist after deletion\n");
        head=delete_pos(head,q);
        display_nodes(head);
         printf("\nafter low deletion\n");
        head=delete_lowest(head);
        display_nodes(head);
    }
    return 0;

}
