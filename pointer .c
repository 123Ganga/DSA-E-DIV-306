#include<stdio.h>
#include<stdlib.h>
void read_array(int *ptra,int *pn)
{
  int i;
  for(i=0;i<*pn;i++)
  {
  scanf("%d",ptra);
  ptra++;
  }
}
void display_array(int *ptra,int *pn)
{
  int i;
  for(i=0;i<*pn;i++)
  {
  printf("%d\t",*ptra);
  ptra++;
  }
}
int sum_array(int *ptra,int *pn)
{
 int i,sum=0;
 for(i=0;i<*pn;i++)
 {
   sum+=*ptra;
   ptra++;
 }
 return sum;
}
int* find_max(int *ptra,int *pn)
{
 int i,*pmax=NULL,max=0,day;
 for(i=0;i<*pn;i++)
 {
 if(max<*ptra)
 {
   max=*ptra;
   pmax=ptra;
   day=i+1;
 }

 ptra++;
 }
 printf("day is %d\n",day);
return pmax;
}
int main()
{
  int n,sum,*pm;
  int *ptra=NULL,*pn=NULL;
  pn=&n;
  printf("Enter the values of n\n");
  scanf("%d",pn);
  ptra=(int *)malloc(n*sizeof(int));
  if(ptra==NULL)
  {
   printf("memory not allocated\n");
  }
else
{
  read_array(ptra,pn);
  display_array(ptra,pn);
 sum= sum_array(ptra,pn);
  printf("sum is %d\n",sum);
  pm=find_max(ptra,pn);
  printf("at adress %x maximum element is %d\n",pm,*pm);
}
free(ptra);
return 0;

}
