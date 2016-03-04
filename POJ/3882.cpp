#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define MP make_pair
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

const int maxn = 44000;
const int INF = 0x3f3f3f3f;

struct SuffixArray
{
    int s[maxn];      // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
    int sa[maxn];     // 后缀数组
    int rank[maxn];   // 名次数组. rank[0]一定是n-1，即最后一个字符
    int height[maxn]; // height数组
    int t[maxn], t2[maxn], c[maxn]; // 辅助数组
    int n; // 字符个数

    void clear()
    {
        n = 0;
        memset(sa, 0, sizeof(sa));
    }

    // m为最大字符值加1。调用之前需设置好s和n
    void build_sa(int m)
    {
        int i, *x = t, *y = t2;
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(i = 1; i < m; i++) c[i] += c[i-1];
        for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1)
        {
            int p = 0;
            for(i = n-k; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;

            for(i = 0; i < m; i++) c[i] = 0;
            for(i = 0; i < n; i++) c[x[y[i]]]++;
            for(i = 1; i < m; i++) c[i] += c[i-1];
            for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for(i = 1; i < n; i++)
                x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
            if(p >= n) break;
            m = p;
        }
    }

    void build_height()
    {
        int i, j, k = 0;
        for(i = 0; i < n; i++) rank[sa[i]] = i;
        for(i = 0; i < n; i++)
        {
            if(k) k--;
            int j = sa[rank[i]-1];
            while(s[i+k] == s[j+k]) k++;
            height[rank[i]] = k;
        }
    }
};

SuffixArray sa;
char ch[maxn];

int check(int mid,int m)
{
    int ret = -1, cnt = 0, tmp = -1;
    for(int i = 1; i < sa.n; i ++)
    {
        if(sa.height[i] < mid) cnt = 1, tmp = sa.sa[i];
        else cnt ++, tmp = max(tmp, sa.sa[i]);
        if(cnt >= m) ret = max(ret, tmp);
    }
    return ret;
}

void debug()
{
    for(int i = 1; i < sa.n ; i ++)
    {
        printf("%d ", sa.sa[i]);
        printf("%d\n", sa.height[i]);
    }puts("");
}

int main()
{
    int m;
    while(scanf("%d", &m), m)
    {
        scanf("%s", ch);
        int len = strlen(ch);
        sa.clear();
        sa.n = len + 1;
        if(m == 1)
        {
            printf("%d 0\n", len);
            continue;
        }
        for(int i = 0; i < len; i ++)
        {
            sa.s[i] = ch[i] - 'a' + 1;
        }
        sa.s[len] = 0;
        sa.build_sa(30);
        sa.build_height();
//        debug();
        int l = 1, r = len, ans;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            int tmp = check(mid, m);
            if(tmp != -1) l = mid + 1, ans = tmp;
            else r = mid - 1;
        }
        if(r >= 1) printf("%d %d\n", r, ans);
        else puts("none");
    }
}
