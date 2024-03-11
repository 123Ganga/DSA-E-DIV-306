// modular c programming to compute total price of the gas
/*
Name:Apoorva
division:S
*/
#include<stdio.h>
// function prototype
float total_price(float size,char gas_station);
int main()
{
float size,final_amount;
char gas_station;
printf("Enter size and gas station \n");
scanf("%f %c",&size,&gas_station);
//function call
final_amount=total_price(size,gas_station);
printf("total price is %f\n");
return 0;
}
// function definition
float total_price(float size,char gas_station)
{
    float gas_amount,gas_gst,total_price;
    char I,B,H;
    if(gas_station==I)
    {
      if(size==5||size==14.2)
        {
        gas_amount=(size*75.49);
        gas_gst=gas_amount+gas_amount*0.18;
        total_price=gas_gst+20;
        printf("Total price is%f\n");
        }
        else if(size==19)
    {
        gas_amount=(size*95.50);
        gas_gst=gas_amount+gas_amount*0.24;
        total_price=gas_gst+20;
         printf("Total price is%f\n");
    }
    }
    else if(gas_station=='B')
    {
       if(size==5||size==14.2)
       {
         gas_amount=(size*77.50);
         gas_gst=gas_amount+gas_amount*0.18;
         total_price=gas_gst+20;
         printf("Total price is%f\n");
    }
       else if(size==19)
       {
         gas_amount=(size*97.50);
         gas_gst=gas_amount+gas_amount*0.24;
         total_price=gas_gst+20;
         printf("Total price is%f\n");
      }
    }
    else if(gas_station=='H')
    {
      if(size==5||size==14.2)
    {

        gas_amount=(size*79.50);
        gas_gst=gas_amount+gas_amount*0.18;
        total_price=gas_gst+20;
         printf("Total price is%f\n");
    }
      else if(size==19)
        {
            gas_amount=(size*99.50);
        gas_gst=gas_amount+gas_amount*0.24;
        total_price=gas_gst+20;
         printf("Total price is%f\n");
        }
    }
        return total_price;
    }














