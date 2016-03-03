#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 500+10;

int gcd(int a,int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){

    int n,a[maxn*maxn];
    map<int,int>cnt;
    scanf("%d",&n);
    for(int i = 0; i < n*n; i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    sort(a,a+n*n);
    vector<int> ret;
    for(int i = n*n-1; i >= 0; i--) {
        if(ret.size()==n) break;
        int tmp = a[i];
        if(cnt[tmp]==0) continue;
        for(int i = 0; i < ret.size(); i++) {
            cnt[gcd(ret[i],tmp)]-=2;
        }
        cnt[tmp]--;
        ret.push_back(tmp);
    }
    printf("%d",ret[0]);
    for(int i = 1; i < n; i++) {
        printf(" %d",ret[i]);
    }
    puts("");
    return 0;
}
