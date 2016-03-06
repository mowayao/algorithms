#include <iostream>
#include <cmath>
using namespace std;
double volume(double l,double n,double a,double m,double b,double c){
	double x =4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-
	   b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n);
	double y = c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)-(a*a+b*b-l*l)
	   *(b*b+c*c-m*m)*(c*c+a*a-n*n);
	//cout<<x-y<<endl;
	return (sqrt(x-y)/12); 
}
int main(){
	
	double l,n,a,m,b,c;
	scanf("%lf%lf%lf%lf%lf%lf",&l,&n,&a,&m,&b,&c);
	double ans = volume(l,n,a,m,b,c); 
	printf("%.4lf\n",ans);
	return 0;
}