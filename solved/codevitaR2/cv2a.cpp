#include <bits/stdc++.h>
using namespace std;
# define ll long long


// #ifndef ONLINE_JUDGE
// #include <chrono>
// #endif
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
# define rfall(f) reverse(f.begin(),f.end());for(auto i:f){cout << i << " ";}cout << endl
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
# define ftd(f) for(auto i:f){for(auto j:i){cout << j << " ";}cout << endl;}


typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;


const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
const ll mod = 1e9+7;
const int LLL = 1e6+5;

//ll JUD = 0;
//
//#ifdef ONLINE_JUDGE
//# define JUD 0
//#else
//# define JUD 1
//#endif


int sml_fctr[LLL];
void fill_factor(){
    for(int i=0;i<=LLL;i++){
        sml_fctr[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int j=i*i;j<=LLL;j=j+i){
            if(sml_fctr[j]==j){
                sml_fctr[j]=i;
            }
        }
    }
}
vector<int> fin_factor(int n){
    // will not have 1 as prime
    vector<int> res;
    int tt=n;
    while(tt!=1){
        res.push_back(sml_fctr[tt]);
        tt=tt/sml_fctr[tt];
    }
    return res;
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> gr(n,vector<ll>(m,0));
    vector<vector<ll>> tm(n,vector<ll>(m));
    ll sx,sy,dx,dy;
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j = 0; j < m ; j++)
        {
            string tem;
            cin>>tem;
            if(tem=="S"){
                sx=i;sy=j;
            }
            else if(tem=="D"){
                dx=i;dy=j;
            }
            else{
                gr[i][j]=stoll(tem);
            }
        }
    }
    for (ll  i = 0; i < n ; i++)
    {
        for (ll  j  = 0; j  < m; j ++)
        {
            cin>>tm[i][j];
        }
    }
    ll stren ;cin>>stren;
    int dx4[] = {-1, 0, 1, 0};
    int dy4[] = {0, 1, 0, -1};

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, 0, sx, sy});
    
    vector<vector<ll>> min_cost(n, vector<ll>(m, LLONG_MAX));
    min_cost[sx][sy] = 0;
    
    while (!pq.empty()) {
        vector<ll> tem = pq.top();
        pq.pop();
        ll ct = tem[0], cs = tem[1], cx = tem[2], cy = tem[3];
        
        if (cx == dx && cy == dy) {
            cout << ct << " " << stren - cs << endl;
            return;
        }
        
        if (cs >= stren) continue;
        
        for (int k = 0; k < 4; k++) {
            ll nx = cx + dx4[k], ny = cy + dy4[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                ll new_cost = cs + gr[nx][ny] + 1; 
                ll new_time = ct + tm[nx][ny];
                
                if (new_cost <= stren && new_cost < min_cost[nx][ny]) {
                    min_cost[nx][ny] = new_cost;
                    pq.push({new_time, new_cost, nx, ny});
                }
            }
        }
    }
    cout << "Not Possible" << endl;

}
int main(){
    // #ifndef ONLINE_JUDGE
    //     auto start = std::chrono::high_resolution_clock::now();
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    // #ifndef ONLINE_JUDGE
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::chrono::duration<long double> duration = end - start;
    //     std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    // #endif
    return 0;
}