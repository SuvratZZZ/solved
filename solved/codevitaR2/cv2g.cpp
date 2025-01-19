#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifndef ONLINE_JUDGE
#include <chrono>
#endif
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

#define pb push_back
#define fl(i, n) for (ll i = 0; i < n; i++)
#define flab(i, a, b) for (ll i = a; i < b; i++)
#define yn(f) cout << (f ? "YES" : "NO") << endl
#define rfall(f) reverse(f.begin(), f.end()); for (auto i : f) { cout << i << " "; } cout << endl
#define fall(f) for (auto i : f) { cout << i << " "; } cout << endl
#define ftd(f) for (auto i : f) { for (auto j : i) { cout << j << " "; } cout << endl; }

typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll, ll> mll;

const ll INF = 1e18;
const ll M = 998244353;
const ll mod = 1e9 + 7;
const int LLL = 1e6 + 5;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, 0, 0, -1, 1, 1, 1, -1, -1 };

map<pair<vector<vector<ll>>, ll>, ll> dp;
set<vector<vector<ll>>> fin;

ll sol(vector<vector<ll>> &pos, ll dep, ll cur) {
    if (cur == dep) {
        fin.insert(pos);
        return 1;
    }
    if (dp.find({pos, cur}) != dp.end()) return dp[{pos, cur}];
    
    ll res = 0;
    map<pair<ll, ll>, ll> mp;
    for (auto &i : pos) mp[{i[1], i[2]}] = 1;

    for (auto &i : pos) {
        int piece_type = i[0];
        int move_range = (piece_type == 1) ? 4 : 8;

        for (int j = 0; j < move_range; j++) {
            int nx = i[1] + dx[j];
            int ny = i[2] + dy[j];
            
            while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !mp[{nx, ny}]) {
                i[1] = nx; i[2] = ny;
                res += sol(pos, dep, cur + 1);
                i[1] -= dx[j]; i[2] -= dy[j];
                
                if (piece_type == 2) break;  // Bishop moves once
                nx += dx[j]; ny += dy[j];
            }
        }
    }
    return dp[{pos, cur}] = res;
}

void solv() {
    string tem;
    ll mov;
    vector<vector<ll>> pos;
    
    while (cin >> tem) {
        if (isdigit(tem[0])) {
            mov = stoll(tem);
            break;
        }
        vector<ll> te(3);
        te[0] = (tem[0] == 'Q') ? 0 : (tem[0] == 'R') ? 1 : 2;
        te[1] = tem[1] - 'A';
        te[2] = tem[2] - '1';
        pos.pb(te);
    }

    cout << sol(pos, mov, 0) << endl;
    cout << fin.size() << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    auto start = chrono::high_resolution_clock::now();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while (t--) {
        solv();
    }

    #ifndef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    #endif

    return 0;
}
