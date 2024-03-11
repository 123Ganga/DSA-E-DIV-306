#include <stdio.h>

// function prototype
void print_fibonaccia(int n);
int main()
{
    int n;
    printf("Enter the number of terms");
    scanf("%d",&n);
    printf("Fibonnacia series : ");
    print_fibonaccia(n);
    return 0;

}
void print_fibonaccia(int n)
{
    int i,next_term,t1=0,t2=1;
    for(i=1;i<=n;i++)
    {
      next_term=t1+t2;
      t1=t2;
      t2=next_term;
      printf("%d ",next_term);
    }
}
