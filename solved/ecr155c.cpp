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

ll n(ll n, ll r){
    double sol=1;
    for (ll i = 1; i <= r; i++)
    {
        sol=sol*((n-r+i)/i);
        // cout << n-r+i << " solution is " << sol << endl;
    }
    return (ll)sol;
}

ll fac(ll n,ll &mod){
    if(n<2){
        return 1;
    }
    return n*fac(n-1,mod)%mod;
}

int main(){
    ll mod=998244353;
    ll t;
    cin>> t;
    while(t--){
        ll res=0,res2=1,tempo=1;
        string s,alt,tem;
        cin >> s;
        alt=s[0];
        for (ll i = 1; i < s.length(); i++)
        {
            tem=s[i];
            if(alt==tem){
                res++;
                tempo++;
            }
            else{
                alt=s[i];
                if(tempo!=0){
                res2=(res2*tempo)%mod;}
                tempo=1;
            }

        }
            if(tempo!=0){
                res2=(res2*tempo)%mod;}
                res2=res2*fac(res,mod)%mod;
        cout << res << " " << res2 << endl;

         
    }
    return 0;
}