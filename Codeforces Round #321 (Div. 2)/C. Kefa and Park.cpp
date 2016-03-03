#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100000+10;
int n,m,a[maxn];
vector<int> g[maxn];
int DFS(int u,int fa,int cnt) {
	if(g[u].size() == 1 && u != 1 && cnt <= m) {
		return 1;
	}
	int s = 0;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v != fa) {
			if(a[v] && cnt < m){
				s += DFS(v,u,cnt+1);
			}
			else if(!a[v]) {
				s += DFS(v,u,0);
			}
		}
	}
	return s;

}
int main() {

	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for(int i = 1; i < n; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<DFS(1,-1,a[1])<<endl;
	return 0;
}
