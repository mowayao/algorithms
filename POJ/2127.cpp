#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 600;
int A[maxn],B[maxn],dp[maxn][maxn],pre[maxn][maxn];
int n,m;
void solve(){
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
	for(int i = 1; i <= n; i++){
		int k = 0;
		for(int j = 1; j <= m; j++){
			if(A[i]!=B[j]) dp[i][j] = dp[i-1][j];
			if(A[i]>B[j]&&dp[i][j]>dp[i][k]) k = j;
			if(A[i] == B[j]){
				dp[i][j] = dp[i][k]+1;
				pre[i][j] = k;
			}
		
		}
	}
	int ans = -1,x = n,y = 0;
	for(int i = 1; i <= m; i++){
		if(dp[n][i] > ans){
			ans = dp[n][i];
			y = i;
		}
	}
	stack<int>kk;
	while(dp[x][y]){
		if(A[x]!=B[y]) x--;
		else{
			kk.push(B[y]);
			y = pre[x][y];
		}
	}
	cout<<kk.size()<<endl;
	if(!kk.empty()){
		cout<<kk.top();
		kk.pop();
	} 
	while(!kk.empty()){
		cout<<" "<<kk.top();
		kk.pop();
	}
	cout<<endl;
}
int main(){
	
	while(~scanf("%d",&n)){
		for(int i = 1; i <= n; i++) scanf("%d",&A[i]);
		scanf("%d",&m);
		for(int i = 1; i <= m; i++) scanf("%d",&B[i]);
		solve();
	}
	
	return 0;
}