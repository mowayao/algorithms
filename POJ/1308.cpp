#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 3000;
bool vis[maxn];
void init(){
	memset(vis,false,sizeof(vis));	
}

int main(){
	int n,m,T=1;
	while(cin >> n >> m && m != -1 && n != -1 ){
	
		if(n == 0 && m == 0){
			printf("Case %d is a tree.\n",T++);
			continue;
		}
		init();
		int cnt_n=0,cnt_e=0;
		if(!vis[n]){
				vis[n] = 1;
 				cnt_n++;
		}
		if(!vis[m]){
				vis[m] = 1;
 				cnt_n++;
		}
		cnt_e++;		
		bool flag = 1;
		while(cin >> n >> m && n+m){
			if(!vis[n]){
				vis[n] = 1;
 				cnt_n++;
			}
			if(!vis[m]){
				vis[m] = 1;
 				cnt_n++;
			}
			cnt_e++;
		}
		//cout<<cnt_n<<"   "<<cnt_e<<endl;
		if(cnt_n == cnt_e+1)
		 printf("Case %d is a tree.\n",T++);
		else
		 printf("Case %d is not a tree.\n",T++);
		
		
		
	}
	
	
	
	
	return 0;
}