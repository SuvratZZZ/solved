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
typedef map<ll,ll> mll;


void prefix_sum() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<ll, ll> m;
    ll s = 0;
    m[0] = 1;
    for(int i = 0; i < n; ++i) {
        a[i] *= ((i % 2) ? -1 : 1);
        s += a[i];
        if(m[s]) {
            cout << "YES\n";
            return;
        }
        ++m[s];
        cout << m[s] << " sum at i " << s << "\n";
    }
    cout << "NO\n";
}


//     NCR
// ll ncr(ll n, ll r){
//     double sol=1;
//     for (ll i = 1; i <= r; i++)
//     {
//         sol=sol*((n-r+i)/i);
//         // cout << n-r+i << " soludtion is " << sol << endl;
//     }
//     return (ll)sol;
// }

// dp 2d unquie paths
long long sol2(vector<vector<int>>&dp,int ro,int col){
	if((ro==0&&col==1)||(col==0&&ro==1)){return 1;}
	if(ro<0||col<0){return 0;}
	if(dp[ro][col]!=-1){return dp[ro][col];}
	long long back = sol2(dp,ro,col-1);
	long long up = sol2(dp,ro-1,col);
	return dp[ro][col]=back+up;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));
	long long res=sol2(dp,m-1,n-1);;
	
	return res;
}

int main(){
    string s;
    cin >> s;
    // int n,m;
    // cin >> n>> m;
    
    // cout << lcm(m,n) << endl;
    // vector<vector<int>> v(5,vector<int>(7,-1));
    // for(vector<int> i: v){
    //     for(int j: i){
    //     cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // int t ;
    // cin >> t;
    // while (t--)
    // {
    //     int p,q;
    //     cin >> p >> q;
    //     cout << uniquePaths(p,q) << endl;
    // }
    
    // for(int i: v){i=2;};
    // for(int i: v){cout << i << endl;};
    

    // s.push_back(char(97));
    // cout << s << endl;
    // cin >> s;
    // ll t,q,r;
    // cin >> t;
    // cin >> q;

    // string s,tem;
    // cin >> s;
    // cout << tem << endl;
    
    // vll v(t);
    // mll m;

    


        // random element of map
        // for (int i = 0; i < t; i++)
        // {
        //     cin >> q >> r;
        //     m[q]=r;
        // }
        // int che1,che2;
        // cin >> che1;
        // for (int i = 0; i < che1; i++)
        // {   
        //     cin >> che2;
        //     cout << m[che2] << endl;
        // }
        


        // // adding no to string
        // s[2]=s[2]+5;
        // cout << s << endl;


        // // IMPOR --->> prefix sum
        // prefix_sum();



        // ll a=0, b=2;
        // swap(a,b);
        // // for (int i = 0; i < 100; i++)
        // // {
        //     cout << a << b << endl;
        // // }

        // (iterator ++ )and (-- iterator)
        // for (int i = 0; i < t; i++)
        // {
        //     cin >> v[i];
        //     m[v[i]]++;
        // }
        
        // for (auto i = m.begin(); i !=m.end(); i++)
        // {
        //     cout << "previous is " << (--i)->first << " next is " << (i)-> first << endl;
        // }
        
        // cout << ncr(t,q) << endl;
    return 0;
}