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


ll ncr(ll n, ll r){
    double sol=1;
    for (ll i = 1; i <= r; i++)
    {
        sol=(sol*(n-r+i))/i;
    }
    return (ll)sol;
}


int main(){
    ll t;
    cin>> t;
    while(t--){
        ll n,res=0;
        cin >> n;
        vector<int> v(n);
        map<int,int> count;
        map<int,int> prefs;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            count[v[i]]++;   
        }

        sort(v.begin(),v.end());
        for (int i = 0; i < n; i++)
        {
            if ((i>0)&&(v[i]!=v[i-1]))
            {
                prefs[v[i]]=i;
            }
        }
        prefs[v[0]]=0;
        // auto pre = count.begin();
        for(auto it = count.begin(); it!=count.end(); it++){
            if(it->second >= 3){
                res=res+ncr(it->second,3);
            }
            if(it->second >=2){
                res=res+(ncr(it->second,2)*prefs[it->first]);
            }
        }
        cout << res << endl;
    }
    return 0;
}