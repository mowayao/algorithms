#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000+10;
const int INF = 1e9;
vector<pair<int,int> > g[maxn];
int dist[maxn];
int cnt[maxn];
queue<int>que;
bool inQue[maxn];
int src = 1;
int n,ml,md;
bool spfa(){
    memset(inQue,0,sizeof inQue);
    memset(cnt,0,sizeof cnt);
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[src]= 0;
    que.push(src);
    inQue[src] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 0; i < g[u].size(); i++){
            if(dist[g[u][i].first]>g[u][i].second+dist[u]){
                dist[g[u][i].first] = g[u][i].second+dist[u];
                if(!inQue[g[u][i].first]){
                    cnt[g[u][i].first]++;
                    if(cnt[g[u][i].first] > n)
                        return false;
                    inQue[g[u][i].first] = 1;
                    que.push(g[u][i].first);
                }
            }
        }
        inQue[u] = 0;
    }
    return true;
}
int main(){


    while(cin >> n >> ml >> md){
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        int a,b,d;
        while(ml--){
            scanf("%d%d%d",&a,&b,&d);
            g[a].push_back(make_pair(b,d));
        }
        while(md--){
            scanf("%d%d%d",&a,&b,&d);
            g[b].push_back(make_pair(a,-d));
        }
        if(!spfa()) cout<<-1<<endl;
        else{
            if(dist[n]==INF){
                cout<<-2<<endl;
            }else{
                cout<<dist[n]<<endl;
            }

        }
    }

    return 0;
}
