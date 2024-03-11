#include<stdio.h>
#include<string.h>
#include<time.h>aa


/*
int length(char str[])
{
    if(str[0]=='\0')
    {

  return 0;
}
else
{

  return 1+length(str+1);
}
}
*/
int main()
{
clock_t t;
t=clock();
char *str,st;
str=&st;
printf("Enter string\n");
scanf("%s",str);
int l=strlen(str);
printf("Length of the string:%d\n",l);
t=clock()-1;
double time=(double)t/CLOCKS_PER_SEC;
printf("time taken to find the length of string is %f\n",time);
return 0;
}
