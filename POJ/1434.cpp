#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define eps 1e-8
struct cistern{
	double b,h,w,d;	
};
vector<cistern> c;
int n;
double v;
double binary_search(double left,double right){
   while(right-left > eps){
   	  double mid = (left+right)/2;
   	  double sum = 0.0;
   	  for(int i = 0; i < n; i++){
   	  	if((mid > c[i].b || fabs(mid-c[i].b)<eps) ){
   	  	    if(mid < c[i].b+c[i].h)
				 sum += c[i].w*c[i].d*(c[i].h-(c[i].b+c[i].h-mid));
		    else{
		    	sum += c[i].w*c[i].d*c[i].h;
		    }
		}
   	  }
   	  //cout<<left<<" "<<right<<" "<<sum<<" "<<v<<endl;
   	  if(sum >= v){
   	  	 right = mid;
   	  }else{
   	  	 left = mid;
   	  }
   }
   return right;
	
}
int main(){
	
	int ncase;
	cin >> ncase;
	while(ncase--){
		cin >> n;
		c.clear();
		c.resize(n);
		double left = 0.0;
		double right = 100000000000.0;
		
		for(int i = 0; i < n; i++){
			scanf("%lf%lf%lf%lf",&c[i].b,&c[i].h,&c[i].w,&c[i].d);
			if(left > c[i].h){
				left = c[i].h;
			}
			if(right < c[i].h+c[i].b){
				right = c[i].h+c[i].b;
			}
		}
		//cout<<left<<" "<<right<<endl;
		scanf("%lf",&v);
		//cout<<v<<endl;
		double ans = binary_search(left,right);
		if(ans > right-10 || fabs(ans)<eps){
			printf("OVERFLOW\n");
		}else{
			printf("%.2lf\n",ans);
		}

		
	}
}