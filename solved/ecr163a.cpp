#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define pb push_back
# define fl(i,len) for(ll i=0; i< len ;i++)
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
    
}
int main(){
    
    ll tes;
    cin >> tes;
    while(tes--){
        ll len;
    cin >> len;
    if (len%2)
    {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for (ll  i = 0; i < len ; i=i+2)
        {
            if (i!=0){
                cout << "Z" ;
            }
            cout << "TT" ;
        }
        cout << endl;
    }
    }
    return 0;
}