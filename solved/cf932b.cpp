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
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <ll> a(n);
        ll sni=0 ,mx=INT_MIN;
        map<ll,ll> hsh;
        map<ll,ll> hsh2;
        bool yay=0,same=1,zero=0;
        for (ll  i = 0; i < n ; i++)
        {
            cin >> a[i];
            hsh[a[i]]++;
        }
        ll jj=0;
        set <ll> s,ss;
        while (hsh[jj]>=2)
        {
            s.insert(jj);
            ss.insert(jj);
            jj++;
        }
        if (hsh[jj]>0   )
        {
            cout << -1 << endl;
            // cout << "this is =1 " << jj << endl;
            continue;
        }
        else{
            ll rev =0;
            for (rev = 0; rev < n ; rev++)
            {
                if (s.find(a[rev])!=s.end())
                {
                    s.erase(a[rev]);
                }
                if (s.empty())
                {
                    break;
                }
            }
            ll res=rev;
            for (ll i = rev+1; i < n; i++)
            {
                if (ss.find(a[i])!=ss.end())
                {
                    ss.erase(a[i]);
                }
                
            }
            
            if (ss.empty())
            {
                cout << 2 << endl;
                cout << 1 << " " << res+1 << endl;
                cout << res+1+1 << " " << n << endl;
            }
            else{
                cout << -1 << endl;
            }
            

        }
        
        
    }
    return 0;
}