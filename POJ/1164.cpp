#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 60000;
int n,m,cnt,ans;
bool vis[maxn];
vector<vector<int> > V;
void init(){
	V.clear();
	V.resize(maxn);	
	memset(vis,0,sizeof(vis));
	cnt = 0;
	ans = 0;
}
void dfs(int x,int &num){
	vis[x] = 1;
	for(int i = 0; i < V[x].size(); i++){
		if(!vis[V[x][i]]){
			vis[V[x][i]] = 1;
			num += 1;
			dfs(V[x][i],num);
		}
	}
	
}
int main(){
	
	while(cin >> n >> m){
		init();
	   	for(int i = 0; i < n; i++)
	   	  for(int j = 0;j < m; j++){
	   	  	 int a;
	   	  	 cin >> a;
	   	  	 if(a >= 8){	
	   	  	 	a -= 8;
	   	  	 }else{
	   	  	 	V[i*m+j].push_back(i*m+m+j);
	   	  	 }
	   	  	 if(a >= 4){
	   	  	 	a -= 4;
	   	  	 }else{
	   	  	 	V[i*m+j].push_back(i*m+j+1);
	   	  	 }
	   	  	 if(a >= 2){
	   	  	 	a -= 2;
	   	  	 }else{
	   	  	 	V[i*m+j].push_back(i*m-m+j);
	   	  	 }
	   	  	 if(a >= 1){
	   	  	 	a -= 1;
	   	  	 	
	   	  	 }else{
				V[i*m+j].push_back(i*m+j-1);
	   	  	 }	   	  	
	   	  }
	   	/*  for(int i = 0; i < n*m; i++){  
	   	      for(int j = 0; j < V[i].size(); j++){
	   	      	cout<<V[i][j]<<" ";
	   	      }
	   	      cout<<endl;
	   	  }*/
	   	       
	   //	vector<vector<int> > tmp = V;
	   	for(int i = 0; i < n; i++){
	   		for(int j = 0; j < m; j++){
	   			int num = 1;
	   			if(!vis[i*m+j]){
	   				cnt++;
	   			}
	   			dfs(i*m+j,num);
	   			if(num > ans)
	   			 ans = num;
	   		}
	   	}
	   	cout<<cnt<<endl<<ans<<endl;
		
		
		
		
	}
	return 0;
} 