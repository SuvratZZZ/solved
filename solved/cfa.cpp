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
        ll n,a1=INT_MIN,a2=INT_MAX,tem1=0,tem2=0,res=0;
        set<ll> a3;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tem1;
            cin >> tem2;
            if (tem1==1)
            {
                a1=max(a1,tem2);
            }
            else if (tem1==2)
            {
                a2=min(a2,tem2);
            }
            else{
                a3.insert(tem2);
            }
        }
        res=a2-a1+1;
        for (ll i : a3)
            {
                if ((i>=a1)&&(i<=a2))
                {   
                    res--;
                }
            }
            if(res>0){cout << res << endl;}
            else{cout << 0 << endl;}
                
            
        
    }
    return 0;
}