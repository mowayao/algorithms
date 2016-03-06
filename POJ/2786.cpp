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
struct task{
    int cost,due;
    task(int cost=0,int due=0):cost(cost),due(due){}
    friend bool operator < (task a,task b) {
        return a.cost < b.cost;
    }
};
bool cmp(task a,task b) {
    return a.due < b.due;
}
priority_queue<task> pt;
vector<task> vt;
int n,ans;
void init() {
    vt.clear();
    while(!pt.empty()) pt.pop();
}
void input() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int s,t;
        scanf("%d%d",&s,&t);
        vt.push_back(task(s,t));
    }
    sort(vt.begin(),vt.end(),cmp);
}
void solve() {
    int cst = 0;
    for(int i = 0; i < n; i++) {
        if(cst+vt[i].cost <= vt[i].due) {
            pt.push(vt[i]);
            cst += vt[i].cost;
        }else if(!pt.empty()){
            
            task tk = pt.top();
            if(tk.cost > vt[i].cost) {
                cst += vt[i].cost-tk.cost;
                pt.pop();
                pt.push(vt[i]);
            }
        }
    }
    ans = pt.size();
    printf("%d\n",pt.size());
}
int main(){


    input();
    solve();
    return 0;
}
