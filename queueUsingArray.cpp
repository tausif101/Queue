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
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}


void enqueue(Queue *q, int data)
{
    if(q->rear == q->size - 1)
        cout<<"Queue is full you cant insert any more element"<<endl;
    else
    {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        cout<<"Queue is empty";
    else
    {   q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void displayQueue(Queue q)
{
    for(int i = q.front+1; i<= q.rear; i++)
    {
        cout<<q.Q[i]<<endl;
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
    enqueue(&q,125);
    enqueue(&q,125);
    
    // dequeue(&q);
    displayQueue(q);
}