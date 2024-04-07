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
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> prex(n);
    for (ll  i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    string s;
    cin>>s;
    ll oo=0,zz=0,fo,fz,ro1=1,ro2=1;
    for (ll  i = 0; i < n ; i++)
    {
        if(s[i]=='1')
        {   
                oo=oo^v[i];
        }
        else{
                    zz=zz^v[i];
        }
        // cout << oo << " : oo " << zz << " : zz " << endl;
        if (i>0)
        {
            prex[i]=prex[i-1]^v[i];
        }
        else
            prex[0]=v[0];

        // cout << prex[i] << " prex i " << i << endl;
    }

    ll q;cin>>q;
    while (q--)
    {
        ll type;cin>>type;
        if (type==1)
        {
            ll l,r;
            cin>>l>>r;
            if (l==1)
            {   
                    oo=oo^prex[r-1]; 
                    zz=zz^prex[r-1];
            }
            else
            {  
                    oo=oo^prex[r-1]^prex[l-2];  
                    zz=zz^prex[r-1]^prex[l-2];
            }
            
        }
        else{
            ll g ;cin>>g;
            cout << (g?oo:zz) << endl;
        }
    }
    
    
}
int main(){
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}