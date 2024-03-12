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
void solve2(){
    ll n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> v(n,97);
    ll index=0;
    vector<bool> hsh(k,true);
    string result;
    for (int i = 0; i < n ; i++)
    {   
        for(int j=0;j<k;j++){hsh[j]=true;}
        ll count=0;
        while ((index<s.length())&&(count<k))
        {
            if (((int)s[index]<(97+k))&&hsh[(int)s[index]-97])
            {
                count++;
                hsh[(int)s[index]-97]=false;
                if(result.length()<i+1){result.push_back(s[index]);}
                result[i]=s[index];
                // cout << result << "<- res" << endl;
            }
            
            index++;
        }
            v[i]=v[i]+count-1;
            // cout << (int)s[index] << " result-> " << hsh[(int)s[index]-97] << endl;
        if (index>=s.length())
            {

                break;
            }
    }
    // for (int i: v){ cout << i << endl;}
    for (int i = 0; i < n ; i++)
    {
        if ((v[i]==(97+k-1))&&(i==n-1))
        {
            cout << "YES" << endl;
                // cout << v[i] << " result-> " << result << endl;
            return;
        }

    }
    char missing;
    for (int i = 0; i < k; i++)
    {
        if(hsh[i]){
            result[(int)result.length()-1]=((char)97+i);
            missing=(char)97+i;
            break;
        }
    }
    
    for (int i = result.length(); i < n ; i++)
    {
        result.push_back(missing);
    }
    cout << "NO\n" << result << endl;
    return;
}

void solve(){
    ll n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> v(n,97);
    ll index=0;
    vector<bool> hsh(k,true);
    string result;
    ll i =0;
    while (i<(n*k)||i<m)
    {
        
        
        
        i++;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}   