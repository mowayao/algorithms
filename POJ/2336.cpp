#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1440+10;
int time[maxn],ans[maxn],T[maxn];
int main(){
	int ncase;
	cin >> ncase;
	int n,t,m;
	while(ncase--){
		cin >> n >> t >> m;	
		for(int i = 1; i <= m; i++){
			cin >> T[i];
	    }
	    memset(ans,0,sizeof(ans));
		memset(time,0,sizeof(time)); 
	    for(int i = 1; i <= m; i++){
	    	ans[i] = max(ans[max(i-n,0)],ans[i])+1;
	    	time[i] = max(time[max(i-n,0)],T[i])+2*t;
		}
		cout<<time[m]-t<<" "<<ans[m]<<endl;
	
		
	}
	
	
	
	
	return 0;
}