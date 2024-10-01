#include <bits/stdc++.h>
using namespace std;
# define ll long long

const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
const ll mod = 1e9+7;
const int LLL = 1e6+5;
ll finpo(ll &i,ll &ood,ll &eve){
    ll tem;
    if(i%2){
            tem=ood;
            ood--;
        }
        else{
            tem=eve;
            eve++;
        }
        return tem;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin >> t;
    while(t--){
        ll n;
    cin>>n;
    vector<ll> arr(n);
    ll eve=(n/2)+1;ll ood=n/2;
    if(n%2==0){
        cout << -1 << endl;continue;
    }
    for (ll  i = 1; i <= n ; i++)
    {
        arr[finpo(i,ood,eve)]=i;
    }
    for (auto i:arr)cout << i << " ";
    cout << endl;
    }
    return 0;
}