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
string A,B,C;
int k;
int sa[maxn*2],t[maxn*2],t2[maxn*2],c[maxn*2],text[maxn*2],len,n;
int Rank[maxn*2],height[maxn*2];
string str;
vi num,cnt;
LL ans;
int lena,lenb;
void getHeight() {
    int k = 0;
    REP(i,0,n-1) Rank[sa[i]] = i;
    REP(i,0,n-1){
        if(k) k--;
        int j = sa[Rank[i]-1];
        while(text[i+k] == text[j+k]) k++;
        height[Rank[i]] = k;
    }
}

void build_sa(int m) {
    int *x = t, *y = t2;
    REP(i,0,m-1) c[i] = 0;
    REP(i,0,n-1) c[x[i] = text[i]]++;
    REP(i,1,m-1) c[i] += c[i-1];
    RREP(i,n-1,0) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p = 0;
        REP(i,n-k,n-1) y[p++] = i;
        REP(i,0,n-1) if(sa[i] >= k) y[p++] = sa[i]-k;
        REP(i,0,m-1) c[i] = 0;
        REP(i,0,n-1) c[x[y[i]]]++;
        REP(i,1,m-1) c[i] += c[i-1];
        RREP(i,n-1,0) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        REP(i,1,n-1)
            x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
        if(p >= n) break;
        m = p;
    }
}
void init() {
    len = sz(str);
    ans = 0;
    n = len+1;
    REP(i,0,len-1) {
        text[i] = str[i];
    }
    text[len] = 0;
}
void solve() {
    build_sa(160);
    getHeight();
    LL tmp;
    REP(i,1,n-1) {
        if(height[i] < k) {
            clr(cnt);
            clr(num);
            tmp = 0;
        }else{
            int tc = 0;
            if(sa[i-1] > lena) {//B串
                tc = 1;
                tmp += height[i]-k+1;
            }
            while(sz(num) && num.back() >= height[i]) {
                tmp -= cnt.back()*(num.back()-height[i]);
                tc += cnt.back();
                num.pop_back();
                cnt.pop_back();
            }
            cnt.pb(tc);
            num.pb(height[i]);
            if(sa[i] < lena) {
                ans += tmp;
            }

        }
    }
    REP(i,1,n-1) {
        if(height[i] < k) {
            clr(num);
            clr(cnt);
            tmp = 0;
        }else{
            int tc = 0;
            if(sa[i-1] < lena) { //A串
                tc = 1;
                tmp += height[i]-k+1;
            }
            while(sz(num) && num.back() >= height[i]) {
                tmp -= cnt.back()*(num.back()-height[i]);
                tc += cnt.back();
                num.pop_back();
                cnt.pop_back();
            }
            cnt.pb(tc);
            num.pb(height[i]);
            if(sa[i] > lena) {
                ans += tmp;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(~scanf("%d",&k) && k) {
        cin >> A >> B;
        lena = sz(A);
        lenb = sz(B);
        str = A+"$"+B;
        init();
        solve();
    }

    return 0;
}
