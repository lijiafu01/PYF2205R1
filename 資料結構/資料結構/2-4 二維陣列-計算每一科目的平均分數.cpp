#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[4][5];
    float sum[5];
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Score[i][j];
            for ( int j=0; j<=4; j++ )
            {
                sum[j]=0;
            }
            for ( int j=0; j<=4; j++ )
            for ( int i=0; i<=3; i++ )
            {
                sum[j]=sum[j]+Score[i][j];
            }
            for ( int j=0; j<=4; j++ )
            {
                cout<<sum[j]/4<<"\t";
            }
}
