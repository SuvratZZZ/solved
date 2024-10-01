#include <bits/stdc++.h>
using namespace std;
# define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
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
vector<int> sieve(ll n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    for (ll p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (ll i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    for (ll p = 2; p <= n; ++p)
        if (isPrime[p])
            primes.push_back(p);
    return primes;
}
pair<int,vector<int>> minimumColors(int N,
                   vector<int> adj[])
{
    vector<int> count(N, 0);
    vector<int> colors(N, 1);
 
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        if (count[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
 
        for (auto x : adj[u]) {
            count[x]--;
 
            if (count[x] == 0) {
                Q.push(x);
            }
            if (colors[x] <= colors[u]) {
                colors[x] = 1 + colors[u];
            }
        }
    }
    int minColor = -1;
    for (int i = 0; i < N; i++) {
        minColor = max(minColor, colors[i]);
    }
    return { minColor,colors};
}

void solve(vector<int> &pr){
    int n;
    cin>>n;
    int i=0;
    vector<int> gr[n];
    while (pr[i]<=n)
    {
        int curr=pr[i];
        // vector<> set;
        // for (ll  j  = 0; j < 32 && curr > 0; j ++)
        // {
        //     if(curr&(1<<j)){
        //         set.push_back(1);
        //     }
        //     else
        //         set.push_back(0);
        // }
        for (int  j = 1; j <= curr; j++)
        {
            ll aa=j-1;
            ll bb=(j^curr) -1;
            if(((j^curr)<curr)&&(j^curr)!=0){
                cout << j << " j curr " << (j^curr) << endl;
                gr[aa].push_back(bb);
                gr[bb].push_back(aa);
            }
        }
        i++;
    }
    cout << 'd' << endl; 
    pair<int,vector<int>> res=minimumColors(n,gr);
    cout << res.first << endl;
    for(auto &i:res.second){
        cout << i << " . ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll up=200000;
    vector<int> pr=sieve(up);
    sort(pr.begin(),pr.end());
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve(pr);
    }
    return 0;
}