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
        ll n ,count=0;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> fact;
        for (ll i = 1; i <= sqrt(n); i++)
        {
            if (n%i==0)
            {
                if (i!=(n/i))
                {
                    fact.push_back(i);
                    fact.push_back(n/i);
                }
                else{
                    fact.push_back(i);
                }
                
            }
            
        }
        
        for(int i:fact)
        {   
            ll g=0;
            for (ll j = 0; j+i < n; j++)
            {
                g=__gcd(g,abs(v[j]-v[j+i]));
                
            }
            cout << g << "<G i>" << i << endl;
            if (g!=1)
            {
                // cout << "yay" ;
                count ++;
            }
            
        }
        cout << count << endl;
    }
    return 0;
}   