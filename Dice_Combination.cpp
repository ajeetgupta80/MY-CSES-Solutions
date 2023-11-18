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

int c;
int mod = 1e9+7;
int solve(int sum, vector<int> &dp){
     
     if(sum==0){
       c++;
     }
     if(sum<0){
     	return 0;
     }
     if(dp[sum]!=-1){
     	return dp[sum];
     }
     

    
	for(int i = 1; i<=6; ++i){
       solve(sum-i, dp)%mod;

	}
	return dp[sum] = c;

	

}


int main(){
    init_code();
    fast_code();
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    int k = solve(n, dp);
    cout<<k<<endl;

}