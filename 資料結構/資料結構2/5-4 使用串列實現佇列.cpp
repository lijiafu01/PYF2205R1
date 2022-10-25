#include <iostream>
using namespace std;
class ListNode
{
public:
    ListNode(int a) { data = a; link = 0; }
private:
    int data;
    ListNode* link;
    friend class LinkedList;
};

class LinkedList
{
public:
    LinkedList() :first(0) {};
    void InsertFirst(int x);
    void InsertLast(int x);
    int DeleteFirst();
    int DeleteLast();
    void PrintList();
private:
    ListNode* first;
    ListNode* last;
};
class Queue:LinkedList
{
public:
    void Enqueue(int x);
    int Dequeue();
    void PrintQueue();
};
void Queue::Enqueue(int x)
{
    InsertLast(x);
}
int Queue::Dequeue()
{
    DeleteFirst();
}
void Queue::PrintQueue()
{
    PrintList();
}
void LinkedList::InsertFirst(int x)
{
    ListNode* newNode = new ListNode(x);
    newNode->link = first;
    first = newNode;
}
void LinkedList::InsertLast(int x)
{
    ListNode* newNode = new ListNode(x);
    if (first == 0) {
        first = newNode;
        return;
    }

    ListNode* current = first;
    while (current->link != 0) {
        current = current->link;
    }
    current->link = newNode;
}
int LinkedList::DeleteFirst()
{
    ListNode* current = first;
    first = current->link;
    delete current;
    current = 0;
}
int LinkedList::DeleteLast()
{
    ListNode* prev = first;
    while (prev->link != last) {
        prev = prev->link;
    }
    ListNode* current = first, * previous = 0;
    while (current != 0 && current->data != prev->data) {
        previous = current;
        current = current->link;
    }
    previous->link = current->link;
    delete current;
    current = 0;
}
void LinkedList::PrintList()
{
    ListNode* current = first;
    while (current != 0) {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; queue.Enqueue(input);}
    for(cin >> times; times > 0; times--) queue.Dequeue();
    queue.PrintQueue();
}
