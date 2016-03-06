/*******************************************************/
/* UVa 199 SCUD Busters                                 */
/* Author: Mowayao                                      */
/* Version: 2013/05/06                                 */
/*******************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
//向量
struct Point{
  int x,y;
  friend bool operator <(Point a,Point b){
     if(a.x < b.x)
       return 1;
     else  if(a.x == b.x)
       return a.y < b.y;
     else
       return 0;
  }
  int norm(){
     return x*x+y*y;
  }
   friend bool operator ==(Point a,Point b){
    return  a.x==b.x && a.y==b.y;
  }
  Point(int x = 0,int y = 0):x(x),y(y){}
};
vector<Point>a;
Point operator - (Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
//凸包
struct Polygon_convex{
    vector<Point> p;
    Polygon_convex(int Size = 0){
        p.resize(Size+1);
    }

};
/*
复杂度：O(1)
输入： 向量 a
      向量 b
输出: a,b的叉积
*/
int Cross(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}


vector<Polygon_convex>V;//凸包容器
/*
复杂度：O(nlogn)
输入：a   所有的点
输出: 用a中的点求出的凸包
*/
Polygon_convex convex_hull (vector<Point> a){

     Polygon_convex res(2*a.size()+5);
     sort(a.begin(),a.end());
     //a.erase(unique(a.begin(),a.end()),a.end());
     int m = 0;
     for(int i = 0; i < a.size(); ++i){
        while(m>1 && Cross(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2])<=0 ) --m;//右转  回溯
        res.p[m++] = a[i];

     }
     int k = m;
     for(int i = int(a.size()-2); i >= 0; --i){
        while(m > k && Cross(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2])<=0) --m;//右转  回溯
        res.p[m++] = a[i];
     }
     res.p.resize(m);
     if(a.size() > 1)  res.p.resize(m-1);
     return res;
}
/*
复杂度：O(n)
输入：一个点 a
     一个凸包 b
输出: a是否在b中
*/
bool PointInPolygon_convex(const Point &a,const Polygon_convex &b)
{
      int n = b.p.size();
      #define next(i) ((i+1)%n)
      int sign = 0;
      for(int i = 0; i < n; ++i)  {
           int x = Cross(b.p[i]-a,b.p[next(i)]-a);
           if(x){
               if(sign){
                       if(sign != x) return 0;

               } else  sign = x;

           }

      }
     return 1;
}

int main(){


   cin>>n;
   a.clear();
   a.resize(n);
   for(int i = 0; i < n; i++)
      cin >> a[i].x >> a[i].y;
   Polygon_convex res = convex_hull(a);
   int ans = 0;
   for(int i = 0; i < res.p.size(); i++){
       for(int j = i+1; j < res.p.size(); j++){
           ans = max(ans,(res.p[i]-res.p[j]).norm());
       }
   }
    cout<<ans<<endl;
    return 0;
}

