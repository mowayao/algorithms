#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 100000+10;
long long num[maxn];
long long sum[maxn],ans;
int n;
int next[maxn],last[maxn];
stack<long long> stk,sk;
void init(){
    ans = -1;
    sum[0] = 0;
    while(!stk.empty()) stk.pop();
    while(!sk.empty()) sk.pop();
}
int main(){
		scanf("%d",&n);
        init();
        for(int i = 1; i <= n; i++){
            scanf("%lld",&num[i]);
            sum[i] = sum[i-1] + num[i];
        }
        stk.push(0);
        num[0] = -100;
        for(int i = 1; i <= n; i++){
           /* if(num[i] == 0){
                last[i] = i;
            }
            else */if(num[i]>num[stk.top()]){
                stk.push(i);
                last[i] = i;
            }else{
                while(num[stk.top()]>=num[i])  stk.pop();
                if(stk.top()==0)
                    last[i] = 1;
                else
                    last[i] = stk.top()+1;
                stk.push(i);
            }
        }
        sk.push(0);
        for(int i = n; i >= 1; i--){
            /*if(num[i]==0){
                next[i] = i;
            }
            else*/ if(num[i]>num[sk.top()]){
                sk.push(i);
                next[i] = i;
            }else{
                while(num[sk.top()]>=num[i]) sk.pop();
                if(sk.top()== 0)
                    next[i] = n;
                else
                    next[i] = sk.top()-1;
                sk.push(i);
            }
        }
        int sta = 1,end = 1;
        for(int i = 1; i <= n; i++){
            long long tmp = (sum[next[i]]-sum[last[i]-1])*num[i];
            /*if(ans == tmp){
                if(end-sta > next[i]-last[i]){
                    end = next[i];
                    sta = last[i];
                }
            }
            else*/ if(ans < tmp){
                ans = tmp;
                end = next[i];
                sta = last[i];
            }
        }
        printf("%lld\n%d %d\n",ans,sta,end);

    return 0;
}