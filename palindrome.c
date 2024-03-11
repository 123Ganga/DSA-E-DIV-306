#include<stdio.h>
int palindrome(int n);
int main()
{
int n,rev;
printf("Enter the number");
scanf("%d",&n);
if(n>0)
{
     rev=palindrome(n);
     printf("%d ",rev);
    if(rev==n)
    {
        printf("palindrome");
    }
    else
        printf("not palindrome");

}

else
    printf("invalid input");
    return 0;
}
int palindrome(int n)
{
  int i,rem,rev=0;
  while(n!=0)
    {
      rem=n%10;
      rev=rev*10+rem;
      n=n/10;
    }
    return rev;

}





