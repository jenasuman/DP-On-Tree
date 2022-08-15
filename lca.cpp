#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;
#define int int64_t

const int N=2*1e5+10;
vector<int> g[N];
int parent[N];

void dfs(int v,int p=-1){
  parent[v]=p;
  for(auto c:g[v]){
    if(c==p)continue;
    dfs(c,v);
  }
}

vector<int> pathArray(int v){
  
     vector<int> path;
     
     while(v!=-1){
       
       path.push_back(v);
       v=parent[v];
      }
  
     reverse(begin(path),end(path));
     return path;
  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int mod=998244353;
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int> path_x=pathArray(x);
    vector<int> path_y=pathArray(y);
    
    int m=min(path_y.size(),path_x.size());
    
    int lca=-1;
    
    for(int i=0;i<m;i++){
      
      if(path_x[i]==path_y[i])lca=path_y[i];
      else break;
      
      
    }
    
    cout<<lca<<"\n";
   	return 0;
}