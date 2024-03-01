#include <bits/stdc++.h>
using namespace std;
# define ll long long
int seiv[1000001];


// index
// fill prime seive
// prime factors map


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
    return m;
}



int main(){
    map<ll,ll> m=prime_factors();

    for(auto i:m){
        cout << i.first << "=" << i.second << endl;
    }
    return 0;
}   