#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;
#define int int64_t

const int N=2*1e5+10;
vector<int> g[N];
int depth[N];

void dfs(int curr,int parent=-1){
  
  for(auto child:g[curr]){
    
    if(child==parent)continue;
    
    depth[child]=1+depth[curr];
    
    dfs(child,curr);
  }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int mod=998244353;
    
    int n;
    cin>>n;
    if(n==1){
      cout<<0;
    }
    else{
          for(int i=0;i<n;i++){
      
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    memset(depth,0,sizeof depth);
    
    dfs(1);
    
    int maxDepth=-1;
    int node=-1;
    
    for(int i=1;i<=n;i++){
      
      if(maxDepth<depth[i]){
        maxDepth=depth[i];
        node=i;
      }
      depth[i]=0;
      
    }
    
    dfs(node);
    
    int diameter=0;
    
    for(int i=1;i<=n;i++)
    {
      
      diameter=max(diameter,depth[i]);
      
    }
    cout<<diameter;
    }

   	return 0;
}