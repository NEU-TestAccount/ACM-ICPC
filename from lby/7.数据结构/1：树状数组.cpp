#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[100000],tree[100000],n;
long long lowbit(long long x){return (x&(-x));}
long long sum(long long y)
{
    long long s=0,t=y;
    while(t>0){s+=tree[t];t-=lowbit(t);}
    return s;
}
void add(long long z,long long c)
{
    long long t=z;
    while(t<=n){tree[t]+=c;t+=lowbit(t);}
}
long long ans(long long l,long long r)
{return sum(r)-sum(l-1);}

int main()
{
    int m,p,q,h,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&p,&q,&h);
        if(p==1)add(q,h);
        else printf("%lld\n",ans(q,h));
    }
    return 0;
}
