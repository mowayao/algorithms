#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(_,a,b) for(int _ = (a); _ < (b); _++)
#define sz(s)  (int)((s).size())
typedef long long ll;
const double eps = 1e-9;
const int maxn = 200;
struct Point{
	double x,y;
	Point(double x=0.0,double y = 0.0):x(x),y(y){}
};
vector<Point> vP;
Point poly[maxn];
typedef Point Vector;
struct Line {
	Point P;
	Vector v;
	double ang;
	Line(){}
	Line(Point P,Vector v):P(P),v(v){
		ang = atan2(v.y,v.x);
	}
	bool operator <(const Line&L) const{
		return ang < L.ang;
	}
};
Line L[maxn];
int lcnt;
Vector operator + (Vector A,Vector B) {
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double p){
	return Vector(A.x*p,A.y*p);
}
Vector operator / (Vector A,double p){
	return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b){
	return a.x < b.x || (a.x==a.y && a.y < b.y);
}
int dcmp(double x){
	if(fabs(x) < eps) return 0;
	else return x < 0? -1:1;
}
bool operator == (const Point &a,const Point &b){
	return dcmp(a.x-b.x)==0&& dcmp(a.y-b.y)==0;
}
double Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}
double Length(Vector A) {return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;}
Vector Rotate(Vector A,double rad) {return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad)); }
Vector Normal(Vector A) {
	double L = Length(A);
	return Vector(-A.y/L,A.x/L);
}
Point getMid(Point A,Point B){//两点中点 
	return Point((A.x+B.x)/2,(A.y+B.y)/2);
}
bool OnLeft(Line L,Point p){
	return Cross(L.v,p-L.P) > 0;
}
Point GetIntersection(Line a,Line b){
	Vector u = a.P-b.P;
	double t = Cross(b.v,u) / Cross(a.v,b.v);
	return a.P+a.v*t;
}
int HalfplaneIntersection(Line* L,int n,Point* poly){
	sort(L,L+n);
	int first,last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first=last=0] = L[0];
	for(int i = 1; i < n; i++){
		while(first < last && !OnLeft(L[i],p[last-1])) last--;
		while(first < last && !OnLeft(L[i],p[first])) first++;
		q[++last] = L[i];
		if(fabs(Cross(q[last].v,q[last-1].v))<eps) {
			last--;
			if(OnLeft(q[last],L[i].P)) q[last] = L[i];
		}
		if(first<last) p[last-1] = GetIntersection(q[last-1],q[last]);
	}
	while(first < last && !OnLeft(q[first],p[last-1])) last--;
	if(last - first <=1) return 0;
	p[last] = GetIntersection(q[last],q[first]);
	int m = 0;
	for(int i = first; i <= last; i++) poly[m++] = p[i];
	return m;
}
void init(){
	vP.clear();
	lcnt = 0;
	vP.push_back(Point(0,0));
	vP.push_back(Point(10,0));
	vP.push_back(Point(10,10));
	vP.push_back(Point(0,10));
	int n = sz(vP);
	#define next(i) ((i)+1)%n
	REP(_,0,n){
		L[_] = Line(vP[_],vP[next(_)]-vP[_]);
		lcnt++;
	}
}
int main(){
	
	double x,y;
	string st;
	init();
	Point pre = Point(0,0),cur;
	bool flag = true;
	while(cin >> x >> y >> st){
		if(!flag){
			printf("0.00\n");
			continue;
		}
		cur = Point(x,y);
		if(st[0]=='S'){
			printf("0.00\n");
			flag = false;
			continue;
		}else if(st[0]=='H'){
			L[lcnt++] = Line((pre+cur)/2,Normal(pre-cur)) ;
		}else{
			L[lcnt++] = Line((pre+cur)/2,Normal(cur-pre));	
		}
		pre = Point(x,y);
		int m = HalfplaneIntersection(L,lcnt,poly);
		if(m==0){
			printf("0.00\n");
			flag = false;
		}else{
			#define next(i) ((i)+1)%m
			double area = 0.0;
			REP(_,0,m) { 
				area += Cross(poly[_],poly[next(_)])/2;
			}
			printf("%.2f\n",fabs(area));	
		}
	}	
	return 0;
}