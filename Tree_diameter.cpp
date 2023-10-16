#include <bits/stdc++.h>
using namespace std;

 

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
 

 const int N = 2*1e5+10;
 vector<int> graph[N];
 int deapth[N];

 void dfs(int node, int par = -1){

    for(auto child:graph[node]){
        if(child == par) continue;
        deapth[child] = deapth[node]+1;
        dfs(child, node);
    }
 }







int main(){
   init_code();
   fast_code();
   int n;
   cin >> n;
   for(int i=0; i<n-1; ++i){
       int x,y;
       cin>> x >> y;
       graph[x].push_back(y);
       graph[y].push_back(x);
   }
 
   dfs(1,-1);
  
   int max_deapth = -1;
   int max_deapth_node;
   for(int i=1; i<=n; ++i){
        if(deapth[i]>max_deapth){
            max_deapth = deapth[i];
            max_deapth_node = i;
        }         
        deapth[i] = 0;
   }
 



   dfs(max_deapth_node,-1);
 int dpt = -1;

   for(int i=1; i<=n; ++i){
        if(deapth[i]>dpt){
            dpt = deapth[i];
          
        }

   }
   cout<<dpt<<endl;
   



}