#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int a[5];
	float b=0;
	for(int i=1;i<=5;i++)
	{
	    cin>>a[i];
	    b+=a[i];
	}
	cout<<b/5<<endl;
}
