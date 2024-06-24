#include <bits/stdc++.h>
using namespace std;
# define ll long long

// 1 finwick tree


// 1 
void add_a2k(ll a,ll k,vector<ll> &jw){
    while(k<jw.size()){
        jw[k]=jw[k]+a;
        k=k+(k&-k);
    }
}
ll fin_sm2k(ll k,vector<ll> &jw){
    ll sum=0;
    while(k>0){
        sum=sum+jw[k];
        k=k-(k&-k);
    }
    return sum;
}
void jwt(ll n, vector<ll> &arr, ll q, vector<vector<ll>> &qu) {
    // vector<ll> jw={0,1,2,3,4,5,6,7,8};
    // cout << fin_sm2k(7, jw) << endl;
    vector<ll> jw(n+1,0);
    vector<ll> ps(n+1,0);
    for(ll i=0;i<n;i++)ps[i+1]=ps[i]+arr[i];
    for(ll i=1;i<=n;i++){
        // jw[i]=ps[i]-ps[i-(i&-i)];
        add_a2k(arr[i-1], i , jw);
    }
            // for(ll i:jw)cout << i << " " ;
            // cout << endl;
    for(ll i=0;i<q;i++){
        if (qu[i][0] == 1) {  // Range sum query
            cout << fin_sm2k(qu[i][2] + 1, jw) - fin_sm2k(qu[i][1], jw) << endl;
        }
        else{
            add_a2k(qu[i][2] - arr[qu[i][1]], qu[i][1] + 1, jw);
            arr[qu[i][1]] = qu[i][2];
            // for(ll i:jw)cout << i << " " ;
            // cout << endl;
        }
    }
}
void chu(){
    ll n, q;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<ll> arr(n);

    cout << "Enter the elements of the array: ";
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of queries: ";
    cin >> q;

    vector<vector<ll>> qu(q, vector<ll>(3));

    cout << "Enter the queries (format: type l r): " << endl;
    for (ll i = 0; i < q; i++) {
        cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
    }
    jwt(n, arr, q, qu);
}







ll main(){
    ll tt;
    cin>> tt;
    while(tt--){
        chu();
    }
    return 0;
}