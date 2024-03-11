#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct water
{
    char place[20];
    int water_c,height;
    float price;
    int hr,min;
}W;
void read_water(W*wptr,int n)
{
    int i;
    printf("Enter place,water_c,height,price,time\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d%f%d%d",wptr->place,&wptr->water_c,&wptr->height,&wptr->price,&wptr->hr,&wptr->min);
        wptr++;
    }
}
void display_water(W*wptr,int n)
{
    int i;
    printf("place\twater_c\theight\tprice\ttime\n");
    for(i=0;i<n;i++)
    {
       printf("%s\t%d\t%d\t%0.2f\t%d:%d\n",wptr->place,wptr->water_c,wptr->height,wptr->price,wptr->hr,wptr->min);
        wptr++;
    }
}
void sort_water(W*wptr,int n)
{
    int i,j,min_index;
    W temp;
    printf("Sorting alphabetically w r t their locality\n");
    for(i=0;i<n-1;i++)
    {
       min_index=i;
       for(j=i+1;j<n;j++)
       {
           if(strcmp((wptr+j)->place,(wptr+min_index)->place)<0)
              {
                  min_index=j;
              }
       }
       temp=*(wptr+i);
       *(wptr+i)=*(wptr+min_index);
       *(wptr+min_index)=temp;
    }

}
void cal_water(W*wptr,int n)
{
    int i,sum =0;
    for(i=0;i<n;i++)
    {
        sum=sum+wptr->water_c;
        wptr++;
    }
    printf("water_capacity =%d\n",sum);
}
int main()
{
    W*wptr;
    int n;
    printf("Enter num of water tanks\n");
    scanf("%d",&n);
    wptr=(W*)malloc(n*sizeof(W));
    read_water(wptr,n);
    display_water(wptr,n);
    cal_water(wptr,n);
    sort_water(wptr,n);
    display_water(wptr,n);
    free(wptr);
    return 0;
}
