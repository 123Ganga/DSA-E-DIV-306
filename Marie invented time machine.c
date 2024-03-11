// c program to compute the leap year
/*
Name:Apoorva
Division:S
Roll no.:1910
Date:09/01/2023
*/
#include<stdio.h>
int main()
{
     int year ;
     printf("enter the year\n");
     scanf("%d",&year);
     if(year%400==0||year%40==10&&year%100!=0)
     printf("%d is a leap year\n",year);
     else
     printf("%d not a leap year\n",year);
     return 0;
}






