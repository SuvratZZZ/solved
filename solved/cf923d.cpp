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
    cin >> n ;
    vector<ll> a(n+1);
    vector<ll> a2(n+1);
    a2[0]=0;
    a2[1]=0;
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        if ((i>1))
        {   
            if((a[i]==a[i-1]))
            {
                a2[i]=a2[i-1];
            }  
            if((a[i]!=a[i-1]))
            {
                a2[i]=i-1;
            }
            
        }
        
    }
    cin >> q;
    vector<pair<ll,ll>> que(q);
    for (int i = 0; i < q; i++)
    {
        ll t1,t2;
        cin >> t1 >> t2;
        que[i]={t1,t2};

    }
    for (int i = 0; i < q; i++)
    {
        if((a2[que[i].second]!=0)&&(a2[que[i].second]>=que[i].first)){
            cout << a2[que[i].second] << " " << que[i].second << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
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