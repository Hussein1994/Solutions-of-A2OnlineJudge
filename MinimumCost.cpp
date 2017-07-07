// Link Problem is : https://a2oj.com/p?ID=174
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
char str1[1001], str2[1001];
int dp[1001][1001], sz1, sz2;
int LCS(int i, int j) {
    if (i == sz1 || j == sz2)
        return 0;
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    if (str1[i] == str2[j])
        return 1 + LCS(i + 1, j + 1);
    int choice1 = LCS(i + 1, j);
    int choice2 = LCS(i, j + 1);
    return ret = max(choice1, choice2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif

    while (scanf("%s", str1) && str1[0] != '#') {
        scanf("%s", str2);
        sz1 = strlen(str1);
        sz2 = strlen(str2);
        memset(dp, -1, sizeof(dp));
        int mx = LCS(0, 0);
        int res = ((sz1 - mx) * 15) + ((sz2 - mx) * 30);
        printf("%d\n", res);
    }
}