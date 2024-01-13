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
        ll n,k,d,tem;
        cin >> n >> k >> d ;
        // cout << n << k << d ;
        vector<ll> a,v;
        for (int i = 0; i < n; i++)
        {
            cin  >> tem;
            a.push_back(tem);
        }
         for (int i = 0; i < k; i++)
        {
            cin  >> tem;
            v.push_back(tem);
        }
        
    }
    return 0;
}