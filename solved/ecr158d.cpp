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
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> tem;
    ll mx=INT_MIN,at;
    for (ll  i = 0; i < n ; i++)
    {
        cin>>a[i];
        if(mx<a[i]){
            mx=a[i];
            at=i;
        }
    }
        ll l=at-1,r=at+1;
        tem.push_back(a[at]);
        while (l>=0||r<n)
        {
            if(l>=0){
                if((a[l]<a[r])||(r==n)){
                    tem.push_back(a[l]);
                    l--;
                }
                else{
                    tem.push_back(a[r]);
                    r++;
                }
            }
            else{
                tem.push_back(a[r]);
                r++;
            }
        }

        // for(auto i:tem){
        //     cout << i << " ";
        // }
    // sort(a.rbegin(),a.rend());
    // reverse(a.begin()+1,a.end());
    auto che=[&](ll mid)->bool{
        // cout << "mid : " << mid << " " ;
        ll im = mid;
        for (ll  i = 0; i < n ; i++)
        {
            if(mid<tem[i]){
                // cout << im  << " : int " << mid << " <at< " << tem[i] << endl;
                return 0;
            }
            mid--;   
        }
        return 1;
    };

    l=0;r=1e15;
    while (l<r)
    {
        ll mid=(l+r)/2;
        if(che(mid)){
            r=mid;
            // cout << " a ";
        }
        else{
            l=mid+1;
        }
    }
    cout << l << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}