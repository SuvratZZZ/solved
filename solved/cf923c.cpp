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
    ll n,m,k,comms=0;
    cin >> n >> m >> k;
    set<int> a;
    set<int> b;
    map<int,int> mapp;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        if(tem<=k){a.insert(tem);
            mapp[tem]=1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int tem;
        cin >> tem;
        if(tem<=k){b.insert(tem);
            if (mapp[tem])
            {
                comms++;
                mapp[tem]--;
            }
            
        }
    }

    // cout << a.size() << " a b " << b.size() << " comms " <<  comms << endl;
    if(a.size()<(k/2)||b.size()<(k/2)){
        cout << "NO" << endl;
        return; 
    }
    if((a.size()+b.size()-comms)==k){
        cout << "YES" << endl;
        return;
    }
        cout << "NO" << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
