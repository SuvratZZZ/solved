// done
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
    ll n,m,br,cp=0,ct=0,tf=0,pf=0;
    cin>>n>>m;
    vector<ll> a(n+m+1),b(n+1+m),prp(n+m+2,0),prt(n+m+2,0);
    for (ll  i = 0; i < n+m+1; i++)
    {
        cin>>a[i];
    }
    for (ll  i = 0; i < n+m+1; i++)
    {
        cin>>b[i];
    }
    for (ll  i = 0; i < n+m+1; i++)
    {
        if(a[i]>b[i]){
            cp++;
            prp[i+1]=prp[i]+a[i];
            prt[i+1]=prt[i];
            if(cp>=n+1){
                br=i;
                pf=1;
                break;
            }
        }
        else{
            ct++;
            prt[i+1]=prt[i]+b[i];
            prp[i+1]=prp[i];
            if(ct>=m+1){
                br=i;
                tf=1;
                break;
            }
        }
        
    }
    if(pf==1){
        for (ll  i = br+1; i < n+m+1; i++)
        {
            prt[i+1]=prt[i]+b[i];
            prp[i+1]=prp[i];
        }
    cout << prp[n+m+1] << " dd " << prt[n+m+1] << endl;
        for (ll  i = 0; i < n+m+1; i++)
        {
            if(i<=br){
                if(a[i]>b[i]){
                    cout << prp[n+m+1]+prt[n+m+1]-max(a[i],b[i]) << " ";
                }
                else{
                    cout << prp[n+m+1]+prt[n+m+1]-max(a[i],b[i])-a[br]+b[br] << " ";
                }
            }
            else{
                cout << prp[n+m+1]+prt[n+m+1]-b[i]-a[br]+b[br] << " ";
            }
        }
    }
    else{
        for (ll  i = br+1; i < n+m+1; i++)
        {
            prp[i+1]=prp[i]+a[i];
            prt[i+1]=prt[i];
        }
    cout << prp[n+m+1] << " dd " << prt[n+m+1] << endl;
        for (ll  i = 0; i < n+m+1; i++)
        {
            if(i<=br){
                if(a[i]<b[i]){
                    cout << prp[n+m+1]+prt[n+m+1]-max(a[i],b[i]) << " ";
                }
                else{
                    cout << prp[n+m+1]+prt[n+m+1]-max(a[i],b[i])+a[br]-b[br] << " ";
                }
            }
            else{
                cout << prp[n+m+1]+prt[n+m+1]-a[i]+a[br]-b[br] << " ";
            }
        }
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