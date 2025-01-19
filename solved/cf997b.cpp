#include <bits/stdc++.h>
using namespace std;
# define ll long long


#ifndef ONLINE_JUDGE
#include <chrono>
#endif
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
    ll n;
    cin>>n;
        set<pair<ll,ll>> ss;
        map<ll,ll> mp;
    vector<vector<ll>> gr(n);
    for (ll  i = 0; i < n ; i++)
    {
        string tem;
        cin>>tem;
        ll deg=0;
        // if(mp[i+1]==0)
        //     mp[i+1]=0;
        for (ll  j = 0; j < n ; j++)
        {
            // if(i>=j)continue; 
            if(tem[j]=='1'){
                // gr[i+1].push_back(j+1);
                deg++;
                // gr[j+1].push_back(i+1);
                // mp[i+1]++;
                // mp[j+1]++;
            }
        }
        gr.push_back({i,deg});
        // sort(gr[i].begin(),gr[i].end());
    }
    sort(gr.begin(),gr.end(),[](const vector<ll> &a,const vector<ll> &b){
        return a[1]<b[1];
    });
    vector<ll> res(n);
    for (ll  i = 0; i < n ; i++)
    {
        ll v=gr[i][0];
        res[v]=i+1;
    }
    
    // for(auto i:mp){
    //     ss.insert({n-(upper_bound(gr[i.first].begin(),gr[i.first].end(),i.first)-gr[i.first].begin()),i.first});
    //     // cout << i.first << " " << i.second << endl;
    // }
    // for(auto i=ss.rbegin();i!=ss.rend();i++){
    //     cout << (i->second) << " ";
    // }
    for(auto i:res){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        auto start = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    #endif
    return 0;
}