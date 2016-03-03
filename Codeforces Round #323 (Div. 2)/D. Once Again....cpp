#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 100+10;
const int inf = 1e9;
vector<int> getArray(int *a,int n,int k) {
    vector<int> ret;
    for(int i = 0; i < n*k; i++) {
        if(i<n) ret.push_back(a[i]);
        else ret.push_back(a[i%n]);
    }
    return ret;
}

vector<int> myLIS(vector<int> a,int n) {
    vector<int>dp,ret;
    dp.resize(n+1);
    dp[0] = -inf;
    for(int i = 1; i <= n; i++) dp[i] = 1000;
    for(int i = 0; i < n; i++) {
        int tmp = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        ret.push_back(tmp);
        dp[tmp] = a[i];
    }
    return ret;
}
int main(){
    int n,T,a[maxn];
    scanf("%d%d",&n,&T);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    int ret = 0;
    if(T <= 1000) {
        vector<int> prefix = myLIS(getArray(a,n,T),n*T);
        for(int i = 0; i < n*T; i++) {
            ret = max(ret,prefix[i]);
        }

    }else{
        vector<int> newA = getArray(a,n,n);
        vector<int> prefix = myLIS(newA,n*n);
        for(int i = 0; i < newA.size(); i++) {
            newA[i] = -newA[i];
        }
        reverse(newA.begin(),newA.end());
        vector<int> suffix = myLIS(newA,n*n);
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) if(a[i]==a[j]) cnt++;
            for(int j = 0; j < n; j++) {
                if(a[j] < a[i]) continue;
                ret = max(ret,prefix[(n-1)*n+i]+cnt*(T-2*n)+suffix[n*n-j-1]);
            }
        }
    }

    cout<<ret<<endl;
    return 0;
}
