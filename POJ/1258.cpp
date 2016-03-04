#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n;//顶点数 
int m;//边数 
const int maxn = 110;
int father[maxn];
struct edge{
    int x,y,w;
	edge(int x=0, int y=0, int w=0):x(x),y(y),w(w){}
	friend bool operator < (edge a,edge b){
		return a.w < b.w;
	}
	
}e[maxn*maxn];
int find(int x){
	if(x == father[x]) return x;
 	else  return father[x] = find(father[x]);
}
int kruscal(){
	sort(e,e+m);
	int cnt = n;
	int ans = 0;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 0; i < m; i++){
    	int t1 = find(e[i].x);
		int t2 = find(e[i].y);
		if(t1 != t2){
			father[t1] = t2;
			ans += e[i].w;
		    if(cnt == 1) break;
	    }
	    
	} 
	return ans;
	 
}
int main(){
	while(cin >> n && n!=0){
		m = 0;
		for(int i = 1; i <= n; i++){
		  for(int j = 1; j <= n; j++){
		  	  int a;
		  	  cin >> a;
		  	  if(a!=0 && j > i){
		  	  	e[m].x = i;
		  	  	e[m].y = j;
		  	  	e[m].w = a;
		  	  	m++;
		  	  }
		  }
	    }
	    printf("%d\n",kruscal());  	
	}
	return 0;
}