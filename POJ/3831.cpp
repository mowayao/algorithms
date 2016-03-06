#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double INF = 1e8;
struct circle{
    double x,y;
    double r;
};
int n;
double ans;
vector<circle> vc;
void init(){
    vc.clear();
    ans = 1e8;
}
double area(int i,double r1,int j,double r2){
    double d=sqrt((vc[i].x-vc[j].x)*(vc[i].x-vc[j].x)+(vc[i].y- vc[j].y)*(vc[i].y-vc[j].y));//圆心距
    if(r1>r2){
        double temp=r1;
        r1=r2;
        r2=temp;
    }//r1取小
    if(r1+r2<=d)
        return 0;//相离
    else if(r2-r1>=d)
        return pi*r1*r1;//内含
    else {
        double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
        double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
        return (a1*r1*r1+a2*r2*r2-r1*d*sin(a1));
 }//相交
}

double binary_search(int i,double r){
    double l = 0;
    r = min(ans,r);
    while(r-l>eps){
        double mid = (l+r)/2;
        bool flag = 1;
        for(int k = 0; k < n; k++){
            if(area(i,mid,k,vc[k].r)<vc[k].r*vc[k].r*pi/2){
                flag = 0;
                break;
            }
        }
        if(flag){
            r = mid;
        }else{
            l = mid;
        }
    }
    return l;
}
void solve(){
    for(int i = 0; i < n; i++){
        double tmp = binary_search(i,1e6);
        ans = min(tmp,ans);
    }
    printf("%.4f\n",ans);

}
int main(){
    int ncase;
    cin >> ncase;
    while(ncase--){
        init();
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            circle tmp;
            scanf("%lf%lf%lf",&tmp.x,&tmp.y,&tmp.r);
            vc.push_back(tmp);
        }
        solve();

    }
    return 0;
}
