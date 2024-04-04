#include <bits/stdc++.h>
using namespace std;
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    fl (i , n)
    {
        cin >> a[i];
    }
    ll curr = a[0]/10;
    ll flag = 1;
    for (ll  i = 0; i < n-1 ; i++)
    {
        if(a[i+1]<a[i]){
            if(a[i]>9){
                    if (a[i]/10<curr)
                    {
                        cout << "NO" << endl;
                        flag=0;
                        break;
                        
                    }
                    if ((a[i]/10>a[i]%10))
                    {
                        cout << "NO" << endl;
                            flag=0;
                            break;
                    }
            }
            else{
                if (a[i]<curr)
                {
                    cout << "NO" << endl;
                    flag=0;
                    break;
                }
            }
        }
        curr = a[i]%10;
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    
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