#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1100*4;
struct ee{
    int u,v;
}ee[maxn*10];
struct edge{
    int v,nxt;
}e[maxn*maxn];
int dfs_clk,scc_cnt;
int sccno[maxn];
int lown[maxn],dfn[maxn];
int head[maxn];
stack<int> S;
int nume;
int n,m;
void init(){
    nume = 1;
    memset(dfn,0,sizeof dfn);
    memset(sccno,0,sizeof sccno);
    scc_cnt = dfs_clk = 0;
    memset(head,0,sizeof head);
    while(!S.empty()) S.pop();
}
void addedge(int u,int v){
    e[++nume].nxt = head[u];
    e[nume].v = v;
    head[u] = nume;
}
void Tarjan(int u){
    S.push(u);
    lown[u] = dfn[u] = ++dfs_clk;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].v;
        if(!dfn[v]){
            Tarjan(v);
            lown[u] = min(lown[u],lown[v]);
        }
        else if(!sccno[v]){
            lown[u] = min(lown[u],dfn[v]);
        }
    }
    if(lown[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}
bool can(int x){
    init();
    for(int i = 0; i < n; i++){
        addedge(ee[i].v,ee[i].u+2*n);
        addedge(ee[i].u,ee[i].v+2*n);
    }
    for(int i = 0; i < x; i++){
        addedge(ee[i+n].u+2*n,ee[i+n].v);
        addedge(ee[i+n].v+2*n,ee[i+n].u);
    }
    for(int i = 0; i < 4*n; i++){
        if(!dfn[i])
            Tarjan(i);
    }
    for(int i = 0; i < 2*n; i++){
        if(sccno[i]==sccno[i+2*n]) return false;
    }
    return true;
}
int binary_search(int L,int R){
    while(L <= R){
        int mid = (L+R)>>1;
        if(can(mid)){
            L = mid+1;
        }else{
            R = mid-1;
        }
    }
    return R;
}
int main(){

    while(~scanf("%d%d",&n,&m) && n+m){
        for(int i = 0; i < n; i++)
            scanf("%d%d",&ee[i].u,&ee[i].v);

        for(int i = 0; i < m; i++)
            scanf("%d%d",&ee[i+n].u,&ee[i+n].v);
        int d = binary_search(0,m);
        printf("%d\n",d);
    }
    return 0;
}
