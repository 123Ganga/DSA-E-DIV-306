#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct traveller
{
    char name[10],source[10],destination[10];
    float price;
    int hr,min;
}T;
/*

appu sagr shivamogga 456.89 12 30
appu shanwad shiva 456.89 12 30
appu simla shiv 456.89 12 30
appu shivamogga sagar 456.89 12 30
appu shimla shivamogga 456.89 12 30
appu shikaripura shivamogga 456.89 12 30
appu sagar shivamogga 456.89 12 30
appu navanagar shivamogga 456.89 12 30
appu thalguppa shivamogga 456.89 12 30
appu hebsur shivamogga 456.89 12 30
appu padesur shivamogga 456.89 12 30
arun sagar nulvi 345 11 45


*/
void read_traveller(T*tptr,int n)
{
    int i;
    printf("Enter name,source,destination,price,time\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%f%d%d",tptr->name,tptr->source,tptr->destination,&tptr->price,&tptr->hr,&tptr->min);
        tptr++;
    }
}
void display_traveller(T*tptr,int n)
{
    int i;
    printf("name\tsource\tdestination\tprice\ttime\n");
    for(i=0;i<n;i++)
    {
       printf("%s\t%s\t%s\t%0.2f\t%d:%d\n",tptr->name,tptr->source,tptr->destination,tptr->price,tptr->hr,tptr->min);
        tptr++;
    }
}
void dis_travel(T*tptr,int n)
{
    int i,status=0,count;
    printf("The traveller who starting their journey at same point\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(tptr->source,(tptr+i)->source)==0)
        {
          count++;
          status=1;
        }
   }
    if(status=1)
    {

        printf("%s\t%s\t%s\t%0.2f\t%d:%d\n",tptr->name,tptr->source,tptr->destination,tptr->price,tptr->hr,tptr->min);
    }
}
void search_travel(T*tptr,int n,char customer[20])
{
    int i,status=0,count=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(tptr->name,customer)==0)
        {
            count++;
          status=1;

        }
        tptr++;
    }
    if(status==1)
    {
        printf("count: %d\n",count);
    if(count>10)
        printf("cost is rupees zero\n");
    }

}
int main()
{
    T*tptr;
    int n;
    char place[20];
    char customer[20];
    printf("Enter number of customers\n");
    scanf("%d",&n);
    tptr=(T*)malloc(n*sizeof(T));
    read_traveller(tptr,n);
    display_traveller(tptr,n);
    dis_travel(tptr,n);
     printf("Enter customer\n");
    scanf("%s",customer);
    search_travel(tptr,n,customer);
    free(tptr);
    return 0;

}
