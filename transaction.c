#include<stdio.h>
struct transaction
{
    char from_no[50];
    char to_no[70];
    int transaction_id;
    float amount;
    int day,month,year;
    int date,min,sec;
};

void read_transaction(struct transaction *tptr)
{
    printf("Enter the transaction details\n");
    printf("Enter the from number");
     scanf("%s",tptr->from_no);
    printf("Enter To number");
     scanf("%s",tptr->to_no);
    printf("Enter transaction ID");
    scanf("%d",&tptr->transaction_id);
    printf("Enter amount");
    scanf("%f",&tptr->amount);
    printf("Enter day,month,year of transaction");
    scanf("%d%d%d",&tptr->day,&tptr->month,&tptr->year);
    printf("Enter date,min,sec of transaction");
     scanf("%d%d%d",&tptr->date,&tptr->min,&tptr->sec);

}
void display_transaction(struct transaction *tptr)
{
    printf("The transaction details:\n");
    printf("The from no.:%s\n",tptr->from_no);
    printf("The to no.:%s\n",tptr->to_no);
    printf("The transaction id:%d\n",tptr->transaction_id);
    printf("Amount: %f\n",tptr->amount);
    printf("day:%d month:%d year:%d\n",tptr->day,tptr->month,tptr->year);
    printf("Date:%d min:%d sec:%d\n",tptr->date,tptr->min,tptr->sec);
}

int main()
{
    struct transaction t;
    struct transaction *tptr;
    tptr=&t;
   read_transaction(tptr);
   display_transaction(tptr);
    return 0;

}
