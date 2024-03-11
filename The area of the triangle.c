#include<stdio.h>
// function prototype
float area(float b,float h);
// main function
int main()
{
    float b,h,areal;
    printf("Enter the base and height of the triangle\n");
    scanf("%f%f",&b,&h);
    // function call
    areal=area(b,h);
    printf("area is %0.2f\n",areal);
    return 0;
}//end of main
// function definition
float area(float b,float h)
{
    float area1;
    area1=(0.5)*b*h;
    return area1;
}
