#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define SIZE 100
struct queue
{
    int num[SIZE];
    int front,rear;
};
void enqueue(struct queue *qptr,int data)
{
    if(qptr->front==-1&&qptr->rear==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->num[qptr->rear]=data;
    }
    else if((qptr->rear+1)%SIZE==qptr->front)
        printf("Queue overflow\n");
        else
        {
            qptr->rear=(qptr->rear+1)%SIZE;
            qptr->num[qptr->rear]=data;
        }
}
int dequeue(struct queue *qptr)
{
    int data=-1;
      if(qptr->front==-1&&qptr->rear==-1)
    {
        return data;
    }
   else if(qptr->front==qptr->rear)
   {
    data=qptr->num[qptr->front];
       qptr->front=qptr->rear=-1;
   }
    else
    {
        data=qptr->num[qptr->front];
        qptr->front=(qptr->front+1)%SIZE;
    }
    return data;
}
void display(struct queue*qptr)
{
    int i;
    if(qptr->front==-1&&qptr->rear==-1)
        printf("Queue is empty");
    else
    {
        for(i=qptr->front;i!=qptr->rear;i=(i+1)%SIZE)
            printf("%d ",qptr->num[i]);
        printf("%d ",qptr->num[i]);
    }
}
int main()
{
    struct queue*qptr,q;
    qptr=&q;
    int m,n,o,data,i;
    int enqagain[SIZE];
    qptr->front=-1;
    qptr->rear=-1;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("enter data\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        enqueue(qptr,data);
    }
    printf("Enter m");
    scanf("%d",&m);
    printf("Enter o");
    scanf("%d",&o);
    for(i=0;i<o;i++)
    {
        scanf("%d",&enqagain[i]);
    }
    printf("Circular queue is:\n");
    display(qptr);

     for(i=0;i<m;i++)
    {
        data=dequeue(qptr);
         if(data==-1)
             printf("\nQueue underflow");
         else
             printf("\nDequeued = %d",data);
    }
    printf("\nCircular queue after dequeue is:\n");
    display(qptr);

    for(i=0;i<o;i++)
    {
        enqueue(qptr,enqagain[i]);
    }
    printf("\nCircular queue after enqueue is:\n");
    display(qptr);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
