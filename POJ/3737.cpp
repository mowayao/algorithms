#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define pi acos(-1.0)
const double eps = 1e-10;
double s;
int main(){
	
	double h,r,v;
	while(cin >> s){
		h = sqrt(2*s/pi+eps);
		if(fabs(h) < eps){
			r = 0;
			v = 0;
		}else{
		    r = sqrt(s*s/(pi*pi*h*h+2*pi*s));
		    v = pi*r*r*h/3;
	    }
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
	
	
	return 0;
}