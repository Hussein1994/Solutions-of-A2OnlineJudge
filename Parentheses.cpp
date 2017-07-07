// Link Problem is : https://a2oj.com/p?ID=168
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(v)    ((int)((v).size()))
#define Rep(i, n) for(int i = 0; i < sz(n); ++i)
#define lp(i, n)  for(int i=0;i<(int)(n);++i)
#define All(X)  (X).begin(),(X).end()
#define All2(X)  (X).rebegin(),(X).rend()
#define pb push_back
#define mp make_pair
#define MOD 1000000000 + 7
#define MAX 101
int n;
string str;
vector<string> vec;
stack<char> s;
int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        str += "()";
    }
    int size = str.size(), i, res = 0, a = 0;
    sort(All(str));
    do {

        if (str[0] != ')') {
            res = 0, a = 0;
            for (i = 0; i < size; i++) {
                if (str[i] == '(') {
                    s.push('(');
                } else if (!s.empty()) {
                    s.pop();
                    res += 2;
                }
            }
            while (!s.empty())
                s.pop();

            if (res == size)
                vec.pb(str);
        }
    } while (next_permutation(All(str)));
    size = vec.size();
    for (i = 0; i < size; i++)
        cout << vec[i] << endl;

    return 0;