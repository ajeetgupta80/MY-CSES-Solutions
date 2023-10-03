#include<iostream>
#include <bits/stdc++.h>
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


int st;
int ed;


bool is_Cycle(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &path){
    vis[node] = 1;
    path[node] = parent;

    for(auto &it:adj[node]){
        if(!vis[it]){
        
            if(is_Cycle(it,node, adj , vis, path)) return true;
        }else if(parent!=it){
            st=it;
            ed=node; 
            return true;
        }
    }

    return false;
}


bool is_valid(int n, vector<int> &vis, vector<int> &path, vector<int> adj[]){

    for(int i=1; i<n; i++){
        if(!vis[i]){
            if(is_Cycle(i, -1, adj, vis, path)) return true;
        }
    }
    return false;
}



int main(){
    init_code();
    fast_code();

    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i =0; i<m; ++i){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n+1, 0);
    vector<int> path(n+1);

    if(!is_valid(n, vis, path , adj)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    vector<int> ans;
    ans.push_back(ed);
    int temp = ed;

    while(temp!=st){
        ans.push_back(path[temp]);
        temp = path[temp];
    }
    ans.push_back(ed);
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<< it << " ";
    }
    cout<<endl;
    
   
    


}