#include <bits/stdc++.h>
using namespace std;
# define ll long long
int seiv[1000001];


// index
// 1 fill prime seive
// 2 prime factors map
// 3 most optimised -- ek hi bachega concept

// 1
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

// 2
map<ll,ll> prime_factors(){
    fill_seiv();
    ll tt;
    cin>> tt;
    map<ll,ll> m;
    while(tt--){
        ll nono;
        cin >> nono ;
        ll tem=nono;
        while (tem%2==0)
        {
            m[2]++;
            tem=tem/2;
            if(seiv[tem]==0){
                m[tem]++;
            }
        }
        for (ll  n = 3; n <= (ll)sqrt(nono); n=n+2)
        {   
            tem=nono;
            if(seiv[n]==0){
                while (tem%n==0)
                {
                    m[n]++;
                    tem=tem/n;
                    if(seiv[tem]==0){
                        m[tem]++;
                    }
                }
            }
        }
        if(seiv[nono]==0){
            m[nono]++;
        }
    }
    for(auto i:m){
        cout << i.first << "=" << i.second << endl;
    }
    return m;
}

// 3
map<ll,ll> prime_factors_opt(){
    ll tem;
    cin >> tem;
    map<ll,ll> m;
    for (ll qs = 2; qs*qs <= tem; qs++)
    {
        while (tem%qs==0)
        {
            m[qs]++;
            tem=tem/qs;
        }
    }
    // jo fac divide nai hua wo prime sirf ek hoga aur prime bhi
    // ....p1*p2*p2=n  i*i<=n  (i will go more p2)
    if(tem>1){
        m[tem]++;
    }
    for(auto i:m){
        cout << i.first << "=" << i.second << endl;
    }
    return m;
}


int main(){
    // map<ll,ll> m=prime_factors();
    // prime_factors_opt();

    return 0;
}   