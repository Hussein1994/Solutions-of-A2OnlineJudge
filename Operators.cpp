// Link Problem is : https://a2oj.com/p?ID=388
#include <iostream>
#include <string.h>
using namespace std;

int t, i, N, target;
int arr[17];
int arr2[17][100001];
int dp(int index, int sum) {
    if (sum == target && index == N)
        return 1;
    if (index == N)
        return 0;
    if (arr2[index][sum] != -1)
        return arr2[index][sum];

    int x = 0;
    x = max(x, dp(index+1 , sum + arr[index]));
    x = max(x, dp(index +1, sum - arr[index]));
    return arr2[index][sum] = x;
}

int main() {
    cin >> t;
    while (t) {
        cin >> N >> target;
        for (i = 0; i < N; i++)
            arr[i] = i+1;
        memset(arr2, -1, sizeof(arr2));
        if (dp(0, 0))
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
        t--;
    }
    return 0;

}