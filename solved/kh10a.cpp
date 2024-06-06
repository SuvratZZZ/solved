#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main(){
    ll tt;
    cin>> tt;
    while(tt--){
        ll n;
        cin>>n;
        ll res=INT_MAX;
        for (ll  i = 0; i <=4 ; i++)
        {
            ll tem=n;
            if (tem-(i*3)>=0)
            {
                tem-=(i*3);
                
            }
            
            res=min(res,tem%5);
        }
        cout << res << endl;
    }
    return 0;
}