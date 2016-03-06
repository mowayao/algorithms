#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10000+10;
int n;
int num[maxn];
int preS[maxn];
int dd[maxn];
int main(){

    while(~scanf("%d",&n)){
        preS[0] = 0;
        memset(dd,0,sizeof dd);
        int flag = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d",&num[i]);
            preS[i] = (preS[i-1]+num[i])%n;
            if(preS[i]==0) flag = i;
        }
        if(flag != -1){
            printf("%d\n",flag);
            for(int i = 1; i <= flag; i++){
                printf("%d\n",num[i]);
            }
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(dd[preS[i]] != 0){
                printf("%d\n",i-dd[preS[i]]);
                for(int k = dd[preS[i]]+1; k <= i; k++)
                    printf("%d\n",num[k]);
                break;
            }else
                dd[preS[i]] = i;
        }
    }

    return 0;
}
