
#include<stdio.h>

int main()
{
    char c;
    printf("Enter characters\n");
    scanf(" %c",&c);
    if((c>=65 && c<=90)||(c>=97&& c<=122))
    {
        printf("The character is Alphabet\n");
    }
    else if(c>=48 && c<=57)
        printf("The character is digits\n");
    else if((c>=32 && c<=47)||(c>=58 && c<=64)||(c>=91 && c<=96)||(c>=123 && c<=126))
        printf("The character is special character\n");

    return 0;
}
