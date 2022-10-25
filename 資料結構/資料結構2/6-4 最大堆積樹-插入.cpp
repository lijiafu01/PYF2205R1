#include <iostream>
using namespace std;
class MaxHeap
{
public:
    void Insert(int x);
    void Print();
private:
    int arr[100];
    int tail=0;
};
void MaxHeap::Insert(int x)
{
    tail++;
    int i = tail;
    arr[i] = x;
    bool isHeap = false;
    while (isHeap!=true)
    {
        if (i == 1)
        {
            isHeap = true;
        }
        else if (arr[i] >= arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
        }
        i--;
    }

}
void MaxHeap::Print()
{
    for (int i = 1; i <= tail; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int argc, char* argv[])
{
    MaxHeap tree1;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
    tree1.Print();
}
