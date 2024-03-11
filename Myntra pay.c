// modular c programming to compute salary of the employee
/*
Name:Apoorva
Roll no.:1910
Division:S
*/
#include<stdio.h>
// function prototype
float payment(float increment, float salary,char designation);
int main()
{
    float increment,salary,Total_salary;
    char designation;
    printf("Enter Designation and salary \n");
    scanf(" %c%f",&designation,&salary);
    // function call
    Total_salary=payment(increment,salary,designation);
    printf("Total_salary is %f",Total_salary);
    return 0;
}
//function definition
float payment(float increment,float salary,char designation)
{
  char S,A,P;
  float Total_salary;
if(designation==S)
{
    if(salary<=200000&&salary>=100000)
    {
        increment=0.05*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    else if(salary<=100000&&salary>=70000)
    {
      increment=0.03*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    else if(salary<=70000&&salary>=40000)
    {
            increment=0.03*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    if(designation==A)
    {
        if(salary<=160000&&salary>=80000)
    {
        increment=0.04*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    if(salary<=80000&&salary>=50000)
    {
        increment=0.05*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    }
    if(designation==P)
    {
        if(salary<=200000&&salary>=100000)
    {
        increment=0.09*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    if(salary<=100000&&salary>=60000)
    {
        increment=0.07*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    if(salary<=60000&&salary>=40000)
    {
        increment=0.05*salary;
        Total_salary=increment+salary;
        printf("Total_salary is %f\n",Total_salary);
    }
    }
    return(Total_salary);
}




}


