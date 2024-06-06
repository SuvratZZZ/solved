#include <bits/stdc++.h>
using namespace std;
# define ll long long

// index
// 1 substr_sum
// 2 bitwise left right
// 3 map - empty
// 4 hcf (aut0 &i:a)error
// 5 lambda func normal recursive func
// 6 subarray sum = 0 map only prefsum
// 7 seive and prime fac

// 1
void substr_sum(){
    ll n;
    cin >> n;
    string tt ,t2;
    getline(cin,tt);
    getline(cin,t2);
    string temp;
    // temp.push_back(tt[0]);
    // for (ll  i = 0; i < n ; i++)
    // {
    //     temp=tt.substr(0,i+1)+t2.substr(i,n-i);
    //     cout << temp << endl;
    // }
    cout << tt << endl;
    cout << t2 << endl;
    // ll i =2;
    // while (tt[i]!=' ')
    // {
    //     i++;
    // }

    // cout << (stoi(tt.substr(2,i-2))) << endl;
    // cout << (stoi(tt.substr(i+1,tt.length()-i-1))) << endl;
}

// 2
void bitwiselr(){
    ll n;
    cin >> n;
    ll tem= (1<<n);
    cout << tem << endl;
}

// 3
void mapii(){
    map<ll,ll> m;
    m[0]++;
    auto it=m.begin();
    it--;
    cout << it->first << " " << it->second ;
}

// 4
void hcf_find(){
    ll t,mx=INT_MIN,res;
    cin >> t;
    vector <ll> a(t);
    auto hcf=[&](auto self,ll n,ll m){      
        if (n%m==0)
        {
            return m;
        }
        else
        {
            return self(self,m,n%m);
        }
        
    };
    for (ll  i = 0; i < t; i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
        if(i==0)res=a[0];
        res=hcf(hcf,a[i],res);
    }
    
    cout << res << endl;
    // while (t--)
    // {
    //     ll a,b;
    //     cin >> a >> b;
    //     cout << hcf(a,b) << endl;
    // }
}


// 5
ll dfs(ll ind, string s, vector<ll> tre[]){
    if(tre[ind].empty()){
        // cout << ind << " is terminal " << endl;
        return 0;
    }
    ll r1 = INT_MAX;
    ll r2=INT_MAX,r3=INT_MAX;
    if (s[ind-1]=='U')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called U" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='L')
    {
        if (tre[ind][0]!=0)
        {
            r2=0+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called L" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='R')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+dfs(tre[ind][0],s,tre);
        }
        if (tre[ind][1]!=0)
        {
            r3=0+dfs(tre[ind][1],s,tre);
        }
        r1=min(r2,r3);
        // cout << "called R" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    return r1;
}
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> tre(n+1);
    for (ll  i = 1; i <= n ; i++)
    {
        ll tem1,tem2;
        cin >> tem1 >> tem2;
        if (tem1==0&&tem2==0)
        {
            // cout << "empty " << i << " ";
            continue;
        }
        tre[i].push_back(tem1);
        tre[i].push_back(tem2);
    }
    
    // cout << " is 0 empty " << tre[0].empty() << endl;
    
    auto dfs2 = [&](auto self,ll ind)-> ll {
        if(tre[ind].empty()){
        // cout << ind << " is terminal " << endl;
        return 0;
    }
    ll r1 = INT_MAX;
    ll r2=INT_MAX,r3=INT_MAX;
    if (s[ind-1]=='U')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called U" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='L')
    {
        if (tre[ind][0]!=0)
        {
            r2=0+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=1+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called L" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    if (s[ind-1]=='R')
    {
        if (tre[ind][0]!=0)
        {
            r2=1+self(self,tre[ind][0]);
        }
        if (tre[ind][1]!=0)
        {
            r3=0+self(self,tre[ind][1]);
        }
        r1=min(r2,r3);
        // cout << "called R" << s[ind-1] << " index-> " << ind  << " " << r1 << " r r " << r2 << " r r " << r3 << endl;
    }
    return r1;
    }; 
    ll ans=dfs2(dfs2,1);
    // cout << dfs(1,s,tre) << endl;
    cout << ans << endl;
}

// 6
void prefs(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> m;
    m[0]=1;
    ll s=0;
    for (ll  i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    for (ll  i = 0; i < n ; i++)
    {
        a[i]=a[i]*((i%2)?-1:1);
        s=s+a[i];
        if(m[s]){
            cout << "YES" << endl;
            return;
        }
        m[s]++;
    }
    cout << "NO" << endl;
}

// 7
const int N = 1e6+5;
int fact[N];
void fill_fact(){
    for(int i=0;i<=N;i++){
        fact[i]=i;
    }
    for(int i=2;i*i<=N;i++){
        for(int j=i*i;j<=N;j=j+i){
            if(fact[j]==j){
                fact[j]=i;
            }
        }
    }
}
void fin_fact(){
    int n ; cin>>n;
    // will not have 1 as prime 
    vector<int> res;
    int tt=n;
    while(tt!=1){
        cout << fact[tt] << " ";
        tt=tt/fact[tt];
    }
}

int main(){
    ll t;
    t=1;
    
    cin >> t;
    while(t--){
        // bitwiselr();
        // mapii();
        // hcf_find();
        // substr_sum();
        // prefs();
        // fill_fact();
        // fin_fact();
        cout << endl;
    }
    return 0;
}