#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define inf 1000000000
const int maxn = 110;
int n,dis[maxn][maxn];
void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j)
			    dis[i][j] = 0;
			else
			    dis[i][j] = inf;
		}
		
	}
	
	
}
void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][j] > dis[i][k]+dis[k][j]){
					dis[i][j] = dis[i][k]+dis[k][j];
				}
				
				
			}
		}
	}
	
	
	
}
int main(){
	
	while(cin >> n && n != 0){
		init();
		for(int i = 1; i <= n; i++){
			int m;
			cin >> m;
			while(m--){
				int p,c;
				cin >> p >> c;
				//dis[p][i] = c;
				dis[i][p] = c;
			}
			
		}
		floyd();
	    /*for(int i = 1; i <= n; i++){
		   for(int j = 1; j <= n; j++){
			   cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
		}
		
	}*/
		int ind = 1,ans=0;
		long long Min = 0;
		for(int j = 1; j <= n; j++){
				ans = max(ans,dis[1][j]);
				Min += dis[1][j];
		}	
	//	cout<<Min<<endl;
		for(int i = 2; i <= n; i++){
			long long sum = 0;
			int tmp = 0;
			for(int j = 1; j <= n; j++){
				tmp = max(tmp,dis[i][j]);
				sum += dis[i][j];
			}
			if(sum < Min){
				Min = sum;
				ans = tmp;
				ind = i;
			}
		}
		if(Min >= inf)
		   cout<<"disjoint"<<endl;
		else
		   cout<<ind<<" "<<ans<<endl;
		
		
	}
	
	return 0;
}