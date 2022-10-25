#include <iostream>
using namespace std;
class Queue {
public:
    void Enqueue(int x);
    void Dequeue();
    void BackEnqueue(int x);
    void BackDequeue();
    void PrintQueue();
private:
    int arr[10], rear = 0, front = 0;
};

void Queue::Enqueue(int x)
{
    arr[rear] = x;
    rear = (rear +1) % 10;
    

}
void Queue::Dequeue()
{
    front = (front + 1) % 10;
   

}
void Queue::BackEnqueue(int x)
{
    
    front = (front +9) % 10;
    arr[front] = x;

}
void Queue::BackDequeue()
{
    rear = (rear -1) % 10;
    

}
void Queue::PrintQueue()
{
    for (int i = front ; i != rear ; i = (i + 1) % 10)
    {
        cout << arr[i] << " ";

    }
    cout << "rear:" << rear << " " << "front:" << front;

}
int main(int argc, char* argv[])
{
    Queue queue;
    int times, input;
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.Dequeue();
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.BackDequeue();
    }
    queue.PrintQueue();
}
