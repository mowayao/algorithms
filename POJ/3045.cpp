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
#define REP(_,a,b) for(int _ = (a); _ <= (b); _++)
struct Cows{
    int w,s;
    Cows(int w,int s):w(w),s(s){}
    friend bool operator < (Cows a,Cows b) {
        return a.w+a.s < b.w+b.s;
    }
};
vector<Cows> vc;
int n;

int main(){

    while(~scanf("%d",&n)) {
        int sum = 0;
        vc.clear();
        for(int i = 0; i < n; i++) {
            int w,s;
            scanf("%d%d",&w,&s);
            sum += w;
            vc.push_back(Cows(w,s));
        }
        sort(vc.begin(),vc.end());
        int ans = -vc[0].s,ps = vc[0].w;
        for(int i = 1; i < n; i++) {
            ans = max(ans,ps-vc[i].s);
            ps += vc[i].w;
        }
        printf("%d\n",ans);

    }
    return 0;
}
