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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;
const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
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
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> ans(n,0);
    vector<ll> poi;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(a[i]!=-1){
            ans[i]=a[i];
            poi.push_back(i);
        }
    }
    if(poi.size()==0){
        for (ll  i = 0; i < n ; i++)
        {
            cout << pow(2,i) << " ";
        }
        cout << endl; return;
    }
    for(ll i=poi[0]-1;i>=0;i--){
        ans[i]=ans[i+1]*2;
    }
    for(ll i=poi[poi.size()-1]+1;i<a.size();i++){
        ans[i]=ans[i-1]*2;
    }
    if(poi.size()==1){
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    // cout << " do n \n";
    for (ll i = 0; i < poi.size()-1; i++)
    {
        ll l=poi[i],r=poi[i+1];
        while (l<r)
        {
            if (abs(l-r)==2){
                if(ans[l]/2!=ans[r]/2){
                    cout << -1 << endl;return;
                }
                else{
                    if(ans[l]==ans[r])
                        ans[l+1]=ans[l]*2;
                    else{
                        ans[l+1]=ans[l]/2;
                    }
                    break;
                }
            }
            if (abs(l-r)==1)
            {
                if((ans[r]!=(ans[l]/2))&&(ans[r]/2!=ans[l]))
                    {cout << -1 << endl;return ;}
                else{
                    break;
                }
            }
            if((ans[l]>ans[r])&&(ans[l]/2!=ans[r]/2)){
                ans[l+1]=ans[l]/2;
                l++;
            }
            else if(ans[l]<ans[r]&&ans[l]/2!=ans[r]/2){
                ans[r-1]=ans[r]/2;
                r--;
            }
            else{
                if(ans[l]==ans[r]){
                    if(ans[l]==1){
                        ans[r-1]=ans[r]*2;
                        ans[l+1]=ans[l]*2;
                    }
                    else{
                        ans[r-1]=ans[r]/2;
                        ans[l+1]=ans[l]/2;
                    }
                    l++;
                    r--;
                }
                else{
                    ans[r-1]=ans[r]/2;
                    ans[l+1]=ans[l]/2;
                    l++;
                    r--;
                }
            }
            // cout << l <<" : l , r : " <<  r << " al " << ans[l] << " ar : " << ans[r] << endl; 
        }
    }
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor()
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}