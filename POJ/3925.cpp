#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double INF = 1e10;
const int maxn = 25;
vector<vector<int> > g;
double mat[maxn][maxn],NODE[maxn],ratio[maxn];
bool vis[maxn];
int n,m;
void input(){
	g.clear();
	for(int i = 1; i <= n; i++) scanf("%lf",&NODE[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%lf",&mat[i][j]);
}
void cc(vector<int> &k,int c){
	if(k.size()==m){
		g.push_back(k);
		return;
	}
	for(int i = c; i <= n; i++){
		k.push_back(i);	
		cc(k,i+1);
		k.pop_back();
	}
}
double prim(vector<int> &node){
	int v = -1;
	double mincost[maxn],ans = 0;
	for(int i = 0; i < node.size(); i++){
		mincost[node[i]] = INF;
		vis[node[i]] = 0;
	}
	mincost[node[0]] = 0;
	double res = 0;
	for(int i = 0; i < node.size(); i++){
		int v = -1;
		for(int j = 0; j < node.size(); j++)
			if(!vis[node[j]]){	
				if(v == -1) v = node[j];
				else if(mincost[node[j]]<mincost[v]) v = node[j];
			}
		if(v == -1) break;
		vis[v] = 1;
		ans+=mincost[v];
		for(int j = 0; j < node.size(); j++){
			if(fabs(mat[v][node[j]])>1e-8){
				if(!vis[node[j]]){
					int x = node[j];
					mincost[x] = min(mincost[x],mat[v][node[j]]);
				}
			}
		}
	}
	double SN = 0;
	for(int i = 0; i < node.size(); i++){
		SN += NODE[node[i]];
	}
	return ans/SN;
}
void solve(){
	vector<int> node;
	cc(node,1);
	node.clear();
	double ans = INF;
	for(int i = 0; i < g.size(); i++){
		double tmp = prim(g[i]);
		if(ans > tmp){
			ans = tmp;
			node = g[i];
		}
	}
	sort(node.begin(),node.end());
	cout<<node[0];
	for(int i = 1; i < node.size(); i++)
		cout<<" "<<node[i];
	cout<<endl;
}
int main(){
	while(~scanf("%d%d",&n,&m)&&n+m){
		input();
		solve();	
	}
	return 0;
}