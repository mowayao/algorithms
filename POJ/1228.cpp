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
const double eps = 1e-10;
const int maxn = 1000+10;
int n;
struct Point{
	double x,y;
	Point(double x=0.0,double y = 0.0):x(x),y(y){}
};
Point vP[maxn];
Point poly[maxn];
typedef Point Vector;
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
int dcmp(double x){
	if(fabs(x) < eps) return 0;
	else return x < 0? -1:1;
}
bool operator < (const Point &a,const Point &b){
	return dcmp(a.x-b.x) <0 || dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0;
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

bool OnSegment(Point p,Point a1,Point a2){
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p)) < 0;
}

int ConvexHull(Point* p,int n,Point *ch){
	sort(p,p+n);
	int m = 0;
	for(int i = 0; i < n; i++) {
		while(m > 1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0) m--;
		ch[m++] = p[i]; 
	}
	int k = m;
	for(int i = n-2; i >= 0; i--){
		while(m > k && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	return m;
}

void input(){
	scanf("%d",&n);
	REP(i,0,n){
		scanf("%lf%lf",&vP[i].x,&vP[i].y);
	}
}
void solve(){
	int m = ConvexHull(vP,n,poly);
	if(n < 6 || m < 3){
		printf("NO\n");
		return;
	}
	bool flag = true;
	REP(i,1,m) {
		int cnt = 0;
		REP(j,0,n) {
			if(OnSegment(vP[j],poly[i],poly[i-1])){
				cnt++;
			}
		}
		if(cnt==0){
			flag = false;
			break;
		}
	}
	if(flag){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}
int main(){
	
	int ncase;
	cin >> ncase;
	while(ncase--){
		input();
		solve();
	}
	return 0;
}