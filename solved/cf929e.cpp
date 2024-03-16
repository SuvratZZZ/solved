#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pres(n+1);
    pres[0]=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin>> a[i];
        pres[i+1]=pres[i]+a[i];
    }
    ll q;
    cin>>q;
    for (ll  i = 0; i < q ; i++)
    {
        ll l,u;
        cin>> l >> u;
        ll lef=l-1,rig=n-1;
        while (rig-lef>0)
        {
            ll mid=(rig+lef)/2;
            if (pres[mid+1]-pres[l-1]>u)
            {
                rig=mid;
            }
            else if(pres[mid+1]-pres[l-1]==u){
                lef=mid;
                break;
            }
            else{
                lef=mid+1;
            }
        }
        if(pres[lef+1]-pres[l-1]==u){
                cout << lef+1 << " "; 
                continue;
            }
        ll res = lef;
            // cout << "lower bound : " << lef+1 << endl;
            if(pres[lef+1]-pres[l-1]-u<=u-pres[lef]+pres[l-1]){
                res+=1 ;
            }
            res=max(res,l);
            res=min(res,n);
            cout << res << " ";
    }
    cout << endl;
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