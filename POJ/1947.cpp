#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 150+10;
const int INF = 1e8;
int dp[maxn][maxn];
int n,p;
int fa[maxn];
vector<int> g[maxn];
int rt;

void dfs(int rt,int p){
    for(int i = 0; i <= p; i++)
        dp[rt][i] = INF;
    dp[rt][1] = 0;
    for(int i = 0; i < g[rt].size(); i++){
        int son = g[rt][i];
        dfs(son,p);
        for(int k = p; k >= 0; k--){
            int  ans = INF;
            if(dp[rt][k] != INF)
                ans = dp[rt][k] + 1;
            for(int v = 0; v <= k; v++){
                if(dp[son][k-v]!=INF&&dp[rt][v]!=INF)
                    ans = min(dp[son][k-v]+dp[rt][v],ans);
            }
            dp[rt][k] = ans;
        }
    }
}

int main(){

    while(~scanf("%d%d",&n,&p)){
        int a,b;
        memset(fa,-1,sizeof fa);
        for(int i = 0; i <= n; i++) g[i].clear();
        for(int i = 0; i < n-1; i++){
            scanf("%d%d",&a,&b);
            fa[b] = a;
            g[a].push_back(b);
        }
        for(int i = 1; i <= n; i++){
            if(fa[i] == -1){
                rt = i;
                break;
            }
        }
        dfs(rt,p);
        int ans = dp[rt][p];
        for(int i = 1; i <= n;i++){
            if(i!=rt){
                ans = min(ans,dp[i][p]+1);
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
