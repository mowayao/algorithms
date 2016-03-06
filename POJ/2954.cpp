#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct point{
   int x,y;
};
point a,b,c;
int gcd(int a,int b){
    return b==0? a:gcd(b,a%b);
}
long long int count_num(point m,point n){
    long long int x1 = abs(m.x - n.x);
    long long int y1 = abs(m.y - n.y);
    if(x1 == 0){

        return y1+1;
    }
    if(y1 == 0){
        return x1+1;
    }
    long long int cnt = gcd(x1,y1)+1;
    return cnt;
}
int main(){

    while(~scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)){
    	if(a.x == 0 && a.y == 0&&b.x==0&&b.y==0&&c.x==0&&c.y==0)
    	   break;
        long long int area =  abs((c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x));
        long long int num = count_num(a,b)+count_num(a,c)+count_num(b,c)-3;
        
        //cout<<area<<"   "<<num<<endl;
        long long int ans = (area-num+2);
        //cout<<ans<<endl;
        if(ans%2){
            ans = ans/2+1;
        }else{
            ans/=2;
        }
        cout<<ans<<endl;
        //cout<<area<<endl;


    }

    return 0;
}