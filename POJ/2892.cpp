#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int n,m;
set<int> sv;
stack<int> dv;
int main(){
    
    while(~scanf("%d%d",&n,&m)){
        while(!dv.empty()) dv.pop();
        sv.clear();
        sv.insert(0);
        sv.insert(n+1);
        while(m--){
            getchar();
            set<int>::iterator itlow,itup;
            char op;
            int d;
            scanf("%c",&op);
            if(op=='D'){
                scanf("%d",&d);
                dv.push(d);
                sv.insert(d);
            }else if(op == 'R'){
                if(!dv.empty()){
                    int td = dv.top();
                    dv.pop();
                    if(sv.count(td)!=0){
                        sv.erase(td);
                    }
                }
            }else{
                scanf("%d",&d);
                if(sv.count(d)!=0){
                    printf("0\n");
                }else{
                    int ans = 0;
                    itlow = sv.lower_bound(d);
                    itup = sv.upper_bound(d);
                    itlow--;
                    printf("%d\n",*itup-*itlow-1);
                }
            }

        }
    }
    return 0;
}
