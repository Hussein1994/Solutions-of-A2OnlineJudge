// Link Problem is : https://a2oj.com/p?ID=80

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

const int oo = 1e9;
int n, m, t, i = 1, a, b, c, res;
struct state {
    int u, cost;
    bool operator<(const state &r) const {
        return cost > r.cost;
    }
    state() {
    }
    state(int a, int b) {
        u = a;
        cost = b;
    }
};
vector<vector<pair<int, int> > > g;
int cost[100000];
bool vis[100000];
int Dijkstra(int src, int target) {
    priority_queue<state> q;
    q.push(state(src, 0));
    for (int i = 0; i < n; ++i) {
        cost[i] = oo;
        vis[i] = 0;
    }
    cost[src] = 0;
    while (!q.empty()) {
        state s = q.top();
        q.pop();
        if (vis[s.u])
            continue;
        if (s.u == target)
            return s.cost;
        vis[s.u] = true;
        for (int i = 0; i < g[s.u].size(); ++i) {
            int v = g[s.u][i].first;
            int len = g[s.u][i].second;
            if (cost[v] > cost[s.u] + len) {
                cost[v] = cost[s.u] + len;
                q.push(state(v, cost[v]));
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("myfile.in", "r", stdin);
#endif

    scanf("%d", &t);
    while (i <= t) {
        scanf("%d%d", &n, &m);
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            g[a].push_back(make_pair(b, c));
            swap(a, b);
            g[a].push_back(make_pair(b, c));
        }
        scanf("%d%d", &a, &b);
        --a;
        --b;
        res = Dijkstra(a, b);
        printf("Case %d: %d\n", i, res);
        i++;
    }
    return 0;
}