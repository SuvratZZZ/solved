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
        ll n,down=1,up=1;
        cin >> n;
        vector<int> v(n),ups(n),dps(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i]; 
        }
        ll m;
        cin >> m;
        vector<int> from(m),to(m);
        for (int i = 0; i < m; i++)
        {
            cin >> from[i] >> to[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (i==0)
            {
                ups[i]=1;
                // if (abs(v[i]-v[1])>abs(v[2]-v[1]))
                // {
                //     dps[i]=abs(v[i]-v[1]);
                // }
                // else{
                    dps[i]=0;
                // }
            }
            if (i==(n-1))
            {
                dps[i]=1;
                // if (abs(v[i]-v[i-1])>abs(v[i-2]-v[i-1]))
                // {
                //     ups[i]=abs(v[i]-v[i-1]);
                // }
                // else{
                    ups[i]=0;
                // }
            }
            
            if (i>1)
            {
                up=abs(v[i]-v[i-1]);
                down=abs(v[i-2]-v[i-1]);
                if (up>down)
                {
                    dps[i-1]=1;
                    ups[i-1]=abs(v[i-1]-v[i]);
                }
                else{
                    ups[i-1]=1;
                    dps[i-1]=abs(v[i-1]-v[i-2]);
                }
            }

        }

        // for (int i = 0; i < n; i++)
        // {
        //     // cout << ups[i] << " <<ups dps>> " << dps[i] << endl;
        // }
        
        for (int i = 1; i < n; i++)
        {
            ups[i]=ups[i]+ups[i-1];
            dps[n-i-1]=dps[n-i]+dps[n-i-1];
        }
        for (int i = 1; i < n; i++)
        {
            ups[n-i]=ups[n-i-1];
            dps[i]=dps[i+1];
        }
        ups[0]=0;
        dps[n-1]=0;
        
        // for (int i = 0; i < n; i++)
        // {
        //     cout << ups[i] << " <<ups dps>> " << dps[i] << endl;
        // }
        

        for (int i = 0; i < m; i++)
        {
            if (from[i]<to[i])
            {
                cout << abs(ups[from[i]-1] - ups[to[i]-1]) << endl;
            }
            else{
                cout <<  dps[to[i]-1] - dps[from[i]-1] << endl;
            }
        }
        
        
    }
    return 0;
}