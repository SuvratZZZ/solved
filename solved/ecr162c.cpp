#include <bits/stdc++.h>
using namespace std;
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
void solve(){
    ll n,q;
    cin >> n >> q;
    vector<ll > a(n);
    ll count=0;
    vector<pair<ll,ll>> qu(q);
    vector<ll> mp(n+1);
    mp[0]=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin >> a[i];
        if (a[i]==1)
        {
            count++;
        }
        mp[i+1]=count;
        
    }
    for (ll  i = 0; i <  q ; i++)
    {
        ll t1,t2;
        cin >> t1 >> t2;
        qu[i]={t1,t2};
        cout << mp[qu[i].first] << " first sec " << mp[qu[i].second] << endl;
    }
    for (ll  i = 0; i < q ; i++)
    {
        if (qu[i].second-qu[i].first==0)
        {
            cout << "NO" << endl;continue;
        }
        if((mp[qu[i].second]-mp[qu[i].first-1])>((qu[i].second-qu[i].first+1)/2)){
            cout << "sec " <<mp[qu[i].second]-mp[qu[i].first-1] << endl;
            cout << "NO" << endl;

        }
        else{
            cout << mp[qu[i].second]-mp[qu[i].first-1] << endl;
            cout << "YES" << endl;
        }
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