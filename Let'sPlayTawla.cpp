// Link Problem is : https://a2oj.com/p?ID=329
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t, a, b;
    string ch[6] = { "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh" };
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        if ((a == 5 && b == 6) || (a == 6 && b == 5))
        {
            cout  << "Case " << i << ": Sheesh Beesh" << endl;
        }
        else if (a > b)
        {
            cout << "Case " << i << ": " << ch[a-1] << " " << ch[b-1] << endl;

        }

        else if (a < b)
        {
            cout << "Case " << i << ": " << ch[b-1] << " " << ch[a-1] << endl;

        }

        else if (a == b)
        {

            if (a == 1 && b == 1)
                cout << "Case " << i << ": Habb Yakk";
            else if (a == 2 && b == 2)
                cout << "Case " << i << ": Dobara";
            else if (a == 3 && b == 3)
                cout << "Case " << i << ": Dousa";
            else if (a == 4 && b == 4)
                cout << "Case " << i << ": Dorgy";
            else if (a == 5 && b == 5)
                cout << "Case " << i << ": Dabash";
            else if (a == 6 && b == 6)
                cout << "Case " << i << ": Dosh";
            cout<<endl;
        }



    }
    return 0;

}