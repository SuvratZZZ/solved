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
        ll n,k,d,tem,cou=0,mcou=0,md=0,init;
        cin >> n >> k >> d ;
        // cout << n << k << d ;
        vector<ll> a,v;
        for (int i = 0; i < n; i++)
        {
            cin  >> tem;
            if (i+1==tem)
            {
                cou++;
            }
            a.push_back(tem);
        }
        init=cou;
        mcou=max(cou,mcou);
        cou=0;
         for (int i = 0; i < k; i++)
        {
            cin  >> tem;
            v.push_back(tem);
        }
        for (int j = 0; j < min(2*n,d); j++)
        {
            cou=0;
            for (int i = 0; i < v[j%k]; i++)
            {
                a[i]=a[i]+1;
                if (a[i]==i+1)
                {
                    cou++;
                }
                
            }
            if (cou>mcou)
            {
                mcou=cou;
                md=j+1;
            }
            
        }
        // cout << mcou << " <<mcou md init>> " << md << " " << init << endl;
        ll r1= mcou+((d-md-1)/2);
        ll r2= init+((d-1)/2);
        if (md==d)
        {
            cout << r2 << endl;
        }
        else
        cout << max(r1,r2) << endl;
    }
    return 0;
}