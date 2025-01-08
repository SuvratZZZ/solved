#include <bits/stdc++.h>
using namespace std;
# define ll long long


#ifndef ONLINE_JUDGE
#include <chrono>
#endif
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


# define pb push_back
# define fl(i,n) for(ll i=0; i< n ;i++)
# define flab(i,a,b) for(ll i=a;i<b;i++)
# define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
# define rfall(f) reverse(f.begin(),f.end());for(auto i:f){cout << i << " ";}cout << endl
# define fall(f) for(auto i:f){cout << i << " ";}cout << endl
# define ftd(f) for(auto i:f){for(auto j:i){cout << j << " ";}cout << endl;}


typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vin;
typedef vector<vin> vvi;
typedef map<ll,ll> mll;


const ll N = 2000;
const ll INF = 1000000000000000000;
const ll M = 998244353;
const ll mod = 1e9+7;
const int LLL = 1e6+5;

//ll JUD = 0;
//
//#ifdef ONLINE_JUDGE
//# define JUD 0
//#else
//# define JUD 1
//#endif


int sml_fctr[LLL];
void fill_factor(){
    for(int i=0;i<=LLL;i++){
        sml_fctr[i]=i;
    }
    for(int i=2;i*i<=LLL;i++){
        for(int j=i*i;j<=LLL;j=j+i){
            if(sml_fctr[j]==j){
                sml_fctr[j]=i;
            }
        }
    }
}
vector<int> fin_factor(int n){
    // will not have 1 as prime
    vector<int> res;
    int tt=n;
    while(tt!=1){
        res.push_back(sml_fctr[tt]);
        tt=tt/sml_fctr[tt];
    }
    return res;
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
// void solve(){
//     ll n,m,q,sa=0,sb=0;
//     cin>>n>>m>>q;
//     vector<ll> a(n),b(m);
//     for (ll  i = 0; i < n ; i++)
//     {
//         cin>>a[i];
//         sa+=a[i];
//     }
//     for (ll  i = 0; i < m ; i++)
//     {
//         cin>>b[i];
//         sb+=b[i];
//     }
    
// }

vector<int> graph;
vector<int> pathLength;  // Stores the longest path length to a cycle for each node
unordered_map<int, int> visited;  // States of each node (0 = unvisited, 1 = visiting, 2 = visited)

int dfs(int node, vector<int>& visited, vector<int>& pathLength) {
    // If the node is already visited, it means we've already processed this node, return its path length
    if (visited[node] == 2) return pathLength[node];
    
    // If the node is in the current recursion stack, we have found a cycle
    if (visited[node] == 1) {
        return 0;  // Cycle detected, the length to cycle is 0
    }
    
    // Mark the node as being visited in the current path
    visited[node] = 1;
    
    // Recursive DFS call to find the longest path from the next node
    int nextNode = graph[node];
    int cyclePathLength = dfs(nextNode, visited, pathLength);
    
    // After returning from DFS, mark the node as fully visited
    visited[node] = 2;
    
    // If we are on the way to the cycle, the path length to cycle is calculated as 1 + length of path from nextNode
    pathLength[node] = 1 + cyclePathLength;
    
    return pathLength[node];
}

void solve() {
    int n;
    cin >> n;
    
    graph.resize(n);
    pathLength.resize(n, -1);  // -1 means unvisited node
    
    // Reading graph input
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        graph[i]--;  // Convert to 0-indexed
    }
    
    vector<int> visited(n, 0);  // Track the state of each node: 0 = unvisited, 1 = visiting, 2 = visited
    int longestPath = 0;
    
    // Try to find the longest path to a cycle for all nodes
    for (int i = 0; i < n; i++) {
        if (pathLength[i] == -1) {
            // If this node hasn't been processed yet
            longestPath = max(longestPath, dfs(i, visited, pathLength));
        }
    }
    
    cout << longestPath << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        auto start = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //AND RE;
   //fill_factor();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    #endif
    return 0;
}