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

int seiv[1000001];
void fill_seiv(){
    int i=2,j=2;
    while(i*j<=100000){
            seiv[i*j]=1;
            j++;
        }
    for (ll i = 3; i <= 1000; i=i+2)
    {
        int j=2;
        if(seiv[i]==0){
            while(i*j<=100000){
                seiv[i*j]=1;
                j++;
            }
        }
        else{continue;}
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> m;

    for (ll i = 0; i < n ; i++)
    {
        cin >> a[i];
        ll tem=a[i];
        // while (tem%2==0)
        // {
        //     m[2]++;
        //     tem=tem/2;
        //     if(seiv[tem]==0&&(tem>(ll)sqrt(a[i])))
        //     {
        //         m[tem]++;
        //     }
        // }
        // // cout << "2 = " <<  m[2] << endl;
        // for (ll  qo = 3; qo <= (ll)sqrt(a[i]); qo=qo+2)
        // {   
        //     tem=a[i];
        //     if(seiv[qo]==0){
        //         while (tem%qo==0)
        //         {
        //             m[qo]++;
        //             tem=tem/qo;
        //             if(seiv[tem]==0&&tem!=qo&&(tem>(ll)sqrt(a[i])))
        //             {
        //                 m[tem]++;
        //             }
        //         }
        //     }
        //     cout << qo << " inside = " <<  m[qo] << endl;
        //     cout << "2 inside = " <<  m[2] << endl;
        // }
        // if(seiv[a[i]]==0){
        //     m[a[i]]++;
        // }

        for (ll qs = 2; qs*qs <= tem; qs++)
        {
            while (tem%qs==0)
            {
                m[qs]++;
                tem=tem/qs;
            }
        
        }
        if(tem>1){
            m[tem]++;
        }
    }
    for(auto i:m ){
        if ((i.first!=1)&&(i.second%n!=0))
        {
            cout << "NO" << endl;
            return;
        }
        cout << i.first << "=" << i.second << endl;
    }
    cout << "YES" << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    fill_seiv();
    
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}