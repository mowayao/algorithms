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
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define REP(_,a,b) for(int _ = (a); _ <= (b); _++)
#define RREP(_,a,b) for(int _ = (a); _ >= (b); _--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define pb push_back
#define clr(a) (a.clear())
#define sz(x) (int)(x).size()
#define all(a) (a.begin()),(a.end())
#define zero(a) memset(a,0,sizeof(a))
const int maxn = 100000+10;
const LL oo = 1000000000000000000LL+10;
LL h;
int a,b,c;
queue<int> que;
bool inQue[maxn];
LL dx[maxn];
void init() {
    zero(inQue);
    REP(i,0,a) dx[i] = oo;
    while(!que.empty()) que.pop();
}
void SPFA() {
    dx[0] = 0;
    inQue[0] = true;
    que.push(0);
    while(!que.empty()) {
        int td = que.front();
        que.pop();
        int t1 = (td+b)%a,t2 = (td+c)%a;
        inQue[td] = false;
        if(dx[t1] > dx[td]+b && dx[td]+b <= h) {
            dx[t1] = dx[td]+b;
            if(!inQue[t1]) {
                inQue[t1] = true;
                que.push(t1);
            }
        }
        if(dx[t2] > dx[td]+c && dx[td]+c <= h) {
            dx[t2] = dx[td]+c;
            if(!inQue[t2]) {
                inQue[t2] = true;
                que.push(t2);
            }
        }
    }
}
void solve() {
    SPFA();
    LL  ret = (h-1)/a+1;
    REP(i,1,a-1) {
        if(dx[i] != oo) {
            //cout<<i<<"!!!"<<dx[i]<<endl;
            ret += (h-dx[i]-1)/a+1;
        }
    }
    cout<<ret<<endl;
}
int main() {
    while(~scanf("%lld%d%d%d",&h,&a,&b,&c)) {
        init();
        solve();
    }

    return 0;
}
