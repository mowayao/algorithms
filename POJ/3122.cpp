#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 10000+10;
#define pi acos(-1.0)
#define eps 1e-7
int n,f;
double area[maxn],sum;
bool isok(double x){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += int(area[i]/x);
	}
	if(cnt >= f+1){
		return false;
	}else{
		return true;
	}
}
double binary_search(double left,double right){
	while(right-left>eps){
		double mid = (left+right)/2;
		if(isok(mid)){
			right = mid;
		}else{
			left = mid;
		}
	}
	return left;
}
int main(){
	int ncase;
	cin >> ncase;
	while(ncase--){
		sum = 0.0;
		cin >> n >> f;
		for(int i = 0; i < n; i++){
			double r;
			scanf("%lf",&r);
			area[i] = r*r*pi;
			sum += area[i];
		}
		double left = 0,right= 10000000000.0;
		double ans = binary_search(left,right);
		printf("%.4lf\n",ans);
		
	}
}