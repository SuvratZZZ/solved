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
int main(){
    ll t;
    cin>> t;
    while(t--){
        ll n, a, k,res=INT_MIN,tem=0;
        cin >> n >> a >> k;
        vector<ll> v(n),ps(n+1);
        ps[0]=0;
        for (ll l = 0; l < n; l++)
        {
            cin >> v[l];
        }
        sort(v.begin(),v.end());
        for (ll i = 1; i <= n; i++)
        {   
            if (i==1)
            {
                ps[i]=v[i-1];
            }
            ps[i]=ps[i-1]+v[i-1];
        }
        for (ll i = 0; i <= a; i++)
        {
            ll b=n-i,c=n-i-k;
            if ((n-i-k)<0)
            {
                c=0;
            }
            tem=ps[n]-(ps[n]-ps[b])-(2*(ps[b]-ps[c]));
            res=max(tem,res);
            // cout << tem << " <tem ps res> " << res << ps[n] << " " << ps[b] << " " << ps[c] << endl;
        }
        cout << res << endl;
    }
    return 0;
}