#include <iostream>
using namespace std;
int fact(int n);
int main(int argc, char *argv[]) {
	int n;
	while(cin>>n)
	cout<<fact(n)<<endl;
	return 0;
}
int fact(int n)
{
    int result;
    if(n==0)
    {
    return 1;	
    }
    if(n>=1)
    {
    return n*fact(n-1);	
    }
    
}
