#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int a[2];
	float b=0;
	for(int i=0;i<=2;i++)
	{
	    cin>>a[i];
	    b+=a[i];
	}
	if(b/2>=60)
	{
	    cout<<"�ή�"<<endl;
	}
	else{
	     cout<<"���ή�"<<endl;
	}
}
