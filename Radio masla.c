#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct winners
{
    char name[10],address[10],village[10],team_name[10];
    int points;

}W;
// A B C D 12 E F G H 34 J K L N 35 Q R T S 45  A B C D 90 E F G H 89 J K L N 8
 void read_win(W*wptr,int n)
 {
     int i;
     printf("Enter name,address,village,team_name,points\n");
     for(i=0;i<n;i++)
     {
         scanf("%s%s%s%s%d",wptr->name,wptr->address,wptr->village,wptr->team_name,&wptr->points);
         wptr++;
     }
 }

void display_win(W*wptr,int n)
 {
     int i;
     printf("Name\taddress\tvillage\tteam_name\tpoints\n");
     for(i=0;i<n;i++)
     {
         printf("%s\t%s\t%s\t%s\t%d\n",wptr->name,wptr->address,wptr->village,wptr->team_name,wptr->points);
         wptr++;
     }

 }
void sort_win(W *wptr,int n)
{
    int i,min_index,j;
    W temp;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if((wptr+j)->points>(wptr+min_index)->points)
            {
                min_index=j;
            }
        }
        temp=*(wptr+i);
        *(wptr+i)=*(wptr+min_index);
        *(wptr+min_index)=temp;
    }

    printf("The second winner is\n");
    printf("%s\t%s\t%s\t%s\t%d\n",(wptr+n-1)->name,(wptr+n-1)->address,(wptr+n-1)->village,(wptr+n-1)->team_name,(wptr+n-1)->points);

}
void dis_sort(W *wptr,int n)
{
    int i;
    printf("The first winner \n");
     printf("Name\taddress\tvillage\tteam_name\tpoints\n");
     for(i=1;i<2;i++)
     {
         printf("%s\t%s\t%s\t%s\t%d\n",(wptr+i)->name,(wptr+i)->address,(wptr+i)->village,(wptr+i)->team_name,(wptr+i)->points);
         wptr++;
     }

}

 int main()
 {
    W *wptr;
    int n;
    printf("Enter the num of competator\n");
    scanf("%d",&n);
    wptr=(W*)malloc(sizeof(W));
    read_win(wptr,n);
    display_win(wptr,n);
    sort_win(wptr,n);
    display_win(wptr,n);
    dis_sort(wptr,n);
    free(wptr);
    return 0;
}

