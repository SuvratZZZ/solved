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
         int n , k ;
         cin >> n >> k;
         string s;
         for (int i = 0; i < k; i++)
         {
            s.push_back((char)97+i);
         }
         for (int i = 0; i < n-1; i++)
         {
            s=s+s;
         }
         cout << s << endl;
    }
    return 0;
}