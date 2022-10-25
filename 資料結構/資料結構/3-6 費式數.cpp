#include <iostream>
using namespace std;
int Fib(int n);
int main(int argc, char *argv[]) {
	int n,sum;
	cin>>n;
	sum=Fib(n);
	cout<<sum<<endl;
}
int Fib(int n)
{
    if(n<=2)
    return 1;
    else
    return Fib(n-1)+Fib(n-2);
}
