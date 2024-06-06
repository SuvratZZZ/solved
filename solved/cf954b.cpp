#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
    for(int i=0;i<n;i++) {

}

cin>>a[i];

int ans = 1;

int mx =max_element(a.begin(), a.end());

int n1 =log2(mx) + 1;

int cnt=0;

int curr_mx = 0;

for (int i = 0; i < n1; i++)

{

int mask= 1 << i;

cnt = 0;

curr_mx=0;

    for (int j = 0; j < a.size(); j++)

    {

    if (!(a[j] & mask))

    {

    cnt++;

    }

    else{ curr_mx=max(curr_mx, cnt); cnt=0;

        }

    }   

    curr_mx = max(curr_mx, cnt);

    if(cnt<a.size()) {

        ans=max(ans, curr_mx+1);

    }

    }

    cout<<ans<<endl;
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