#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
//
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;

vector<vector<int>> transpose(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> t(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = mat[i][j];
        }
    }
    return t;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid1(n, vector<int>(m));
    vector<vector<int>> grid2(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid2[i][j];
        }
    }

    if (n == m) {
        set<vector<int>> stt;
        for (const auto& v : grid1) {
            stt.insert(v);
        }

        for (const auto& v : grid2) {
            if (stt.find(v) == stt.end()) {
                cout << "NO" << endl;
                return;
            }
        }

        grid1 = transpose(grid1);
        grid2 = transpose(grid2);
        stt.clear();

        for (const auto& v : grid1) {
            stt.insert(v);
        }

        for (const auto& v : grid2) {
            if (stt.find(v) == stt.end()) {
                cout << "NO" << endl;
                return;
            }
        }

        cout << "YES" << endl;
    } else {
        set<vector<int>> stt;
        for (const auto& v : grid1) {
            stt.insert(v);
        }

        for (const auto& v : grid2) {
            if (stt.find(v) == stt.end()) {
                cout << "NO" << endl;
                return;
            }
        }

        stt.clear();

        for (int j = 0; j < m; j++) {
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                cur.push_back(grid1[i][j]);
            }
            stt.insert(cur);
        }

        for (int j = 0; j < m; j++) {
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                cur.push_back(grid2[i][j]);
            }
            if (stt.find(cur) == stt.end()) {
                cout << "NO" << endl;
                return;
            }
        }

        cout << "YES" << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}