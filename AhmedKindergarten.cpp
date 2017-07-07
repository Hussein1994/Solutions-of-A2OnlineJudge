// Link Problem is : https://a2oj.com/p?ID=78
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(v)    ((int)((v).size()))
#define Rep(i, n) for(int i = 0; i <     sz(n); ++i)
#define All(X)  (X).begin(),(X).end()
vector<bool> isPrime;
ll cum[200011];
int N, x = 1, m;
void sieve(int n) {
    isPrime = vector<bool>(n + 1, true);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
}
ll CountPrime(int n) {
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (n == 4)
        return 3;
    ll count = 0;
     for (int i = 3; i <= n + 1; i++)
        if (isPrime[i])
            count++;
    int a = 5, b = n + 2, x = n + 1, j = 2 * n - 1;
    while (x < j) {
         count += (cum[b] - cum[a - 1]);
        a += 2;
        b++;
        x++;
    }
    return count;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif
    sieve(200011);
    cum[0] = isPrime[0];
    for (int i = 1; i < 200011; i++)
        cum[i] = isPrime[i] + cum[i - 1];

    scanf("%d", &m);
    while (x <= m) {
        scanf("%d", &N);
        printf("Case %d: %lld\n", x, CountPrime(N));
        x++;
    }

    return 0;
}