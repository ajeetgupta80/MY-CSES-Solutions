#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long



void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin); 
    freopen("output_1.txt", "w", stdout);
    #endif 
}

void fast_code(){
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
}
 
const int N = 1e5+7;
vector<vector<int>> adj[N]; 




signed main(){
    init_code();
    fast_code();
    int n, m;
    cin >> n >>m;
    for(int i = 0; i<m; ++i){
        int x,y,wt;
        cin >> x >> y >> wt;
        adj[x].push_back({wt,y});
    }

   priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
   vector<int> dist(n+1, 1e18);
   dist[1] = 0;
   pq.push({0, 1});
   while(!pq.empty()){
     
    int w = pq.top().first;
    int node = pq.top().second;
    pq.pop();
     
    if(dist[node]<w){
        continue;
    }
    for(auto &it:adj[node]){
        int wet = it[0];
        int nod = it[1];
        if(w+wet<dist[nod]){
            dist[nod] = w+wet;
            pq.push({dist[nod],nod});
        }
    }


   }


  for(int i =1; i<dist.size(); ++i){
    cout<<dist[i]<<" ";
  }
  cout<<endl;
}