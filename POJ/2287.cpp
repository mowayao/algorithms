#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000+10;
int main(){
	int n;
	vector<int> TJ;
	vector<int> Q;
	while(~scanf("%d",&n) && n){
		TJ.clear();
		Q.clear();
		TJ.resize(n);
		Q.resize(n);
		for(int i = 0; i < n; i++){
			scanf("%d",&TJ[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%d",&Q[i]);
		}
		sort(TJ.begin(),TJ.end());
		sort(Q.begin(),Q.end());
		//cout<<Q[n-1]<<endl;
		int d = 0;
        int ts,te,qs,qe;
        ts = qs = 0;
        te = qe = n-1;
		for(int i = 0; i < n; i++){
		   if(TJ[te]>Q[qe]){
		   	te--;
		   	qe--;
		   	d++;
		   }
		   else if(TJ[ts]>Q[qs]){
		   	qs++;
		   	ts++;
		   	d++;
		   }else{
		   	if(TJ[ts] != Q[qe]){
		   		d--;
		   		
		   	}
			   ts++;
		   	   qe--;
		   }
		}
		cout<<d*200<<endl;;
		
	    
		
	}
		
	return 0;
}