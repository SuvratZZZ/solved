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
    ll n,m,sum=0;
    cin>>n>>m;
    vector<ll> a(n);
    multiset<ll> mm;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        ll tem=a[i];
        while (tem>0)
        {
            sum=sum+1;
            tem=tem/10;
        }
        tem=a[i];
        ll tem2=a[i]%10;
        ll cou=0;
        while (tem2==0)
        {
            tem=tem/10;
            tem2=tem%10;
            cou ++;
        }
        mm.insert(cou);
    }
    // cout << "sum : " << sum << endl;
    bool ff=1;
    // cout << "multi : ";
    for(auto it = mm.rbegin(); it!=mm.rend(); it++){
        // cout << *it << " ";
        if(ff){
        sum=sum-*it;}
        if(ff){
            ff=0;
        }
        else{
            ff=1;
        }
    }
    // cout << endl;
    // cout << "sum : " << sum << endl;
    cout << (sum>m?"Sasha":"Anna") << endl;
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