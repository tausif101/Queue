#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void createQueue(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

void enqueue(Queue *q, int x)
{
    if((q->rear+1)%q->size == q->front)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear = (q->rear +1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        cout<<"Queue is empty!"<<endl;
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;    
}


void display(Queue q)
{
    int i = q.front +1;
    while(i != (q.rear+1)%q.size)
    {
        cout<<q.Q[i]<<endl;
        i = (i+1)%q.size;
    }
}


int main()
{   
    Queue q;
    
    createQueue(&q, 5);
    enqueue(&q,121);
    enqueue(&q,122);
    enqueue(&q,123);
    enqueue(&q,124);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,125);
    enqueue(&q,125);
    
    display(q);

    return 0;
}