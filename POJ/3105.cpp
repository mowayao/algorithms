/*
author:mowayao
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define REP1(_,a,b) for(int _ = (a); _ <= (b); _++)
#define REP2(_,a,b) for(int _ = (a); _ < (b); _++)
#define RREP(_,a,b) for(int _ = (a); _ >= (b); _--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define pb push_back
#define clr(a) (a.clear())
#define sz(x) (int)(x).size()
#define all(a) (a.begin()),(a.end())
#define zero(a) memset(a,0,sizeof(a))
const int maxn = 32;
LL scale2[maxn];
LL d,n;
void getScale2() {
    scale2[0] = 1;
    REP2(i,1,maxn)  {
        scale2[i] = scale2[i-1]<<1;
    }
}
void init() {
    d = lower_bound(scale2,scale2+maxn,n)-scale2;
}
void solve() {
	double ret = 0;
    REP1(i,0,d) {
    	double p = 0.0;
		if(n&scale2[i]) {
			p = ((n/scale2[i+1])*scale2[i]+(n%scale2[i])+1)/double(n+1);
		}else{
			p = (n/scale2[i+1])*scale2[i]/double(n+1);
		}
    	ret += 2*p*(1-p)*scale2[i];
        
    }
    
    printf("%.2f\n",ret);
}
int main() {
    int ncase;
    getScale2();
    cin >> ncase;
    while(ncase--) {
        scanf("%d",&n);
        n--;
        init();
        solve();

    }
    return 0;
}