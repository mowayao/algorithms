#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,root,u,v;
const int maxn = 10000+10;
vector<int> g[maxn];
int depth[maxn],father[maxn];
void init(){
	root = n;
	for(int i = 0; i <= n; i++){  
	   g[i].clear();
	   father[i] = -1;
    }
}
void dfs(int p,int dep){
	depth[p] = dep;
	//father[p] = v;
	for(int i = 0; i < g[p].size(); i++){
		dfs(g[p][i],dep+1);
	}
}
int lca(int u,int v){
	dfs(root,1);
	while(depth[u] > depth[v]) u = father[u];
	while(depth[v] > depth[u]) v = father[v];
	
	while(u!=v){
		u = father[u];
		v = father[v];
	}
	return u;
	
}
int main(){
	
	int ncase;
	cin >>ncase;
	while(ncase--){
		scanf("%d",&n);
		init();
		for(int i = 1; i <= n-1; i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			father[b] = a;
		}
		while(father[root]!=-1){
			root = father[root];
		}
		scanf("%d%d",&u,&v);
		cout<<lca(u,v)<<endl;	
		
	} 
	
	return 0;
}