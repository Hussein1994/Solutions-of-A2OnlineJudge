// Link Problem is : https://a2oj.com/p?ID=367
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(v)    ((int)((v).size()))
#define Rep(i, n) for(int i = 0; i < sz(n); ++i)
#define lp(i, n)  for(int i=0;i<=(int)(n);++i)
#define All(X)  (X).begin(),(X).end()
#define All2(X)  (X).rebegin(),(X).rend()
#define MOD 1000000000 + 7
#define MAX 200001
using namespace std;
int n, t, res, i;
long arr[MAX], temp[MAX];
ll merge(int left, int mid, int right) {
    int i, j, k;
    ll cnt = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            cnt = cnt + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return cnt;
}
ll _mergeSort(int left, int right) {
    int mid;
    ll cnt = 0;
    if (right > left) {

        mid = (right + left) / 2;
        cnt = _mergeSort(left, mid);
        cnt += _mergeSort(mid + 1, right);
        cnt += merge(left, mid + 1, right);
    }
    return cnt;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        i = 0;
        while (i < n) {
            scanf("%ld", &arr[i]);
            i++;
        }
        printf("%lld\n", _mergeSort(0, n - 1));
    }
    return 0;
}
