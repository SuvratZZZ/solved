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


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid1(n, vector<int>(m));
    vector<vector<int>> grid2(n, vector<int>(m));

    set<set<ll>> m1ro;
    set<set<ll>> m2ro;
    set<set<ll>> m1co;
    set<set<ll>> m2co;

    for (int i = 0; i < n; i++) {
        set<ll> tem;
        for (int j = 0; j < m; j++) {
            cin >> grid1[i][j];
            tem.insert(grid1[i][j]);
        }
        m1ro.insert(tem);
    }

    for (int i = 0; i < n; i++) {
        set<ll> tem;
        for (int j = 0; j < m; j++) {
            cin >> grid2[i][j];
            tem.insert(grid2[i][j]);
        }
        m2ro.insert(tem);
    }

    for (int i = 0; i < m; i++) {
        set<ll> tem;
        for (int j = 0; j < n; j++) {
            // cin >> grid2[i][j];
            tem.insert(grid1[j][i]);
        }
        m1co.insert(tem);
    }

    for (int i = 0; i < m; i++) {
        set<ll> tem;
        for (int j = 0; j < n; j++) {
            // cin >> grid2[i][j];
            tem.insert(grid2[j][i]);
        }
        m2co.insert(tem);
    }
    
    if(m1co==m2co&&m1ro==m2ro){
        cout << "YES" << endl;
        return ;
    }
        cout << "NO" << endl;
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