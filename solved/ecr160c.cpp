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
    ll n,a,b;
    cin >> n;
    ll m[30]={0};
    for (ll  i = 0; i < n ; i++)
    {
        cin >> a >> b;
        if (a==2)
        {
            
            long long tem2 = b;
            for (ll ii = 29; ii >= 0; ii--)
            {
               ll mn=min(m[ii],tem2>>ii);
                tem2=tem2-((1<<ii)*mn);

                if (tem2==0)
                {
                    cout << "YES" << endl;
                    break;
                }
                if(ii==0){
                    cout << "NO" << endl;
                    break;
                } 
            }
            
                
            

        }
        if (a==1)
        {
            m[b]++;
        }
        
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
        solve();
    return 0;
}