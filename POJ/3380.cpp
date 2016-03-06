#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int maxn = 10000+10;
#define REP(_,a,b) for(int _ = (a); _ <= (b); _++)

struct edge{
    int u,v,nxt,id;
    LL w;
};
int nume,head[maxn];
edge E[maxn*2];
vector<edge> ve;
int n,k,sh,sc;
bool cmp(edge a,edge b) {
    return a.w < b.w;
}
void init() {
    memset(head,0,sizeof head);
    nume = 1;
    ve.clear();
}
void addedge(int u,int v,LL w,int id) {
    E[++nume].nxt = head[u];
    E[nume].u = u;
    E[nume].v = v;
    E[nume].w = w;
    E[nume].id = id;
    head[u] = nume;
}
void input() {
    for(int i = 0; i < n-1; i++) {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        addedge(u,v,l,i+1);
        addedge(v,u,l,i+1);
    }
}
int dfs(int u,int fa) {
    int ret = 1;
    for(int i = head[u]; i; i = E[i].nxt) {
        if(E[i].v != fa) {
            int tmp = dfs(E[i].v,E[i].u);
            if(tmp) {
                E[i].w *= LL(tmp)*(n-tmp)*(sh-sc);
                //cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<" "<<E[i].id<<endl;
                ve.push_back(E[i]);
            }
            ret += tmp;
        }
    }
    return ret;
}
void solve() {
    dfs(1,-1);
    sort(ve.begin(),ve.end(),cmp);
    printf("%d",ve[0].id);
    for(int i = 1; i < k; i++) {
        printf(" %d",ve[i].id);
    }
    puts("");
}
int main(){

    while(~scanf("%d%d%d%d",&n,&k,&sh,&sc)) {
        init();
        input();
        solve();
    }
    return 0;
}
