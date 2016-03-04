#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1000+10;
int n,k;
struct Edge{
    int nxt,to;
}edge[maxn*maxn];
int head[maxn],from[maxn];
bool visS[maxn];
bool visT[maxn];
bool S[maxn];
int cnt;

void init(){
    cnt = 0 ;
    memset(head,-1,sizeof head);
    memset(from,-1,sizeof from);
}

void addedge(int u,int v){
    ++cnt;
    edge[cnt].nxt = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
}

bool dfs(int x){
    visS[x] = 1;
    for(int i = head[x]; i != -1; i = edge[i].nxt){
        int v = edge[i].to;
        if(!visT[v]){
            visT[v] = 1;
            if(from[v]==-1||dfs(from[v])){
                from[v] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) visT[j] = 0;
        if(dfs(i)) ans++;
    }
    return ans;
}

int main(){

    while(~scanf("%d%d",&n,&k)){
            init();
            for(int i = 0; i < k; i++){
                int a,b;
                scanf("%d%d",&a,&b);
                addedge(a,b);
            }
            int ans = hungary();
            printf("%d\n",ans);
    }
    return 0;
}
