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
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
}






signed main(){
	init_code();
     fast_code();


    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row);
    for(int i =0; i<row; ++i){
        for(int j = 0; j<col; ++j){
            char x;
            cin >>x;
            grid[i].push_back(x);
        }
    }
  


    int startRow; int startCol;
    for(int i=0; i<row; ++i){
        for(int j =0; j<col; ++j){
        if(grid[i][j]== 'A')
        {
            startRow = i; 
            startCol = j; 
        } 

    } 
}


    vector<vector<int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<char> direc = {'R','L','D','U'};
    vector<vector<int>> prev(row, vector<int> (col , -1));
    prev[startRow][startCol] = -2;


    // DFS
    queue<pair<int,int>> q;
    q.push({startRow, startCol});
    int rows;
    int cols;
    while(!q.empty()){
      rows = q.front().first;
      cols = q.front().second;
      q.pop();
      if(grid[rows][cols]=='B'){
        break;
      }
      for(int i =0; i<4; ++i){
        int nrow = rows + dir[i][0];
        int ncol = cols + dir[i][1];

        if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && grid[nrow][ncol]!='#' && prev[nrow][ncol]==-1){

            prev[nrow][ncol] = i;
            q.push({nrow, ncol});
        }

        
      }


    }

    if(grid[rows][cols]!='B'){
        cout<<"NO"<<endl;
    }
    cout<<"YES"<<endl;
    string path;
    while(prev[rows][cols]!=-2){
        int ls = prev[rows][cols];
        path.push_back(direc[ls]);
        rows -= dir[ls][0];
        cols -= dir[ls][1];
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl; 
    for(int i =0; i<path.size(); ++i){
        cout<<path[i];
    }
    cout<<endl;




}




