// modular c program to compute the total bill
/*
Name:Apoorva
Division:S
roll no.:1910;
*/
#include<stdio.h>
// function prototype
float total_bill(float PA,float DA,char type_of_item);
int main()
{
  float PA,DA,Bill;
  char type_of_item;
  printf("Enter the Type of item and PA\n");
  scanf(" %c%f",&type_of_item,&PA);
  // function call
  Bill=total_bill(PA,DA,type_of_item);
  printf("total bill is %f\n",total_bill);
  return 0;
}
// function definition

float total_bill(float PA,float DA,char type_of_item)
{
char T,C;
float Bill;
if(type_of_item==T)
{
if(PA>=1||PA<=1000)
{
    printf(" No discount\n");
}
else if (PA>1000)
{
    DA=0.07*(PA-1000);
    Bill=PA+DA;
    printf("Bill is %f\n",Bill);
}
}
else if(type_of_item==C)
{
    if(PA>0||PA<=5000)
    {
        DA=0.03*PA;
        Bill=PA+DA;
        printf("Bill is %f\n",Bill);
    }
    if(PA>5000)
    {
        DA=0.15*(PA-5000);
        Bill=PA+DA;
        printf("Bill is %f\n",Bill);

    }
    return(Bill);

}
 }






