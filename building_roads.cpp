#include<iostream>
#include<bits/stdc++.h>
using namespace std;




void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    #endif 
}

void fast_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



// first count the no of connected component(p) then answer is p-1

void dfs(int node, vector<int> adj[], vector<int> &vis ){
    vis[node] =1;

    for(auto it:adj[node]){
        if(vis[it] == 0){
            dfs(it, adj , vis);
        }
    }
}


int main(){
 init_code();
 fast_code();

 int n,m;
 cin >> n >> m;
 vector<int> adj[n+1];
 for(int i =1; i<=m; ++i)
 {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
 }

 vector<int> vis(n+1,0);

 vector<int> roads;
 int count = 0;
 int ind =-1;
 int flag = 0;
  for(int i =1 ; i<=n; ++i){
    if(vis[i]==0){
        dfs(i, adj, vis);
        roads.push_back(i);
    }
  }


  cout<<roads.size()-1<<endl;

  for(int i =1; i<roads.size(); ++i){
    cout<<roads[i-1]<<" "<<roads[i]<<endl;
  }
  cout<<endl;


}


