#include <iostream>
using namespace std;
int GCD(int a, int b);
int main(int argc, char *argv[]) {
	int a,b,c;
	cin>>a>>b;
	cout<<GCD(a,b);
}
int GCD(int a, int b)
{
    int c;
    c=a%b;
    if(c==0)
    return b;
    else
    return GCD(b,c);
}
