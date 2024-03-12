#include <bits/stdc++.h>
using namespace std;
# define ll long long
int seiv[1000001];


// index
// 1 fill prime seive
// 2 prime factors map
// 3 most optimised -- ek hi bachega concept
// 4 multiset 

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

// 4
void multi_cf932c(){
    ll n;
    cin >> n;
    multiset<ll> mm;
    for (ll  i = 0; i < n ; i++)
    {
        ll tem;
        cin>> tem;
        mm.insert(tem);
    }
    ll tem ;
    cin >> tem ;
                    ll max_value = *mm.rbegin();
                    mm.erase(max_value);
    for(auto it:mm){
        cout << it << endl;
    }
}
void sss(){
    
    int t = 1;
    std::cin >> t;
    while (t--) {
        int n, L;
        std::cin >> n >> L;
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0 ; i < n ; i++) {
            std::cin >> v[i].second >> v[i].first;
        }
        sort(v.begin(), v.end());

        int ans = 0;
        for (int l = 0 ; l < n ; l++) {
            multiset<int> s;
            int cur = 0;
            for (int r = l ; r < n ; r++) {
                s.insert(v[r].second);
                cur += v[r].second;
                while (!s.empty() && v[r].first - v[l].first + cur > L) {
                    int max_value = *s.rbegin();
                    cur -= max_value;
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
                ans = std::max(ans, (int) s.size());
            }
        }
        cout << ans << endl;
    }
}
int main(){
    // map<ll,ll> m=prime_factors();
    // prime_factors_opt();
    // multi();
    // sss();
    return 0;
}   