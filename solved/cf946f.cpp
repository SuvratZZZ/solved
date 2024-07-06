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
void solve(){
    ll aa,b,n,m;
    cin>>aa>>b>>n>>m;
    vector<pair<ll,ll>> xc,yc;
    set<pair<ll,ll>> del;
    for (ll  i = 0; i < n ; i++)
    {
        ll tem ,t2;
        cin>>tem>>t2;
        xc.push_back({tem,t2});
        yc.push_back({t2,tem});
    }
    sort(xc.begin(),xc.end());
    sort(yc.begin(),yc.end());
    ll r1=0,r2=0,l=1,r=b,u=1,d=aa;
    ll il=0,ir=n-1,iu=0,id=n-1;
    bool al=1;
    for (ll i = 0; i < m ; i++)
    {
        char a;ll k;
        cin>>a>>k;
        if(a=='U'){
            ll end=k+u-1;
            // ll start=xc.lower_bound({u,LLONG_MIN});
            u+=k;
            while (xc[iu].first<=end&&iu<n)
            {
                if(del.find(xc[iu])==del.end()){
                    del.insert(xc[iu]);
                    (al==1?r1++:r2++);
                }
                iu++;
            }
            
        }
        else if(a=='D'){
            ll end=d-k+1;
            // ll start=xc.lower_bound({u,LLONG_MIN});
            d-=k;
            while (xc[id].first>=end&&id>=0)
            {
                if(del.find(xc[id])==del.end()){
                    del.insert(xc[id]);
                    (al==1?r1++:r2++);
                }
                id--;
            }
        }
        else if(a=='L'){
            ll end=k+l-1;
            // ll start=xc.lower_bound({u,LLONG_MIN});
            l+=k;
            while (yc[il].first<=end&&il<n)
            {
                if(del.find({yc[il].second,yc[il].first})==del.end()){
                    del.insert({yc[il].second,yc[il].first});
                    (al==1?r1++:r2++);
                }
                il++;
            }
        }
        else if(a=='R'){
            ll end=r-k+1;
            // cout << end << "=end;" << endl;
            // ll start=xc.lower_bound({u,LLONG_MIN});
            r-=k;
            while (yc[ir].first>=end&&ir>=0)
            {
                // cout << yc[ir].first << " <yc> " << yc[ir].second << endl;
                if(del.find({yc[ir].second,yc[ir].first})==del.end()){
                    del.insert({yc[ir].second,yc[ir].first});
                    (al==1?r1++:r2++);
                }
                ir--;
            }
        }
        // cout << "lef : " << l << " , rig : " << r << " , up : " << u << " , do : " << d << endl;
        // cout << "r1 : " << r1 << " , r2 : " << r2  << endl;
        al=!al;
    }
    cout << r1 << " " << r2 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}