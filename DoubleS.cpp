// Link Problem is : https://a2oj.com/p?ID=151
#include <bits/stdc++.h>
using namespace std;
#define inp_s     ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(v)    ((int)((v).size()))
#define Rep(i, n) for(int i = 0; i < sz(n); ++i)
#define lp(i, n)  for(int i=0;i<=(int)(n);++i)
#define All(X)  (X).begin(),(X).end()
#define All2(X)  (X).rebegin(),(X).rend()
#define MOD 1000000000 + 7
#define MAX (int)1e5+4
#define PI 2 * acos(0.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int sum, target, i, j, t, n, arr[11], v;

int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &target, &n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        v = 0;
        for (i = 1; i < (1 << n) && !v; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (i & (1 << j))
                    sum += arr[j];
            }
            if (sum == target)
                v = 1;
        }
        if (v)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}