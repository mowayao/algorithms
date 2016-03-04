#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	
	int ans,a,b,c,d,T=1;
	int ncase;
	while(cin >> a >> b >> c >>d){
		if(a == -1 && b ==-1 && c ==-1 && d==-1)
		break;
		int find = 0;
		for(int i = 1; !find; i++){
			if((a+23*i-b)%28 ==0&& (a+23*i-c)%33==0){
				find = 1;
				ans = a + 23*i -d;
			}
		}
	    if(ans > 21252){
	    	ans = ans%21252;
	    }
	    while(ans <= 0){
	    	ans += 21252;
	    }
	     // i = 25252;
		printf("Case %d: the next triple peak occurs in %d days.\n",T++,ans);
		
	}
	
	return 0;
}
//24 29 34 0           1
//24 29 34 1           21252
//24 29 34 2           21251
//0  0  0  0           21252