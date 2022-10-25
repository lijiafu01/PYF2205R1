#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a) {data = a; link = 0;}
private:
	int data;
	ListNode *link;
	friend class CircularList;
};

class CircularList
{
public:
    CircularList();
	void InsertFirst(int);
	void InsertLast(int);
	int DeleteFirst();
	int DeleteLast();
	void PrintList();
private:
	ListNode *last;
};

CircularList::CircularList() {
	last = 0;
}

void CircularList::InsertFirst(int x) {
	ListNode *newNode = new ListNode(x);
	if (last == 0) last = newNode;
	newNode->link = last->link;
	last->link = newNode;
}

void CircularList::InsertLast(int x) {
	ListNode *newNode = new ListNode(x);
	if (last == 0) last = newNode;
	newNode->link = last->link;
	last->link = newNode;
	last = newNode;
}

int CircularList::DeleteFirst() {
	ListNode *oldNode = last->link;
	if (last == last->link)
		last = 0;
	else
		last->link = last->link->link;
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

int CircularList::DeleteLast() {
	ListNode *oldNode = last;
	if (last == last->link) {
		last = 0;
	}
	else {
		ListNode *pre = last->link;
		while(pre->link != last) {
			pre = pre->link;
		}
		pre->link = last->link;  //caution
		last = pre;
	}
	int rt_val = oldNode->data;
	delete oldNode;
	return rt_val;
}

void CircularList::PrintList() {
	if (last != 0) {
	    ListNode *current = last;
	    do {
	    	current = current->link;
	    	cout << current->data << " ";
	    } while (current != last);
	}
}
 
int main(int argc, char *argv[])
{
    CircularList list;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertFirst(input);}
    for(cin >> times; times > 0; times--) list.DeleteFirst(); 
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertLast(input);}
    for(cin >> times; times > 0; times--) list.DeleteLast();
    list.PrintList();
}
