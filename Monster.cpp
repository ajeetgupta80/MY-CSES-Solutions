
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
 
 int n ,m;
 vector<vector<int>>g(n, vector<int> (m));
 pair<int,int> st;
 vector<pair<int,int>> monsters;

bool IsValid(int r, int c , int timer){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    if(g[r][c] <= timer)
        return false;

    return true;
}



int32_t main(){
    init_code();
    fast_code();

    cin >>n >> m;
   
    for(int i =0; i<n; ++i){
        for(int j =0; j<m; ++j){
            g[i][j] = INT_MAX;
        }
    }

    for(int i =0; i<n; ++i){
        for(int j =0; j<m; ++j){
            char c;
            cin >> c;
            if(c == '#'){
                g[i][j] = 0;
   
            }else if(c == 'M'){
                g[i][j] = 0;
                monsters.push_back({i,j});
                  
            }else if(c == 'A'){
               g[i][j] = 0;
               st={i,j};

            }else{
               g[i][j] = -1;
            }
        }
    }


    for(auto it:g){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }


  




}