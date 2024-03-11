#include<stdio.h>
int main()
{ int i,j,p,q;
for(p=1;p<=6;p++)
{
for(q=1;q<=6;q++)
{
    if(q<p)
    {
        printf(" ");

    }
    else
    {

         printf(" *");
    }


}
printf("\n");
}
for(j=6;j>0;j--)
{
for(i=0;i<=6;i++)
{
    if(i<j)
    {
        printf(" ");

    }
    else
    {
         printf("* ");

    }
}
printf("\n");
}



return 0;
}

