#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a, int b) {coef = a; exp = b; link = 0;}
private:
	int coef;
	int exp;
	ListNode *link;
	friend class PolyList;
};

class PolyList
{
public:
	void InsertLast(int, int);
	void Add(PolyList&);
	void PrintList();
private:
	ListNode *first = 0;
	ListNode *last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
	ListNode *newNode = new ListNode(coef, exp);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}

void PolyList::Add(PolyList& b)
{
	

}

void PolyList::PrintList()
{
	// Write here
}

int main(int argc, char *argv[])
{
    PolyList A, B;
    int times, input, input2;
    for(cin >> times, times/=2; times > 0; times--) {cin >> input >> input2; A.InsertLast(input, input2);}
    for(cin >> times, times/=2; times > 0; times--) {cin >> input >> input2; B.InsertLast(input, input2);}
    A.Add(B);
	A.PrintList();
}
