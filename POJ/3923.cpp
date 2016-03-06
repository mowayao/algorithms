#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100+10;
char mat[maxn][maxn];
int n,m;
void input(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];
}
bool check(int a,int b,char ch){
	int tmp1=a,tmp2=b;
	int len1=1,wid1=1,len2=1,wid2=1;
	int a1,b1;
	a1 = a+1;
	mat[a][b] = '.';
	while(mat[a1][b]==ch){
		mat[a1][b] = '.';
		a1++;
		len1++;
	}
	b1 = b+1;
	while(mat[a][b1]==ch){
		mat[a][b1] = '.';
		b1++;
		wid1++;
	}
	a1--;
	b1--;
	if(mat[a1][b1]==ch)
	 	wid2++;
	a++;
	b++;
	while(mat[a][b1]==ch){
		mat[a][b1] = '.';
		a++;
		len2++;
	}
	while(mat[a1][b]==ch){
		mat[a1][b] = '.';
		b++;
		wid2++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == ch)
				mat[i][j] = '.';
		}
	}
	bool flag = 1;
	for(int i = tmp1; i < a1; i++){
		for(int j = tmp2; j < b1; j++){
			if(mat[i][j]>='A'&&mat[i][j]<='Z')
				flag = 0;
		}
	}
	if(len1==len2&&wid1==wid2 && flag && len1 >=3 && wid1>=3) return true;
	return false;
}
void solve(){
	vector<char> ans;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			char tmp = mat[i][j];
			if(mat[i][j]<='Z' && mat[i][j]>='A'&&check(i,j,mat[i][j]))
				ans.push_back(tmp);
		}
	for(int i = 0; i < ans.size(); i++)
		for(int j = i+1; j < ans.size(); j++)
			if(ans[i]>ans[j])
			 	swap(ans[i],ans[j]);	
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i];
	cout<<endl;
	
}
int main(){
	while(~scanf("%d%d",&n,&m) && n+m){
		input();
		solve();	
	}	
	return 0;
}