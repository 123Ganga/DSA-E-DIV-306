#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *link;

}*NODE;
NODE create_node()
{
    NODE newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
    printf("Error: memory is not allocated\n");
    else
    {
        printf("Enter data: \n");
        scanf("%d",&newn->link);
        newn->link=NULL;
    }
    return newn;
}
NODE insert_end(NODE head)
{
    NODE newn=create_node();
    if(head==NULL)
       head=newn;
    else
    {
        NODE cur=head;
        NODE newn;
        while(cur->link!=NULL)
        {
            cur=cur->link;
            cur->link=newn;
        }
        return head;
    }
}
void Display_list(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("Error:SLL is empty\n");
    else
    {
        cur=head;
    while(cur->link!=NULL)
        {
            printf("%d-> \n",cur->data);
            cur=cur->link;
        }
        printf("\n");
    }
}
NODE insert_front(NODE head)
{
    NODE newn=create_node();
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        newn->link=head;
        head=newn;
    }
    return head;

}
int main()
{
    NODE head=NULL;
    int ch;
    printf("SLL list \n");
    printf("Enter 1.insert_end 2.Display 3.insert_front 4.exit\n");
    while(1)
    {
        printf("enter a choice\n");
        scanf("%d",&ch);


    switch(ch)
    {
       case 1:head=insert_end(head);
              printf("Insert end is successful\n");
              break;
      case 2:Display_list(head);
              break;
      case 3:head=insert_front(head);
          printf("Insert front is successful\n");
              break;
      case 4:exit(0);
      default:printf("Invalid input\n");
             break;

    }
      }
    return 0;
}
