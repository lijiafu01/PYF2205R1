#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int Score[6];
	int a=0;
	for(int i=0;i<6;i++)
	cin>>Score[i];
	for(int i=0;i<6;i++)
	{
	    a+=Score[i];
	}
	cout<<a<<endl;
}
