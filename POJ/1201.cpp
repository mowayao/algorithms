#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
const int maxn = 50000+10000;
const int INF = 1e9;
int n;
int src,sink;
bool inQue[maxn];
int dist[maxn];
queue<int>que;
struct edge{
    int to,next,w;
    edge(int to,int next,int w):to(to),next(next),w(w){}
};
int head[maxn];
vector<edge> e;

void addedge(int from,int to,int w){
    e.push_back(edge(to,head[from],w));
    head[from] = e.size()-1;
}
void spfa(){
    for(int i = src; i <= sink; i++){
        inQue[i] = 0;
        dist[i] = INF;
    }
    inQue[sink] = 1;
    que.push(sink);
    dist[sink] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        inQue[u] = 0;
        for(int i = head[u]; i != -1; i = e[i].next){
            if(dist[e[i].to] > dist[u]+e[i].w){
                dist[e[i].to] = dist[u]+e[i].w;
                if(!inQue[e[i].to]){
                    inQue[e[i].to] = 1;
                    que.push(e[i].to);
                }
            }
        }
    }

}
int main(){

    int m;
    //freopen("in","r",stdin);
    while(~scanf("%d",&m)){
        e.clear();
        src = maxn,sink = -1;
        memset(head,-1,sizeof head);
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ++b;
            src = min(src,a);
            sink = max(sink,b);
            addedge(b,a,-c);
        }
        for(int i = src; i < sink; i++){
            addedge(i+1,i,0);
            addedge(i,i+1,1);
        }
        spfa();
        cout<<-dist[src]<<endl;

    }
    return 0;
}
