#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20000+10,maxm = 100000+10;;
int n,num[maxn];
long long C[maxn],D[maxn];
int ext1[maxm],ext2[maxm];
void init(){
	memset(C,0,sizeof(C));
	memset(ext1,0,sizeof(ext1));
	memset(ext2,0,sizeof(ext2));
	memset(D,0,sizeof(D));
}
int lowbit(int x){
	return x&(-x);
}
int sum1(int x){
	int ret = 0;
	while(x > 0){
		ret += ext1[x];
		x -= lowbit(x);
	}
	return ret;
}
int sum2(int x){
	int ret = 0;
	while(x > 0){
		ret += ext2[x];
		x -= lowbit(x);
	}
	return ret;
}
void add1(int x){
	while(x<maxm){
		ext1[x]++;
		x += lowbit(x);
	}
}
void add2(int x){
	while(x<maxm){
		ext2[x]++;
		x += lowbit(x);
	}
}
void solve(){
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		add1(num[i]);
		C[i] = sum1(num[i]-1);
		//cout<<C[i]<<endl;
	}
	for(int i = n; i >= 1; i--){
		add2(num[i]);
		D[i] = sum2(num[i]-1);
	}
	for(int i = 1; i <= n; i++){
		ans += C[i]*(n-i-D[i])+(i-C[i]-1)*D[i];
	}
	cout<<ans<<endl;
}
int main(){
	int ncase;
	cin >> ncase;
	while(ncase--){
		init();
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) {
			scanf("%d",&num[i]);
		}
		solve();
	}
	return 0;
}
