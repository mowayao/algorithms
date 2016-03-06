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
const int maxe = 6000+10;
struct edge{
    int v,nxt;
}e[maxe];
int head[maxn];
int n,m;
stack<int> S;
queue<int> que;
int in[maxn],out[maxn];
int dfn[maxn],lown[maxn],sccno[maxn];
int dfs_clk,scc_cnt,nume;
void init(){
    dfs_clk = 0;
    scc_cnt = 0;
    nume = 1;
    while(!S.empty()) S.pop();
    while(!que.empty()) que.pop();
    memset(sccno,0,sizeof sccno);
    memset(dfn,0,sizeof dfn);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(head,0,sizeof head);
}
void addedge(int u,int v){
    e[++nume].nxt = head[u];
    e[nume].v = v;
    head[u] = nume;
}
void Tarjan(int u){
    dfn[u] = lown[u] = ++dfs_clk;
    S.push(u);
    for(int i = head[u]; i ; i = e[i].nxt){
        int v = e[i].v;
        if(!dfn[v]){
            Tarjan(v);
            lown[u] = min(lown[u],lown[v]);
        }
        else if(!sccno[v]){//在栈中，能到达的祖先
            lown[u] = min(lown[u],dfn[v]);
        }
    }
    if(lown[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x = S.top();S.pop();
            sccno[x] = scc_cnt;
            if(x==u) break;
        }
    }
}
int main(){

    int ncase;
    cin >> ncase;
    while(ncase--){
        init();
        scanf("%d%d",&n,&m);
        int a,b;
        for(int i = 0; i < m; i++){
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        for(int i = 1; i <= n;i++){
            if(!dfn[i])
                Tarjan(i);
        }
        for(int i = 1; i <= n; i++){
            int k = sccno[i];
            for(int j = head[i]; j; j = e[j].nxt){
                int d = sccno[e[j].v];
                if(k!=d){
                    in[d]++;
                    out[k]++;
                }
            }
        }
        int tr = 0,ts = 0;
        bool flag = true;
        for(int i = 1; i <= scc_cnt; i++){
            if(in[i]==0){
               tr++;
               if(out[i]>1){
                    flag = false;
                    break;
               }
            }
            if(out[i]==0){
                ts++;
            }
        }
        if(flag&&tr==1&&ts==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
/*
3
8 10
1 5
6 3
2 7
7 8
3 6
8 2
2 1
4 6
7 3
6 5

5 8
1 2
2 3
3 4
1 3
1 4
2 4
4 5
5 4

6 10
6 3
2 5
4 6
3 6
2 6
6 1
1 5
3 2
4 1
5 3
*/
