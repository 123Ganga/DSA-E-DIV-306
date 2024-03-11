#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct car
{
    char TRN[20],CO[20],CN[20];
    struct car *link;
}*CAR;

CAR create_node()
{
    CAR newn=(CAR)malloc(sizeof(struct car));
    if(newn==NULL)
    {
        printf("Error:memmory is not allocated\n");
    }
    else
    {
        printf("Enter TRN,CO,CN: \n");
        scanf("%s%s%s",newn->TRN,newn->CO,newn->CN);
        newn->link=NULL;
    }
    return newn;

}
CAR insert_front(CAR head)
{
    CAR cur;
    CAR newn=create_node();
    if(head==NULL)
       head=newn;
    else
    {
        cur=head;
        while(cur->link!=NULL)
            {
            cur=cur->link;
        }
        cur->link=newn;

    }
    return head;

}
void Display_list(CAR head)
{
    CAR cur;
    if(head==NULL)
        printf("Error:SLL is empty\n");
    else
   {
     cur=head;
    while(cur!=NULL)
    {
        printf("%s-> %s-> %s \n",cur->TRN,cur->CO,cur->CN);
        cur=cur->link;
    }
    }
}
CAR delete_front(CAR head)
{
    CAR cur;
    if(head==NULL)

        printf("Delete front error:LIst empty\n");
    else if(head->link==NULL)
    {
        printf("Deleted %s %s %s\n",head->TRN,head->CO,head->CN);
        free(head);
        head=NULL;
    }
    else
    {
       cur=head;
    head=cur->link;
    printf("Deleted %s %s %s\n",cur->TRN,cur->CO,cur->CN);
    free(cur);

    }
    return head;
}
CAR delete_end(CAR head)
{
    CAR cur;
    if(head==NULL)
        printf("List is empty\n");
     else if(head->link==NULL)
    {
        printf("Deleted %s %s %s\n",head->TRN,head->CO,head->CN);
        free(head);
        head=NULL;
    }
    else
    {
        CAR prev=NULL,cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("Deleted %s %s %s\n",cur->TRN,cur->CO,cur->CN);
    free(cur);
    prev->link=NULL;

    }
    return head;
}
int count_node(CAR head)
{
    CAR cur;
   int count=0;
   cur=head;
    while(cur!=NULL)
    {
        count++;
        cur=cur->link;
    }
    return count;
}
int search(CAR head)
{
    int status=0;
    char key_no[10];
    printf("Enter key num\n");
    scanf("%s",key_no);
    CAR cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->TRN,key_no)==0)
        {
            status=1;
            printf("%s %s %s\n",cur->TRN,cur->CO,cur->CN);
        }
         cur=cur->link;

    }
        return status;


}
int search_list(CAR head)
{
    int status=0;
    char car[10];
    printf("Enter car owner name\n");
    scanf("%s",car);
    CAR cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->CO,car)==0)
        {
            status=1;
             printf("%s %s %s\n",cur->TRN,cur->CO,cur->CN);
        }
        cur=cur->link;
    }
   return status;

}
CAR insert_func(CAR head,int pos)
{
    CAR newn=create_node();
    int count=count_node(head);

    if(head==NULL&&pos==1)
    head=newn;
    else if(pos==1)
    {
        newn->link=head;
        head=newn;
    }
    else if(pos==count+1)
    {
        CAR cur=head;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=newn;
    }
    else if(pos>1&&pos<=count)
    {
       CAR cur=head,next;
       int i;
        for(i=0;i<pos-1;i++)
        cur=cur->link;
        next=cur->link;
        cur->link=newn;
        newn->link=next;
    }
    else if(pos>count+1)
        printf("Invalid possition\n");
        return head;
}
CAR delete_position(CAR head,int pos)
{
    int count=count_node(head);
    if(head==NULL)
        printf("List is empty\n");
    else if(pos==1)
    {
        printf("delete %s %s %s\n",head->TRN,head->CO,head->CN);
        free(head);
        head=NULL;
    }
    else if(pos==count)
    {
       CAR cur=head,prev=NULL;
       while(cur->link!=NULL)
       {
           prev=cur;
           cur=cur->link;
       }
        free(cur);
        prev->link=NULL;
    }
    else if(pos>1&&pos<=count)
    {
        CAR cur=head,prev=NULL,next=NULL;
         int i;
        for(i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        next=cur->link;
        cur->link=prev;
        prev->link=next;
        free(cur);

    }
    return head;
}


int main()
{
    CAR head=NULL,count=NULL,cur;
    int ch,c,pos,status;

    printf("SLL list menu\n");
    printf("press 1.insert_front  2.Display 3.Delete_front 4.delete_end 5.count 6.search 7 search car name 8.insert function 9.exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:head=insert_front(head);
                   printf("Insert front successfull\n");
                   break;
            case 2: Display_list(head);
                   break;
            case 3:head=delete_front(head);
                   printf("delete front successfull\n");
                   break;
            case 4:head=delete_end(head);
                   printf("delete end succesfull\n");
                   break;
             case 5:c=count_node(head);
                    printf("num of nodes %d\n",c);
                    break;
            case 6:status=search(head);
                   if(status==1)
                    printf("search succesfull\n");
                    else
                   printf("search unsuccesfull\n");
                   break;
            case 7:status=search_list(head);
                   if(status==1)
                    printf("search succesfull\n");
                   else
                    printf("search unsuccesfull\n");
                   break;
            case 8:printf("enter position\n");
                    scanf("%d",&pos);
                   head=insert_func(head,pos);
                   printf("insert function succesfull\n");
                   break;
            case 9:printf("Enter position \n");
                   scanf("%d",&pos);
                   head=delete_position(head,pos);
                   printf("DElete successful\n");
                   break;
             case 10:exit(0);
             default :printf("invalid choice\n");
        }

    }


    return 0;

}
