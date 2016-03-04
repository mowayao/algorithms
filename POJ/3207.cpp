#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1000+10;
struct ee{
    int u,v;
}ee[maxn];

struct edge{
    int v,nxt;
}e[maxn*maxn];
int n,m;
int head[maxn];
int nume;
int lown[maxn],dfn[maxn];
int dfs_clk;
stack<int> S;
int scc_cnt;
int sccno[maxn];

void init(){
    memset(head,0,sizeof head);
    memset(dfn,0,sizeof dfn);
    memset(sccno,0,sizeof sccno);
    nume = 1;
    dfs_clk = scc_cnt = 0;
    while(!S.empty()) S.pop();
}

void addedge(int u,int v){
    e[++nume].nxt = head[u];
    e[nume].v = v;
    head[u] = nume;
}

void Tarjan(int u){
    lown[u] = dfn[u] = ++dfs_clk;
    S.push(u);
    for(int i = head[u]; i ; i = e[i].nxt){
        int v = e[i].v;
        if(!dfn[v]){
            Tarjan(v);
            lown[u] = min(lown[u],lown[v]);
        }else if (!sccno[v]){
            lown[u] = min(lown[u],dfn[v]);
        }
    }
    if(lown[u] == dfn[u]){
        scc_cnt++;
        while(true){
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if(x==u) break;
        }
    }
}
inline bool touch(int i,int j){
    return  (ee[i].u < ee[j].u && ee[i].v > ee[j].u && ee[j].v > ee[i].v) || (ee[j].u < ee[i].u && ee[j].v > ee[i].u && ee[i].v > ee[j].v);
}
int main(){

    while(~scanf("%d%d",&n,&m)){
        init();
        int a,b;
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&ee[i].u,&ee[i].v);
            if(ee[i].u > ee[i].v) swap(ee[i].u,ee[i].v);
        }
        for(int i = 1; i <= m; i++){
            for(int j = i+1; j <= m; j++){
                if(touch(i,j)){
                    addedge(i,j+m);
                    addedge(j+m,i);
                    addedge(i+m,j);
                    addedge(j,i+m);
                }
            }
        }
        for(int i = 1; i <= 2*m; i++){
            if(dfn[i]==0)
                Tarjan(i);
        }
        bool flag = true;
        for(int i = 1; i <= m; i++){
            if(sccno[i] == sccno[i+m]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("panda is telling the truth...\n");
        }else{
            printf("the evil panda is lying again\n");
        }
    }
    return 0;
}
