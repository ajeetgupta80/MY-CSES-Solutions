#include<iostream>
#include<bits/stdc++.h>
#define int long long
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

vector<int> v(200005);
vector<int> segtree(4*200005);

void build(int ind , int start, int end){
     if(start == end){
        segtree[ind] = v[start];
        return;
    }

    int mid = (start + end )/2;

    build(2*ind, start, mid);
    build(2*ind+1 , mid+1, end);

    segtree[ind] = segtree[2*ind] + segtree[2*ind+1];
}

void update(int ind, int start, int end, int i , int val){
   if(start == end){
      segtree[ind] = val;
      return;
  }

  int mid = (start + end )/2;
  if(i<=mid){
     update(2*ind, start, mid, i, val);
  }else{
       update(2*ind+1, mid+1 , end , i , val);
  }

  segtree[ind] = segtree[2*ind]+segtree[2*ind+1];
}

int query(int ind, int start, int end , int l , int r){

     if(start>=l && end<=r){
        return segtree[ind];
    } 
    if(end<l || start>r){
        return 0;
    }

    int mid = (start+end)/2;

    int left = query(2*ind , start, mid, l ,r);
    int right = query(2*ind+1, mid+1, end , l ,r );
    return left + right;
}

signed main(){
    init_code();
    fast_code();
    int n;
    cin >> n;
    int q;
    cin >> q;
    for(int i =1; i<=n; ++i){
        cin >> v[i];
    }
    build(1, 1, n);

    while(q--){

        int type;
        cin >> type;
        if(type == 1){
            int i , val;
            cin >> i >> val;
            update(1,1 ,n , i , val);
        }else{
            int l ,r;
            cin >> l >> r;
            cout<<query(1, 1 ,n , l ,r)<<endl;
        }
    } 


}