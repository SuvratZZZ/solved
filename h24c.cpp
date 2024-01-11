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
// subsequences = same seq but discontinue 
int main(){
    ll t;
    cin>> t;
    while(t--){
        ll n,tem=0,i1=0,i2=0,a1=0,a2=0;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            cin >> tem;
            if (i>0)
            {
                if (tem > a1)
                {
                    if (a2!=0)
                    {
                        if (tem > a2)
                        {
                            i2++;
                            (a1>a2?a2=tem:a1=tem);
                        }    
                    }
                    else{
                        a2=tem;
                    }
                }
                else{
                    if (a2 > tem)
                    {
                        (a1>a2?a2=tem:a1=tem);
                    }
                    else{
                        a1=tem;
                    }
                }
            }
            else
            {
                a1=tem;
            }
            v.push_back(tem);
        }
        cout << i1+i2 << endl;
    }
    return 0;
}