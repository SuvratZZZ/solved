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
bool ose(string s,string t){
    for (ll  i = 0; i < 2 ; i++)
    {
        for (ll  j = 0; j < 2 ; j++)
        {
            if(s[i]==t[j]){
                return 1;
            }  
        }
    }
    return 0;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> bg;
    vector<ll> br;
    vector<ll> by;
    vector<ll> gr;
    vector<ll> gy;
    vector<ll> ry;
    vector<string> col(n);
    map<string,vector<ll>> mp;
    for (ll  i = 0; i < n ; i++)
    {
        string s;
        cin>>s;
        mp[s].push_back(i);
        col[i]=s;
    }
    for (ll  i = 0; i < q ; i++)
    {
        ll x,y;
        cin>>x>>y;x--;y--;
        if(x>y)swap(x,y);
        if(ose(col[x],col[y])){
            cout << y-x << endl;
            continue;
        }
        else{
            ll res=INT_MAX;
            for (ll  i = 0; i < 4 ; i++)
            {
                string tem="";
                char c1=col[x][i/2],c2=col[y][i%2];
                tem.push_back(c1);
                tem.push_back(c2);
                sort(tem.begin(),tem.end());
                // cout << tem << " tem " << endl;
                if(mp[tem].size()==0){
                    continue;
                }

                auto it=lower_bound(mp[tem].begin(),mp[tem].end(),x);
                if(it!=mp[tem].end()){
                res=min(abs(*it-x)+abs(*it-y),res);
                // cout << *it << " IT " << endl;
                }
                if(it==mp[tem].begin()){
                    continue;
                }
                it--;
                if(it!=mp[tem].end())
                res=min(abs(*it-x)+abs(*it-y),res);


                auto it2=lower_bound(mp[tem].begin(),mp[tem].end(),y);
                if(it2!=mp[tem].end()){
                res=min(abs(*it2-x)+abs(*it2-y),res);
                // cout << *it << " IT " << endl;
                }
                if(it2==mp[tem].begin()){
                    continue;
                }
                it2--;
                if(it2!=mp[tem].end())
                res=min(abs(*it2-x)+abs(*it2-y),res);
            }
            
            if(res!=INT_MAX){
                cout << res << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}