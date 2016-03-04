#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define REP(_,a,b) for(int _ = (a); _ <(b); _++) 
struct stop{
	int pos,fuel;
	stop(int pos,int fuel):pos(pos),fuel(fuel){}
	friend bool operator <(stop a,stop b){
		return a.pos > b.pos;
	}
};
vector<stop> vs;
priority_queue<int> pq;
int n,L,P,ans;
void init(){
	vs.clear();
	ans = 0;
	while(!pq.empty()) pq.pop();
}
void input(){
	REP(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);
		vs.push_back(stop(a,b));
	}
	vs.push_back(stop(0,0));
	sort(vs.begin(),vs.end());
	scanf("%d%d",&L,&P);
}
void solve(){
	int curp = L,curf = P, i = 0;
	bool flag = true;
	while(i <= n){
		while(i <= n&&curp-vs[i].pos<=curf) {
			pq.push(vs[i].fuel);
			i++;
		}
		if(i==n+1){
			break;
		}
		if(!pq.empty()){
			ans++;
			curf += (vs[i-1].pos - curp) + pq.top();
			pq.pop();
			curp = vs[i-1].pos;
		}else{
			flag = false;
			break;
		}
	} 
	if(!flag){
		printf("-1\n");
	}else{
		printf("%d\n",ans);
	}
	
}
int main(){
	
	while(~scanf("%d",&n)){
		init();
		input();
		solve(); 
	}
	return 0;
}