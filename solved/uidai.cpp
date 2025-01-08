#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100000; // Adjust based on constraints
vector<int> adj[MAXN + 1];
int par[20][MAXN + 1]; // log(n) is at most 20 for n <= 10^7
int dep[MAXN + 1];
int diff[MAXN + 1];
int ep_sub[MAXN + 1];

void dfs(int u, int prev) {
    for (int v : adj[u]) {
        if (v != prev) {
            dep[v] = dep[u] + 1;
            par[0][v] = u;
            dfs(v, u);
        }
    }
}

int find_lca(int u, int v, int log) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int diff = dep[u] - dep[v];
    for (int i = 0; i < log; i++) {
        if (diff & (1 << i)) {
            u = par[i][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = log - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

void acc_dfs(int u, int prev) {
    for (int v : adj[u]) {
        if (v != prev) {
            acc_dfs(v, u);
            diff[u] += diff[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    vector<vector<int>> queries(q,vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin>>queries[i][0];
        cin>>queries[i][1];
        cin>>queries[i][2];
    }

    int log = 0;
    while ((1 << log) <= n) {
        log++;
    }

    dfs(1, 0);
    for (int i = 1; i < log; i++) {
        for (int v = 1; v <= n; v++) {
            par[i][v] = par[i - 1][par[i - 1][v]];
        }
    }

    for (auto i : queries) {
        int a=i[0],b=i[1],x=i[2];
        int l = find_lca(a, b, log);
        diff[a] += x;
        diff[b] += x;
        diff[l] -= x;
        if (par[0][l] != 0) {
            diff[par[0][l]] -= x;
        }
        ep_sub[a] += x;
        ep_sub[b] += x;
    }

    acc_dfs(1, 0);

    long long sum_j = 0, sum_b = 0;
    for (int i = 1; i <= n; i++) {
        long long pop = p[i - 1] + diff[i] - ep_sub[i];
        if (i % 2 == 1) {
            sum_j += pop;
        } else {
            sum_b += pop;
        }
    }

    cout << abs(sum_j - sum_b) << endl;

    return 0;
}