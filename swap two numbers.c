#include<stdio.h>
void swap(int *aptr,int *bptr)
{
    int temp;
  temp=*aptr;
  *aptr=*bptr ;
  *bptr=temp;
}


int main()
{
 int a,b;
 int *aptr,*bptr;
 aptr=& a;
 bptr=& b;
 printf("address of the number is %x and %x\n",aptr,bptr);
 printf("Enter a and b\n");
 scanf("%d%d",aptr,bptr);
 printf("before swaping the numbers are %d and %d\n",a,b);
 swap(aptr,bptr);
 printf("after swapping %d and %d\n",a,b);
 return 0;
}
