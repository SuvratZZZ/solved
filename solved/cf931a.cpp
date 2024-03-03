#include <bits/stdc++.h>
using namespace std;
# define ll long long

void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll tem=n;
        vector<ll > a (n);
        ll i=0;
        while (tem--)
        {
            
            cin >> a [i];
            i++;
        }
        sort(a .begin(),a .end());
        ll ans =abs(a [0]-a [n-1])+abs(a [n-1]-a [1])+abs(a [1]-a [n-2])+abs(a [n-2]-a [0]);
        cout << ans  << endl;
    }
    return 0;
}