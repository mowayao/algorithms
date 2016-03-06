#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 200+10;
int n;
double dis[maxn][maxn];
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				  dis[i][j] = min(dis[i][j],max(dis[i][k],dis[k][j]));		     
			}
		}
	}
	
	
}
int main(){
	
	int T=1;
	while(cin >> n && n){
		double x[maxn],y[maxn];
		for(int i = 1; i <= n; i++){
			cin >> x[i] >> y[i];
			for(int j = 1; j < i; j++){
				dis[i][j] = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
				dis[j][i] = dis[i][j];
			}
		}
	
	    floyd();
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",T++,dis[1][2]);
		
	}
	
	
	
	
	
	return 0;
}