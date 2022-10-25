#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[4][5];
    float sum[4];
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Score[i][j];
        for ( int i=0; i<=3; i++ )
            {
                sum[i]=0;
            }
        for ( int i=0; i<=3; i++ )
            for ( int j=0; j<=4; j++ )
            {
                sum[i]=sum[i]+Score[i][j];
            }
             for ( int i=0; i<=3; i++ )
            {
                cout<<sum[i]/5<<"\t";
            }
}
