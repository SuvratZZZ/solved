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

void ss(vector<pair<ll,char>> &v, ll ind,ll n,ll curr,set<ll> &s){
    if (ind==(ll)v.size())
    {
        s.insert(curr);
    }
    
    if (v[ind].second=='?')
    {
        ss(v,ind+1,n,((curr+v[ind].first)==n?n:(curr+v[ind].first)%n),s);
        if (curr-v[ind].first<1)
        {
            ss(v,ind+1,n,n+curr-v[ind].first,s);
            
        }
        else
        ss(v,ind+1,n,curr-v[ind].first,s);
        

    }
    else if (v[ind].second=='0')
    {
        ss(v,ind+1,n,((curr+v[ind].first)==n?n:(curr+v[ind].first)%n),s);

    }
    else if (v[ind].second=='1'){
        if (curr-v[ind].first<1)
        {
            ss(v,ind+1,n,n+curr-v[ind].first,s);
            
        }
        else
        ss(v,ind+1,n,curr-v[ind].first,s);
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
        ll n,m,x;
        cin >> n >> m >> x;
        vector<pair<ll,char>> v(m);
        for (ll  i = 0; i < m ; i++)
        {
            ll tem;
            char ccc;
            cin >> tem >> ccc;
            v[i]={tem,ccc};
        }
        set<ll> res;
        ss(v,0,n,x,res);
        cout << res.size() << endl;
        for (ll i:res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}