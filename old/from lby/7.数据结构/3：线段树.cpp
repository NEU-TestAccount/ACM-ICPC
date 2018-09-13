#include<cstdio>
long long sum[1000000],lazy[1000000];
int ll,rr,xx;
void build(int pl,int pr,int x)
{
    if(pl==pr)scanf("%lld",&sum[x]);
    else
    {
        int mid=(pl+pr)/2;
        build(pl,mid,2*x);
        build(mid+1,pr,2*x+1);
        sum[x]=sum[2*x]+sum[2*x+1];
    }
}
void pushdown(int pl,int pr,int x)
{
    int m=(pl+pr)/2;
    lazy[2*x]+=lazy[x];lazy[2*x+1]+=lazy[x];
    sum[2*x+1]+=lazy[x]*(pr-m);
    sum[2*x]+=lazy[x]*(m-pl+1);
    lazy[x]=0;
}
void change(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)
    {
        lazy[x]+=xx;sum[x]+=xx*(pr-pl+1);
    }
    else
    {
        pushdown(pl,pr,x);
        int m=(pl+pr)/2;
        if(ll<=m)change(pl,m,2*x);
        if(rr>=m+1)change(m+1,pr,2*x+1);
        sum[x]=sum[2*x]+sum[2*x+1];
    }
}
long long findsum(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)return(sum[x]);
    else
    {
        int m=(pl+pr)/2;long long ans=0;
        if(lazy[x]!=0)pushdown(pl,pr,x);
        if(ll<=m)ans+=findsum(pl,m,2*x);
        if(rr>=m+1)ans+=findsum(m+1,pr,2*x+1);
        return ans;
    }
}
int main()
{
    int n,m,i,j,k;
    scanf("%d",&n);
    build(1,n,1);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        if(k==1){scanf("%d%d%d",&ll,&rr,&xx);change(1,n,1);}
        else{scanf("%d%d",&ll,&rr);printf("%lld\n",findsum(1,n,1));}
    }
    return 0;
}
