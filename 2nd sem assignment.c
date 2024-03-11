 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
     int data;
     struct node *link;
 };
  struct node *create_node()
  {
    struct node *newn=( struct node *)malloc(sizeof( struct node));
    if(newn==NULL)
        printf("memory is not allocated\n");
    else
    {
        scanf("%d",&newn->data);
        newn->link=NULL;
    }
    return newn;
  }
   struct node *insert_end( struct node *head,struct node *newn)
   {

    if(head==NULL)
        head=newn;
    else
    {
        struct node *cur=head;
    while(cur->link!=NULL)
         {
             cur=cur->link;
         }
         cur->link=newn;

    }
    return head;
   }


void display_list( struct node *head)
   {

        struct node *cur=head;
       if(head==NULL)
        printf("list is empty\n");
       else
       {

           while(cur!=NULL)
           {

                printf("%d ",cur->data);
                cur=cur->link;
           }
       }

   }


   struct node * reverse_list(struct node *head)
   {

       struct node *cur=head,*temp=head,*cur1,*cur2;
       if(head==NULL)
        printf("List is empty\n");
    else if(head->link==NULL)
          return head;
       else
       {
           struct node*prev=NULL;

       struct node *next=NULL;
       while(cur!=NULL)
       {
           if(cur->data%2==0)
               {
                   while(temp!=NULL&&temp->data%2==0)
                   {

                   next=temp->link;
                   temp->link=prev;

                   prev=temp;

                   temp=next;

                   }
head=prev;
                      cur=temp;

                     while(prev!=NULL)
                     {
                          printf("%d ",prev->data);
                         prev=prev->link;
                     }

            }


            else{

               while(temp->data%2!=0)
                {
                    printf("%d ",temp->data);
                   temp=temp->link;
                }
                 cur=cur->link;

            }

       }

}

   return head;
   }


   int main()
   {
        struct node *head=NULL;
        int n,i;
        printf("Enter the n value\n");
        scanf("%d",&n);
        if(n>1)
        {
            for(i=0;i<n;i++)
                {
                struct node *newn=create_node();
              head=insert_end(head,newn);
                }
                head=reverse_list(head);

        }
        else
            printf("invalid input\n");
        return 0;
   }
// 8 76 48 62 28 7 9 4 6
