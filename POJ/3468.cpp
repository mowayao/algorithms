//Code here
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1111110;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
long long  sum[maxn<<2];
long long col[maxn<<2];
void PushDown(int rt, int len)
{
    col[rt<<1|1] += col[rt];
    col[rt<<1] += col[rt];
    sum[rt<<1] += (len-(len>>1))*col[rt];
    sum[rt<<1|1] += (len>>1)*col[rt];
    col[rt] = 0;
}
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l, int r, int rt)
{
    col[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void Update(int L, int R, int num, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        col[rt] += num;
        sum[rt] += (long long)num*(r-l+1);
        return ;
    }

    if (col[rt] != 0)
    PushDown(rt, r-l+1);

    int m = (l+r)>>1;
    if (L<=m)
    Update(L, R, num, lson);
    if (R>m)
    Update(L, R, num, rson);

    PushUp(rt);
}
long long  Query(int L, int R, int l ,int r, int rt)
{

    if (col[rt] != 0)
    PushDown(rt, r-l+1);

    if (L<=l && r<=R)
    {
        return sum[rt];
    }

    int m = (l+r)>>1;

    long long ans = 0;

    if (L<=m)
    ans += Query(L, R, lson);
    if (R>m)
    ans += Query(L, R, rson);

    return ans;
}
int main()
{
    int N, Q, a, b, c;
    char op[5];
    //freopen("1.txt", "w", stdout);
    scanf("%d%d", &N, &Q);
    build(1, N, 1);
   // cout<<"AAAAAAAAA"<<endl;
    while (Q--)
    {
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            scanf("%d%d", &a, &b);
            printf("%lld\n", Query(a, b, 1, N, 1));
        }
        else if (op[0] == 'C')
        {
            scanf("%d%d",&a, &b);
            scanf("%d", &c);
            Update(a, b, c, 1, N, 1);
        }
    }
 return 0;
 }