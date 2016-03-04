#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct mony{
	int s,t;
	int ts,tt;
	int last;
	friend bool operator <(mony a,mony b){
		if(a.ts != b.ts)
			return a.ts < b.ts;
		return a.tt < b.tt;
	}
};
int n;
vector<mony>mm;
void init(){
	mm.clear();
	mony tk;
	for(int i = 0; i < n; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		tk.s = a;
		tk.t = b;
		tk.last = (b-a)/2+1;
		if((b-a)%2==0){
			tk.ts = (b-a)/2+a-1;
			tk.tt = tk.ts+2;
		}else{
			tk.ts = (b-a-1)/2+a;
			tk.tt = tk.ts+1;
		}
		mm.push_back(tk);
	}
	sort(mm.begin(),mm.end());
}
void solve(){
	bool flag = 1;
	int now_s,now_t,last_t=mm[0].s+mm[0].last;
	for(int i = 1; i < n; i++){
		now_s = max(mm[i].s,last_t);
		if(mm[i].t-now_s < mm[i].last){
			flag = 0;
			break;
		}
		last_t = min(now_s+mm[i].last,mm[i].t);
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;	
}
int main(){
	
	while(~scanf("%d",&n)&&n){
		init();
		solve();
	}
	
	
	return 0;
}