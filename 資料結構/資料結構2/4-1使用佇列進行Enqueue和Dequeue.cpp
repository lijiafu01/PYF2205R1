#include <iostream>
using namespace std;
#define num 10
void Enqueue(int x);
int Dequeue();
void PrintQueue();
typedef struct queue{
    int arr[num];
    int rear;
    int front;
}Queue;
Queue queue;
int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    queue.rear=-1;
    queue.front=-1;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        Enqueue(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        Dequeue();
    }
    PrintQueue();
}
void Enqueue(int x){
    if(queue.rear==num-1){
        return ;
    }
    else
    queue.arr[++queue.rear]=x;
}

int Dequeue(){
    if(queue.front==queue.rear)
    {
        return -1;
    }
    else
    return queue.arr[++queue.front];
}
void PrintQueue(){
    int i;
    for(i=queue.front+1;i<queue.rear+1;i++)
    cout<<queue.arr[i]<<"\t";
}
