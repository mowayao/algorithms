#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define eps 1e-10
double x,y,c;
double binary_search(double left,double right){
	while(right-left>eps){
		double mid = (left+right)/2;
		double tmp = c/sqrt(x*x-mid*mid) + c/sqrt(y*y-mid*mid);
		if(tmp > 1.0){
			right = mid;
		}else{
			left = mid;
		}
	}
	return left;
}
int main(){
	
	while(cin >> x >> y >> c){
		double left = 0.0,right = min(x,y);
		double ans = binary_search(left,right);
		printf("%.3lf\n",ans);
	}
	
	
	return 0;
}