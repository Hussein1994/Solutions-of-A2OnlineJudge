// Link Problem is : https://a2oj.com/p?ID=389
#include <bits/stdc++.h>
using namespace std;
#define sz(v)    ((int)((v).size()))
#define Rep(i, n) for(int i = 0; i < sz(n); ++i)
#define lp(i, n)  for(int i=0;i<(int)(n);++i)
int t, Q = 1, p, s, j, m, i, to, z;
vector<vector<int> > adj;
vector<bool> visited, onCycle, OnCycle_MyNode, vis2; //Edit
vector<string> names;
string name;
vector <int>finals;
bool inBag[51];
// Edit
void dfs(int node) {
    inBag[node]=true;
    visited[node] = true;
    Rep(i, adj[node]) {
        int child = adj[node][i];
        if (!visited[child])
            dfs(child);
        else if (inBag[child]){
            onCycle[child] = true;
        }
    }
    inBag[node]=false;
}

//Edit
void dfs2(int node) {
    vis2[node] = true;

    if (onCycle[node]) {
        OnCycle_MyNode[node] = true;
        z++;
    }

    Rep(i, adj[node]) {
        int child = adj[node][i];
        if (!vis2[child])
            dfs2(child);
    }
}

void dfs3(int node) {
    vis2[node] = true;
    OnCycle_MyNode[node] = true;
    z++;

    Rep(i, adj[node]) {
        int child = adj[node][i];
        if (!vis2[child])
            dfs3(child);
    }
}

int main() {

    scanf("%d", &t);
    while (Q <= t) {
        memset(inBag,0,sizeof(inBag));
        scanf("%d%d", &p, &s);
        adj = vector<vector<int> >(p);
        visited = vector<bool>(p, 0);
        vis2 = vector<bool>(p, 0);
        onCycle = vector<bool>(p, 0);
        OnCycle_MyNode = vector<bool>(p, 0);
        names = vector<string>(p);
        lp(j, p) {
            cin >> name;
            names[j] = name;
        }
        lp(j, p) {
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &to);
                adj[j].push_back(to - 1);
            }
        }

        s--;
        j = 0;
        //Edit
        lp(j,p) {
            visited.clear();
            visited = vector<bool>(p, 0);
            dfs(j);
        }
        z = 0;
        i = 0;
        dfs2(s);
        lp(j,p) {
            vis2.clear();
            vis2 = vector<bool>(p, 0);
            if (OnCycle_MyNode[j])
                dfs3(j);
        }
        j=0;
        lp(j,p){
            if (OnCycle_MyNode[j])
                finals.push_back(j);
        }
        //Finish Edit

        if (z == 0) {
            printf("Chain Email #%d:\nSafe chain email!", Q);
        } else {
            printf("Chain Email #%d:\n", Q);
            j=0;
            Rep(j,finals) {
                if (j<finals.size()-1)
                    cout << names[finals[j]] << " ";
                else
                    cout << names[finals[j]] ;

            }
        }
        if (Q<=t-1)
            printf("\n\n");

        visited.clear();
        finals.clear();
        vis2.clear();
        adj.clear();
        names.clear();
        onCycle.clear();
        OnCycle_MyNode.clear();
        Q++;
    }

    return 0;

}