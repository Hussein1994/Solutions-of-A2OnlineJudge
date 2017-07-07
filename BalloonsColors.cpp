// Link Problem is : https://a2oj.com/p?ID=6
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T ,N,X,Y,first,v,last ;
    cin>>T;
    while (T>0) {
        bool easy = false, hard = false;
        cin >>N >>X>>Y>>first;
        while (N >= 3) {
            cin>>v;
            N--;
        }
        cin>>last;
        if (first == X) {
            easy = true;
        }
        if (last == Y) {
            hard = true;
        }

        if (easy && hard) {
            cout<<"BOTH"<<endl;
        } else if (easy) {
            cout<<"EASY"<<endl;
        } else {
            if (hard) {
                cout<<"HARD"<<endl;
            } else {
                cout<<"OKAY"<<endl;
            }

        }
        T--;
    }

    return 0;
}
