#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1000+10;
vector<int> G[maxn];
int n,m;
int dfn[maxn],lown[maxn];
int du[maxn];
int dfs_clk;

void init(){
    for(int i = 0; i <= n; i++){
        G[i].clear();
    }
    dfs_clk = 0;
    memset(dfn,0,sizeof dfn);
    memset(du,0,sizeof du);
}
int dfs(int u,int fa){
    int lowu = dfn[u] = dfs_clk++;
    for(int i = 0; i < G[u].size(); i++){
        int d = G[u][i];
        if(!dfn[d]){
            int lowv = dfs(d,u);
            lowu = min(lowu,lowv);
        }
        else if(dfn[d] < dfn[u] && d != fa){
            lowu = min(lowu,dfn[d]);
        }
    }
    lown[u] = lowu;
    return lowu;
}
int main(){

    while(~scanf("%d%d",&n,&m)){
        init();
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1,-1);

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < G[i].size(); j++){
                int k = G[i][j];
                if(lown[i] != lown[k]){
                    du[lown[i]]++;
                }
            }
        }
        int block = 0;
        for(int i = 0; i < dfs_clk; i++){
            if(du[i]==1) ++block;
        }
        printf("%d\n",(block+1)/2);

    }
    return 0;
}
