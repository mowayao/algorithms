#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
int d,v;
int main(){

    while(scanf("%d%d",&d,&v)&&d+v){
        double ans = (-12.0*v+2*pi*d*d*d)/(2*pi);
        printf("%.3lf\n",pow(ans,1.0/3));
    }
    return 0;
}
