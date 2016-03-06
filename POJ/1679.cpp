#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX 9999999
using namespace std;

const int maxn=100+10;
const int maxm=maxn*maxn/2+10;

struct Edge
{
    int x,y,w;
    int del;//删边
    int equal;//是否存在权值相等的边
    int used;//记录第一次用过的边
}e[maxm];

int father[maxn];
int sum,n,m;
bool first,ok;

void make_set()//初始化
{
    for(int i=1;i<=n;i++)father[i]=i;
}

int find_set(int x)//并查集的查找
{
    if(x!=father[x])
    father[x]=find_set(father[x]);
    return father[x];
}

void union_set(int x,int y,int w,int i)//并查集的并操作
{
    int a=find_set(x);
    int b=find_set(y);
    if(a==b)return ;
    else father[a]=b;
    sum+=w;
    if(first)e[i].used=1;//将选过的边标记
}

bool cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}

int kruscal()//做一次kruscal
{
    make_set();
    sort(e,e+m,cmp);
    sum=0;
    for(int i=0;i<m;i++)
    {
        if(e[i].del==1)continue;//如果该边已删除，不选
        union_set(e[i].x,e[i].y,e[i].w,i);
    }
    return sum;
}

void cal_equal()//判断所给的边中是否存在权值相同的边，并标记
{
    for(int i=0;i<m;i++)
    for(int j=i+1;j<m;j++)
    {
        if(e[i].w==e[j].w)
        e[i].equal=e[j].equal=1;
    }
}

int main()
{
    //freopen("in","r",stdin);
    int t,xx,yy,ww;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)//初始化
        {
            scanf("%d %d %d",&xx,&yy,&ww);
            e[i].x=xx;
            e[i].y=yy;
            e[i].w=ww;
            e[i].del=0;
            e[i].equal=0;
            e[i].used=0;
        }
        cal_equal();//计算
        first=true; //做第一次kruscal

        int weight1=kruscal(),weight2;

        first=ok=false;
 
       //扫描每条边，如果该边在第一次中用过，并且存在于该边权值相同的边，将该边删去，重新做一次kruscal，判断
        for(int i=0;i<m;i++)
        {
            if(e[i].used&&e[i].equal)
            {
                e[i].del=1;
                weight2=kruscal();
                if(weight1==weight2)
                {
                    ok=true;
                    break;
                }
                e[i].del=0;//如果不是，则还原该边
            }
        }
        if(ok)
        printf("Not Unique!\n");
        else printf("%d\n",weight1);
    }
    return 0;
}
