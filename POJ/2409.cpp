#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int gcd(int a,int b){
	return b == 0?a:gcd(b,a%b);
}
int main(){
	
	int s,c;
	while(cin >> c >> s && s+c){
		int ans = 0;
		for(int i = 1; i <=  s; i++){
			ans += int(pow(c*1.0,gcd(i,s))*1.0);
		}
		if(s%2==1){
			ans += int(s*pow(c*1.0,s/2+1));
		}else{
		    ans += int(s/2*pow(c*1.0,s/2*1.0)+s/2*pow(c*1.0,s/2+1*1.0));
		}
		ans = ans/(s*2);
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}