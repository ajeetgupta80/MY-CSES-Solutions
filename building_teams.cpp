#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//  check for bipartite graph if any component is not bipartite then its IMPOSSIBLE



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

bool is_bipartite(int node , vector<int> &color, vector<int> adj[]){

    color[node] = 0;
    queue<int> q;
    q.push(node);


    while(!q.empty()){

        int nod = q.front();
        q.pop();


        for(auto it:adj[nod]){
        if(color[it]==-1){
          color[it] = !color[nod];
          q.push(it);

        }else if(color[it] == color[nod]){
            return false;
        }
    }
  }
    return true;
    
}
  
  


int main(){
    init_code();
    fast_code();
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i =1; i<=m; ++i){
        int x,y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    vector<int> color(n+1, -1);
    int flag = 0;
    for(int i =1; i<=n; ++i){
        if(color[i]==-1){
            if(is_bipartite(i, color, adj)==false)
               {
                flag = 1;
                break;
               }
        }
    }

    if(flag == 1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{

   
   for(int i=1; i<=n; ++i){
    cout<<color[i]+1<<" ";
   }
   cout<<endl;
}


       

}






