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
    ll n,k;
    cin>>n>>k;
    ll i =0,ind=(n+1)/2,prev=0;
    
    for( ; i <= 30 ; i++){
        if (ind >= k||ind<0)
        {
            break;
        }
        prev=ind;
        ind=ind+((n-(ll)pow(2,i+1))/(ll)pow(2,i+2))+1;
        // cout << "ind : " << ind << endl;
        
    }
    // cout << "i : " << i << endl;
    ll res=pow(2,i)+(pow(2,i+1)*(k-prev-1));
    cout << res << endl;
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