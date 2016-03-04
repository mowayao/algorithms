#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const double eps = 1e-10;
struct point 
{ 
 double x; 
 double y;  
};
struct line{
   double a,b,c;
};
line makeline(point p1,point p2) 
{ 
 line tl; 
 int sign = 1; 
 tl.a=p2.y-p1.y; 
 if(tl.a<0) 
 { 
  sign = -1; 
  tl.a=sign*tl.a; 
 } 
 tl.b=sign*(p1.x-p2.x); 
 tl.c=sign*(p1.y*p2.x-p1.x*p2.y); 
 return tl; 
} 

bool lineintersect(line l1,line l2,point &p) // 是 L1，L2 
{ 
  double d=l1.a*l2.b-l2.a*l1.b; 
  if(abs(d)<eps) // 不相交 
    return false; 
  p.x = (l2.c*l1.b-l1.c*l2.b)/d; 
  p.y = (l2.a*l1.c-l1.a*l2.c)/d; 
  return true; 

} 
point P[4],cross;
line LINE1,LINE2;
int main(){

    int ncase;
    scanf("%d",&ncase);
    printf("INTERSECTING LINES OUTPUT\n");
    while(ncase--){
       for(int i = 0; i < 4; i++)
          cin >> P[i].x >> P[i].y;
          LINE1 = makeline(P[0],P[1]);
          LINE2 = makeline(P[2],P[3]);
          if(lineintersect(LINE1,LINE2,cross)){
               printf("POINT %.2lf %.2lf\n",cross.x,cross.y);
          }else{
             // cout<<LINE1.a<<" "<<LINE1.b<<" "<<LINE1.c<<" "<<LINE2.a<<" "<<LINE2.b<<" "<<LINE2.c<<endl;
            if(abs(LINE1.a*LINE2.c-LINE1.c*LINE2.a)<eps && abs(LINE1.b*LINE2.c-LINE1.c*LINE2.b)<eps )
                printf("LINE\n");
             else
                printf("NONE\n");
          }
    }
    printf("END OF OUTPUT\n");
    return 0;
}