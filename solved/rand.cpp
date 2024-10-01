// #include<bits/stdc++.h>
// using namespace std;

// void dfs(vector<vector<int>> &gra, vector<int> &vis , int ind){
// 	vis[ind]=1;
// 	for(auto i:gra[ind]){
// 		if(vis[i]==-1){
// 			dfs(gra,vis,i);
// 		}
// 	}
// }
// int main(){
// 	int n,e;
// 	cin>>n>>e;
// 	vector<vector<int>> gra(n+1);
// 	vector<int> vis(n+1,-1);
// 	for(int i=0;i<e;i++){
// 		int a,b;
// 		cin>>a>>b;
// 		gra[a].push_back(b);
// 		gra[b].push_back(a);
// 	}
// 	int cou=0;
// 	for(int i=1;i<=n;i++){
//         // cout << i << " i ans vis " << vis[i] << endl;
// 		if(vis[i]==-1){
//             dfs(gra,vis,i);
// 		    cou++;
//         }
// 	}
// 	cout << cou << endl;
// }
