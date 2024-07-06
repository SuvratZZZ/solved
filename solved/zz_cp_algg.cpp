#include <bits/stdc++.h>
using namespace std;
# define ll long long

// 1 finwick tree
// 2 DSU


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
void demofw(){
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


// 2
class CHU
{
public:
    vector<ll> prt,siz,ran;
    CHU(ll n){
        prt.resize(n+1);
        siz.resize(n+1,1);
        ran.resize(n+1,1);
        for (ll i = 0; i < n+1; i++)
        {
           prt[i]=i;
        }
    }
    ll fin_prt(ll n)
    {
        if(prt[n]==n)return n;
        else return prt[n]=fin_prt(prt[n]);
    }
    ll fin_siz(ll n){
        ll pp=fin_prt(n);
        return siz[pp];
    }
    void ubs(ll u,ll v)
    {
        ll pu=fin_prt(u);
        ll pv=fin_prt(v);
        if(pu!=pv){
            if (siz[pu]>siz[pv])
            {
                prt[pv]=pu;
                siz[pu]+=siz[pv];
            }
            else{
                prt[pu]=pv;
                siz[pv]+=siz[pu];
            }
        }
    }
};
void demochu(){
    CHU cha(10);
    cha.ubs(1,5);
    cha.ubs(1,6);
    cha.ubs(7,3);
    // cha.ubs(7,5);
    for (ll i = 0; i < 11; i++)
    {
        cout << cha.prt[i] << " parent of : " << i << endl;
        cout << cha.siz[i] << " siz of    : " << i << endl;
    }
}





int main(){
    ll tt;
    cin>> tt;
    while(tt--){
        // demofw();
        demochu();
    }
    
    return 0;
}