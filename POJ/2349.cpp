#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 600;
int father[maxn];
int cnt;
struct edge{
	int u,v;
	double w;
	friend bool operator <(edge a,edge b){
		return a.w < b.w;
	}
}e[maxn*maxn];
void init(int n){
	for(int i = 1; i <= n; i++){
		father[i] = i;
    }
}
int find_set(int x){
	if(x != father[x]){
		return find_set(father[x]);
	}else{
		return father[x];
	}
	
}
bool Union(int u,int v){
	int x = find_set(u);
	int y = find_set(v);
	if(x != y){
		father[x] = y;
		return 1;
	}
	return 0;
}
void solve(int n,int m){
	sort(e,e+cnt);
	vector<int> eg;
	for(int i = 0; i < cnt; i++){
		if(Union(e[i].u,e[i].v)){
			eg.push_back(i);
		}
	}
	printf("%.2lf\n",e[eg[eg.size()-n]].w);
	
}
int main(){
	
	int ncase;
	cin >> ncase;
	int n,m;
	while(ncase--){
		cnt = 0;
		double x[maxn],y[maxn];
		scanf("%d%d",&n,&m);
		init(m);
	    for(int i = 1; i <= m; i++){
	    	scanf("%lf%lf",&x[i],&y[i]);
	    	for(int j = 1; j < i; j++){
	    		e[cnt].u = i;
	    		e[cnt].v = j;
	    		e[cnt].w = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
	    	    cnt++;
			}
	    }
	    solve(n,m);
		
	}
	
	return 0;
}
/*
3
3 3
1 2 2
2 3 3
3 1 3
3 3
1 2 3
2 3 2
3 1 3
3 2
1 2 2
2 3 2
*/