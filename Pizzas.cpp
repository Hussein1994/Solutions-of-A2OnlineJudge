// Link Problem is : https://a2oj.com/p?ID=326
#include <iostream>
using namespace std;
int main() {

    int t, i, N ,j, Sum,x;
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>N;
        Sum=0;
        for (j=0;j<N;j++)
        {
            cin>>x;
            Sum+=x;
        }
        cout<<"Case "<<i<<": "<<Sum<<endl;

    }

    return 0;
}