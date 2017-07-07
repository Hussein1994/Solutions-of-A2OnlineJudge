// Link Problem is : https://a2oj.com/p?ID=330
#include<bits/stdc++.h>
using namespace std;
 
int arr[51][2], target, N, mini, t, i, x, j, q, maxi, id;
long long cou, mem[51][5001], vist[51][5001];
long long dp(int index, int sum, int i) {
    if (sum == target && index == N)
        return 1;
    if (sum > target || index >= N)
        return 0;
    if (vist[index][sum] == id)
        return mem[index][sum];
    vist[index][sum] = id;
    long long x = 0;
    x += dp(index + 1, sum, i);
    if (arr[index][1] >= i)
        x += dp(index + 1, sum + arr[index][0] * i, i);
    return mem[index][sum] = x;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif
 
    scanf("%d", &t);
    q = 1;
    while (q <= t) {
        scanf("%d%d", &target, &N);
        i = 0;
        maxi = 0;
        mini = 5001;
        while (i < N) {
            scanf("%d%d", &arr[i][0], &x);
            if (x > maxi)
                maxi = x;
            arr[i][1] = x;
            i++;
            cou = 0;
        }
        memset(mem, -1, sizeof(mem));
        for (i = 1; i * i <= target; i++) {
            if (target % i == 0) {
                ++id;
                cou += dp(0, 0, i);
                if (i * i != target) {
                    ++id;
                    cou += dp(0, 0, target / i);
                }
            }
        }
        printf("Case %d: %lld\n", q, cou);
        q++;
    }
 
    return 0;
}