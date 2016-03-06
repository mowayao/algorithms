#include <cstdio> 
#include <cstring> 
#include <algorithm> 
  
const int N=101; 
int n; 
bool map[N][N]; 
int dep[N], low[N], f[N]; 
int root; 
bool isVisited[N]; 
  
using namespace std; 
  
void dfs(int u, int depth) 
{ 
    dep[u]=depth; 
    low[u]=depth; 
    isVisited[u]=true; 
    for(int i=1; i<=n; i++) 
    { 
        if(map[u][i])  //u的后向节点 
        { 
            if(!isVisited[i]) 
            { 
                dfs(i,depth+1); 
                low[u]=min(low[u],low[i]); 
                if(u!=1 && low[i]>=dep[u])   //non-root 
                { 
                    f[u]++; 
                } 
                else if(u==1) 
                { 
                    root++; 
                } 
            } 
            else
            { 
                low[u]=min(low[u],dep[i]); 
            } 
        } 
    } 
} 
  
int main() 
{ 
    int u,v; 
    int ans; 
  
    while(scanf("%d",&n)!=EOF && n) 
    { 
        memset(map,0,sizeof(map)); 
        memset(dep,0,(n+1)*sizeof(int)); 
        memset(low,0,(n+1)*sizeof(int)); 
        memset(f,0,(n+1)*sizeof(int)); 
        memset(isVisited,0,(n+1)*sizeof(int)); 
        root=0; 
        ans=0; 
        while(scanf("%d",&u) && u) 
        { 
            while(getchar()!='\n') 
            { 
                scanf("%d",&v); 
                map[u][v]=true; 
                map[v][u]=true; 
            } 
        } 
        dfs(1,1); 
        if(root>=2) 
        { 
            ans++; 
        } 
        for(int i=2; i<=n; i++) 
        { 
            if(f[i]>=1) 
            { 
                ans++; 
            } 
        } 
        printf("%d\n",ans); 
    } 
    return 0; 
}