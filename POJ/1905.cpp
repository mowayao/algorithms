#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define eps 1e-8
#define epss 1e-12
double l,n,c;
bool j(double x){
	if(x <epss && x > -epss){
		return 1;
	}else{
		return 0; 
	}
}
double binary_search(double left,double right){
	double kk =(1+n*c)*l;
	while(right-left>eps ||left-right <-eps){
		double mid = (left+right)/2;
		double r = l*l/(8*mid) + mid/2;
		double tmp = 2*acos((r-mid)/r)*r;	
		if(tmp >= kk){
			right = mid;		
		}else{
			left = mid;
		}
	}
	return left;
}
int main(){
	
	while(cin >> l >> n >> c){
		if(l < 0 && n < 0 && c < 0){
		    break;	
		}
		double ans;
		if(j(l)||j(n)||j(c)){
			ans = 0.0;
		}else{
		    double left = 0,right = l;
		    ans = binary_search(left,right);
		}
		
		printf("%.3lf\n",ans);
		
	}
	
	return 0;
}