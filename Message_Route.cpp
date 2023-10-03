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



int main(){
    init_code();
    fast_code();

    int n,m;
    cin >>n >> m;
    vector<int> adj[n+1];
    for(int i=1; i<=m; ++i){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

     vector<int> vis(n+1, 0);
     vector<int> parent(n+1, -1);
     queue<int> q;
     q.push(1);
     vis[1] =1;

     while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(node == n){
            break;
        }

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                parent[it]= node;

            }
        }

     }

     if(parent[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
     }

    

     stack<int> st; 
     int current_node = n;
     while(current_node!=-1){
        st.push(current_node);
        current_node = parent[current_node];
     }
     
     cout<<st.size()<<endl; 
     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
     }







}