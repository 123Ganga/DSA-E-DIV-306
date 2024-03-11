// modular c program to compute temperature in celsius and print message
/*
Name:Apoorva
Division:S
Roll no.:1910
Date:17/01/2023
*/
#include<stdio.h>
// function prototype
void decide_temperature(float c);
int main()
{
    float f,c;
    printf("Enter temperature in farenhiet\n");
    scanf("%f",&f);
    c=(0.55)*(f-32);
    printf("Temperature in celsius is %f\n",c);
    decide_temperature(c);
    return 0;
}
    void decide_temperature(float c)
    {
        if(c<0)
            printf("Freezing\n");
        else if(c>=0&&c<10)
        printf("Very cold\n");
        else if(c>=10&&c<20)
            printf("cold\n");
        else if(c>=20&&c<30)
            printf("Normal\n");
        else if(c>30&&c<40)
            printf("Hot\n");
        else
            printf("Very Hot\n");
    }



