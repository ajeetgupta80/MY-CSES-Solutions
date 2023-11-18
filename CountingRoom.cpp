#include<iostream>
#include <bits/stdc++.h>
using namespace std;



void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    #endif 
    
}


void dfs(int i,int j, vector<vector<int>> &vis, vector<vector<char>> &grid, int dr[], int dx[], int n, int m){
    vis[i][j] = 1;

    for(int k=0; k<4; ++k){
        int nrow = i+dr[k];
        int ncol = j+dx[k];
      if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
        if(!vis[nrow][ncol] && grid[nrow][ncol] == '.'){
            dfs(nrow, ncol , vis, grid, dr , dx, n,m);
        }
    }
}



}




int main(){
	init_code();
    int n, m;
    cin >>n >> m;
	vector<vector<char>> grid(n);
    for(int i =0; i<n; ++i){
        for(int j = 0; j<m; ++j){
             char x;
             cin >> x;
             grid[i].push_back(x);
        }
    }

    
    int dr[] = {-1, 0, 1, 0};
    int dx[] = {0, 1 ,0 ,-1};
    int count = 0;
    vector<vector<int>> vis(n, vector<int> (m , 0));
    for(int i =0; i<n; ++i){
        for(int j=0; j<m; ++j){

            if(vis[i][j]==0 && grid[i][j] =='A'){
                count++;
                dfs(i, j , vis, grid, dr, dx, n, m);

            }
        }
    }
    cout<<count<<endl; 
    
}
