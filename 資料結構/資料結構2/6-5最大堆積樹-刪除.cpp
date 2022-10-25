  
#include <iostream>
using namespace std;
class MaxHeap
{
public:
    void Insert(int x);
    void Print();
    void Delete();

private:
    int arr[100] = {0};
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
void MaxHeap::Delete()
{
    bool isHeap = false;
    int i = 1;
    arr[1] = arr[tail];
    while (isHeap!=true) 
    {
        if(i * 2 < tail)
        {
            if (arr[i * 2] > arr[i * 2 + 1]) 
            {
                if (arr[i * 2] > arr[i])
                    swap(arr[i], arr[i * 2]);
                else
                    isHeap = true;
                i = i * 2;
                
            }
            else if (arr[i * 2] < arr[i * 2 + 1]) 
            {
                
                if (arr[i * 2 + 1] > arr[i])
                    swap(arr[i], arr[i * 2 + 1]);
                else
                    isHeap = true;
                i = i * 2 + 1;
                
            }
        }
        else
            isHeap = true;
        
        
    }
    tail--;
    
}
int main(int argc, char* argv[])
{
    MaxHeap tree1;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
    for (cin >> times; times > 0; times--) { tree1.Delete(); }
    tree1.Print();
}
