#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 3000000+10;
int minDiv[maxn],phi[maxn],sum[maxn];
void genPhi(){
	for(int i = 1; i < maxn; i++){
		minDiv[i] = i;
	}
	for(int i = 2; i*i <maxn; i++){
		if(minDiv[i] == i){
			for(int j = i*i; j < maxn; j+=i){
				minDiv[j] = i;
			}
		}
	}
	phi[1] = 1;
	for(int i = 2; i < maxn; i++){
		phi[i] = phi[i/minDiv[i]];
		if(i / minDiv[i] % minDiv[i] == 0){
			phi[i] *= minDiv[i];
		}else{
			phi[i] *= minDiv[i] -1;
		}
	}
}
int main(){
	
	int a;
	genPhi();
	int ncase,T=1;
	cin >> ncase;
	while(ncase--){
		cin >> a;
		long long  ans = 0;
		for(int i = 2; i <= a; i++){
			ans += phi[i];
			//cout<<i<<" "<<phi[i]<<endl;
		}
		cout<<T++<<" "<<a<<" "<<ans*2+3<<endl;
		
	}
	
}