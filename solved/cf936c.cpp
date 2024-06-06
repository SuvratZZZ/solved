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

ll dfscut(ll nod,vector<vector<ll>> &tri,ll &k,ll mine,ll parent){
    ll nodes=1;
    for(ll i: tri[nod]){
        if(i!=parent){
            nodes=nodes + dfscut(i,tri,k,mine,nod);
        }
    }
    if(nodes>=mine){
        k++;
        nodes=0;
    }
    return nodes;
}
void solve(){
    ll n,k;
    cin>> n>>k;
    vector<vector<ll>> tri(n+1);
    for (ll i = 0; i < (n-1); i++)
    {
        ll t1,t2;
        cin>>t1>>t2;
        tri[t1].push_back(t2);
        tri[t2].push_back(t1);
    }
    ll lef=1,rig=n,cuts,cou=0,ans=1;
    while (lef<=rig)    
    {
        ll mid=(lef+rig)/2;
        cuts=0;
        ll tt = dfscut(1,tri,cuts,mid,-1);
            cuts--;
        // cout << tt << " : tt " << cuts << " : cuts , for mid : " << mid << endl;
        if(k<cuts){
            lef=mid+1;
        }
        else if(k==cuts){
            ans=mid;
        }
        else{
            rig=mid-1;
        }
        if (cou>10)
        {
            break;
        }
        cou++;
    }

    // for (ll  i = 1; i < n ; i++)
    // {   
    //     cuts =0;
    //     dfscut(1,tri,cuts,i,-1);
    //     cout <<  "no of cuts : " << cuts << " min no of elements : " << i << endl;
    // }
    
    cout << ans << endl;
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