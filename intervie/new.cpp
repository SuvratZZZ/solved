#include<bits/stdc++.h>
using namespace std;

void coustom_swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

vector<vector<string>> group(vector <string> &a){
    vector<vector<string>> res;
    map<vector<int>,vector<string>> mp;
    for(int i=0;i<a.size();i++){
        vector<int> count(26,0) ;
        for(auto &i:a[i]){
            count[i-'a']++;
        }
        mp[count].push_back(a[i]);
    }

    for(auto &i:mp){
        res.push_back(i.second);
    }
    return res;

}

int main(){
    vector<string> a= {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = group(a);

    for (int  i = 0; i < res.size() ; i++)
    {
        for (int  j  = 0; j  < res[i].size() ; j ++)
        {
            cout << res[i][j] << " , " ;
        }
        cout << endl; 
    }
    
    return 0;
}