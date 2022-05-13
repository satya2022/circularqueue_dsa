#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int);
void dequeue();
void display();

void main()
{
    enqueue(3);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    dequeue();
    enqueue(10);
    enqueue(10);
    display();
}

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        /*
        // why i am using that function
        // one codition also i have if (front ==0 && rear==N-1)then also queue is ful
        // that codition iscontaing both type
        */
        printf("queue is full");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        // printf("%d", queue(front));
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if (front==rear)
    {
   front =rear =-1;
    }
    
    else
    {
        printf("queue is =");
        while (i != rear)
        {
            printf("%d", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d",queue[rear]);
    }
}