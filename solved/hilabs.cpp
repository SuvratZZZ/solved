#include <bits/stdc++.h>
using namespace std;


vector<int> tin;
vector<int> low;
int tim;
vector<vector<int>> res;
void dfs(int ind,int pr,vector<vector<int>>&gra,vector<int>& vis){
    vis[ind]=1;
    tin[ind]=tim;
    tim++;
    for(auto i:gra[ind]){
        if(i==pr)continue;
        if(vis[i]==-1){
            dfs(i,ind,gra,vis);
            low[ind]=min(low[i],low[ind]);
        }
        else{
            // low[ind]=min(low[i],low[ind]);
            low[ind]=min(tin[i],low[ind]);
        }
    }
    if(pr!=-1&&low[ind]>tin[pr]){
        if(pr<ind)
        res.push_back({pr,ind});
        else
        res.push_back({ind,pr});
    }
    return;
}
    vector<vector<int>> cri(int v, vector<vector<int>>& ed) {
        vector<int> vis(v,-1);
        vector<vector<int>> gra(v);
        for(auto i:ed){
        gra[i[0]].push_back(i[1]);
        gra[i[1]].push_back(i[0]);
        }
        tin.clear();
        low.clear();
        tin.resize(v,0);
        low.resize(v,INT_MAX);
        res.clear();
        tim=1;
        dfs(0,-1,gra,vis);
        return res;
    }

class dsu{
    public:
    vector<int> pr;
    vector<int> siz;
    
    dsu(int n){
        pr.resize(n+1);
        for(int i=0;i<=n;i++){
            pr[i]=i;
        }
        siz.resize(n+1,1);
    }
    
    int fpr(int ind){
        if(pr[ind]==ind)return ind;
        return pr[ind]=fpr(pr[ind]);
    }
    
    int fsz(int ind){
        return siz[fpr(ind)];
    }
    void ubs(int v,int u){
        if(fpr(u)==fpr(v))return ;
        
        if(fsz(u)>fsz(v)){
            siz[fpr(u)]+=fsz(v);
            pr[fpr(v)]=fpr(u);
        }
        else{
            siz[fpr(v)]+=fsz(u);
            pr[fpr(u)]=fpr(v);
        }
    }
};
int main() {
	
    int n,e;
    cin>>n>>e;
    vector<vector<int>> ed;
    vector<vector<int>> br;
    for(int i=0;i<e;i++){
        int u,v;cin>>u>>v;u--;v--;
        ed.push_back({u,v});
    }
    
    dsu dd(n);
    
    br=cri(n,ed);
    
    auto comp=[](const vector<int>&a,const vector<int>&b)->bool{
        if(a[0]<=b[0])return true;
        else return false;
    };
    sort(br.begin(),br.end(),comp);
    // sort(br.begin(),br.end());
    
    for(auto i:ed){
        vector<int> tem;
        vector<int> t2;
        if(i[0]<i[1])
            tem={i[0],i[1]};
        else
            tem={i[1],i[0]};
            
        if(lower_bound(br.begin(),br.end(),tem)!=br.end())
            t2=*lower_bound(br.begin(),br.end(),tem);
        if(t2==tem){
            continue;
        }
        else{
            cout << i[1] << " union done " << i[0] << endl;
            dd.ubs(i[0],i[1]);
            cout << i[0] << " -> " << i[1] << " sizes : " << dd.fsz(i[0]) << " and " << dd.fsz(i[1]) << endl;  
        }
    }
    int sum =0;
    for(auto i:br){
        cout << i[0] << " -> " << i[1] << " sizes : " << dd.fsz(i[0]) << " and " << dd.fsz(i[1]) << endl;  
        sum+=dd.fsz(i[0])*dd.fsz(i[1]);
    }
    
    cout << sum << endl;
}
