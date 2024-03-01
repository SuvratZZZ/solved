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
        ll a,b,r;
        cin >> a >> b >> r;
        ll at=a,bt=b,res=INT_MAX;
        if (at>bt)
        {
            swap(at,bt);
        }
        ll j=0,x=0,alt=1;
        while((at>0)&&(x<r)){
            if(((at&1)&&((~bt)&1))^(((~at)&1)&&(bt&1))){
                if ((alt==0)&&((at&1)&&((~bt)&1)))
                {
                    x=x+(1<<j);
                    alt=1;
                }
                if ((alt==1)&&(((~at)&1)&&(bt&1)))
                {
                    x=x+(1<<j);
                    alt=0;
                }
                
            }
            res=min(res,abs((a^x)-(b^x)));
            at=at>>1;
            bt=bt>>1;
            j++;
        }
        cout << res << endl;
    }
    return 0;
}   