#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,ans;
bool vis[20];
vector<string> sst;
int mat[15][15];
void backtrack(vector<int>&k,int c){
	if(k.size()==n){
		int sum = 0;
		for(int i = 0; i < k.size()-1; i++){
				sum += mat[k[i]][k[i+1]];
		}
		ans = max(ans,sum);
		return;
	}
	for(int i = 0; i < sst.size(); i++){
		if(!vis[i]){
			vis[i] = 1;
			k.push_back(i);
			backtrack(k,i);
			k.pop_back();
			vis[i] = 0;
		}
	}
}
int getlcs(string a,string b){
	int k = 0;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			int tl = i,tb = j,tmp = 0;
			while(tl<a.size() && tb<b.size()){
				if(a[tl]==b[tb]){
					tmp++;
				}
				tl++;
				tb++;
			}
			k = max(k,tmp);
		}
	}
	return k;
}
void init(){
	ans = 0;
	//sort(sst.begin(),sst.end());
	//memset(vis,0,sizeof(vis));
	for(int i = 0; i < sst.size(); i++){
		for(int j = i+1; j < sst.size(); j++){
			mat[i][j] = getlcs(sst[i],sst[j]);
			mat[j][i] = mat[i][j];
		}	
	}
}
int main(){
	while(~scanf("%d",&n) && n>0){
		sst.clear();
		for(int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			sst.push_back(tmp);
		}
		vector<int> k;
		for(int i = 0; i <= n-1; i++)	 k.push_back(i);
		init();
		do{
			int sum = 0;
			for(int i = 0; i < k.size()-1; i++){
				sum += mat[k[i]][k[i+1]];
			}
			ans = max(ans,sum);
		}while(next_permutation(k.begin(),k.end()));		
		cout<<ans<<endl;
	}
	
	return 0;
}