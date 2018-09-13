#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define N 1000005
#define lowbit(i) (i & (-i))
using namespace std;
struct node
{
    int l,r,id;
} a[N];
int n,c[N],x,y;
int cmp(node a,node b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    return a.r<b.r;
}
int sum(int x)
{
    int ret = 0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x,int d)
{
    while(x<=y)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
LL ans;
int main()
{
    int i,j,k,l,r,t,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x,&y,&n);
        memset(c,0,sizeof(c));
        for(i = 1; i<=n; i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a+1,a+1+n,cmp);
        ans = 0;
        for(i = 1; i<=n; i++)
        {
            add(a[i].r,1);
            ans+=sum(y)-sum(a[i].r);
        }
        printf("Test case %d: %lld\n",cas++,ans);
    }
    return 0;
}

