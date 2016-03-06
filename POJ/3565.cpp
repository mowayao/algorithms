#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 555;
const int inf = 1000000000;
double w[maxn][maxn],x[maxn],y[maxn],slack[maxn];
int prev_x[maxn],prev_y[maxn],son_y[maxn],par[maxn];
int lx,ly,pop;
struct node{
	double x,y;
}apple[maxn],ant[maxn];
void adjust(int v){
	son_y[v] = prev_y[v];
	if(prev_x[son_y[v]] !=-2){
		adjust(prev_x[son_y[v]]);
	}
}
bool find(int v){
	int i;
	for(i =0; i< pop; i++)
	   if(prev_y[i]==-1){
	        if(slack[i]>x[v]+y[i]-w[v][i]){
	        	slack[i] = x[v]+y[i]-w[v][i];
	        	par[i] = v;
	        }
	        if(x[v]+y[i] == w[v][i]){
	        	prev_y[i] = v;
	        	if(son_y[i]==-1){
	        		adjust(i);
	        		return 1;
	        	}
	        	if(prev_x[son_y[i]]!=-1){
	        		continue;
	        	}
	        	prev_x[son_y[i]]=i;
	        	if(find(son_y[i]))
	        	    return 1;
	        }
	    }
	return 0;
}
void km(){
	int i,j;
	double m;
	for(i=0; i < pop; i++){
		son_y[i] = -1;
		y[i] = 0;
	}
	for(i=0; i < pop; i++){
		x[i] = 0;
		for(j = 0; j <pop; j++){
			x[i] = max(x[i],w[i][j]);
		}
	}
	bool flag;
	for(i = 0; i < pop; i++){
		for(j = 0; j < pop; j++){
			prev_x[j] = prev_y[j] = -1;
			slack[j] = inf;
		}
		prev_x[i] = -2;
		if(find(i)) continue;
		flag = 0;
		while(!flag){
			m = inf;
			for(j = 0; j < pop; j++)
			   if(prev_y[j] == -1)
			       m = min(m,slack[j]);
			for(j = 0; j <pop; j++){
				if(prev_x[j]!=-1){
					x[j] -= m;
				}
				if(prev_y[j] !=-1){
					y[j]+=m;
				}else{
					slack[j]-=m;
				}
			}
			for(j=0; j < pop; j++){
				if(prev_y[j]==-1&&!slack[j]){
					prev_y[j] = par[j];
					if(son_y[j]==-1){
						adjust(j);
						flag = 1;
						break;
					}
					prev_x[son_y[j]] = j;
					if(find(son_y[j])){
						flag = 1;
						break;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < pop; i++){
		//ans += w[son_y[i]][i];
		//cout<<ans<<endl; 
		cout<<son_y[i]+1<<endl;
	}
	
}
int main(){
	
	int m,n;
	while(~scanf("%d",&pop) ){
		for(int i = 0; i < pop; i++){
			scanf("%lf%lf",&ant[i].x,&ant[i].y);
		}
		for(int i = 0; i < pop; i++){
			scanf("%lf%lf",&apple[i].x,&apple[i].y);
		}
		for(int i = 0; i < pop; i++){
			for(int j = 0; j < pop; j++){
				w[i][j] = -sqrt((apple[i].x-ant[j].x)*(apple[i].x-ant[j].x)+(apple[i].y-ant[j].y)*(apple[i].y-ant[j].y));
			}
		}
		km();
		//cout<<pop<<endl;
		
	}
	
	return 0;
}