// c program to compute maximum of 3 numbers
/*
Name: Apoorva
Division:S
Date:09/01/2023
Roll no.:1910
*/
#include<stdio.h>
int main()
{
    int num1,num2,num3,num4;
    printf("Enter 3 numbers\n");
    scanf("%d%d%d",&num1,&num2,&num3);
    if(num1>num3)
    {
        if(num1>num3)
            printf("%d is maximum\n",num1);
        else
            printf("%d is maximum \n",num3);
    }
       else
       {
        if(num2>num3)
        printf("%d is maximum\n",num2);
        else
        printf("%d is maximum\n",num3);
       }
return 0;
}//end of main
