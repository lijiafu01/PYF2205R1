#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Array_Data[3][5];
    int Array_Data2[15];
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Array_Data[i][j];
     for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
        {
            int t=i+j*3;
            Array_Data2[t]=Array_Data[i][j];
        }
        for(int i=0;i<15;i++)
        cout<<Array_Data2[i]<<"\t";
}
