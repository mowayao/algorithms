#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const long long dx[10]={0,-1,0,1,-1,0,1,-1,0,1};
const long long dy[10]={0,-1,-1,-1,0,0,0,1,1,1};
struct node{
	
	long long  x,y;
	
}pre,now;
long long Cross(node a,node b){
    return a.x*b.y-a.y*b.x;	

}
int main(){
	
   
	int ncase;
	cin >> ncase;
//	getchar();
	while(ncase--){
		char n;
		long long ans=0;
		now.x = 0;
		now.y = 0;
		while(cin >> n && n !='5'){
		
		   long long ind = n-'0';
		   pre = now;
		   now.x += dx[ind];
		   now.y += dy[ind];
		   ans += Cross(pre,now);	
		}
	    if(ans < 0)
	      ans = -ans;
	    if(ans%2)
	      cout<<ans/2<<".5"<<endl;
	    else
		   cout<<ans/2<<endl;
    }

	
	
	return 0;
}