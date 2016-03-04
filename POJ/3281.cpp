#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100+10;
const int inf = 1<<25;
struct edge{
    int v,nxt,f;
}e[maxn*maxn*10];
int head[maxn*10],nume;

void addedge(int u,int v,int c){
    e[++nume].nxt = head[u];
    e[nume].v = v;
    e[nume].f = c;
    head[u] = nume;
    e[++nume].nxt = head[v];
    e[nume].v = u;
    e[nume].f = 0;
    head[v] = nume;
}
bool vis[maxn*10];
int dist[maxn*10];
int src,sink;
queue<int> que;
void bfs(){
    memset(vis,false,sizeof vis);
    while(!que.empty()) que.pop();
    vis[src] = true;
    que.push(src);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = head[u]; i ; i = e[i].nxt){
            int v = e[i].v,f = e[i].f;
            if(f && !vis[v]){
                que.push(v);
                vis[v] = true;
                dist[v] = dist[u]+1;
            }
        }
    }
}
int dfs(int u,int delta){
    if(u == sink) return delta;
    else{
        int ret = 0;
        for(int i = head[u]; i && delta; i = e[i].nxt){
            int v = e[i].v;
            if(e[i].f && dist[v] == dist[u]+1){
                int dd = dfs(v,min(delta,e[i].f));
                e[i].f -= dd;
                e[i^1].f += dd;
                delta -= dd;
                ret += dd;
            }
        }
        return ret;
    }
}
int maxFlow(){
    int ret = 0;
    while(true){
        bfs();
        if(!vis[sink]) break;
        ret += dfs(src,inf);
    }
    return ret;
}
int n,f,d;
void init(){
    memset(head,0,sizeof head);
    nume = 1;
    src = 0;
    sink = f+2*n+d+1;
}

int main(){

    while(~scanf("%d%d%d",&n,&f,&d)){
        int a,b,c;
        init();
        for(int i = 1; i <= f; i++){
            addedge(src,i,1);
        }
        for(int i = 1; i <= d; i++){
            addedge(i+2*n+f,sink,1);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&a,&b);
            while(a--){
                scanf("%d",&c);
                addedge(c,f+i,1);
            }
            while(b--){
                scanf("%d",&c);
                addedge(f+n+i,2*n+f+c,1);
            }
            addedge(f+i,f+n+i,1);
        }
        //cout<<sink<<endl;
        cout<<maxFlow()<<endl;
    }


    return 0;
}
