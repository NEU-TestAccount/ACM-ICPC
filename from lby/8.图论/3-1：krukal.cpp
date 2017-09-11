#include<cstdio>
#include<cstring>
int a[20000][3],p[105];
void qsort(int l,int r)
{
    int t,x=l,y=r,m=a[(x+y)/2][0];
    while(x<=y)
    {
        while(a[x][0]<m)x++;
        while(a[y][0]>m)y--;
        if(x<=y)
        {
           t=a[x][0];a[x][0]=a[y][0];a[y][0]=t;
           t=a[x][1];a[x][1]=a[y][1];a[y][1]=t;
           t=a[x][2];a[x][2]=a[y][2];a[y][2]=t;
           x++;y--;
        }
    }
    if(x<r)qsort(x,r);
    if(l<y)qsort(l,y);
}
int fin(int x)
{
    if(p[x]!=x)p[x]=fin(p[x]);
    return p[x];
}
int unio(int x,int y)
{
    int xx=fin(x),yy=fin(y);
    if(xx!=yy)p[xx]=yy;
}
int main()
{
    int sum,n,i,j,k,s,t;
    long long ans;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++)p[i]=i;t=0;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++){scanf("%d",&s);if(i!=j){t++;a[t][0]=s;a[t][1]=i;a[t][2]=j;}}
    qsort(1,t);
    sum=0;i=0;ans=0;
    while(sum<n-1)
    {
        i++;
        if(fin(p[a[i][1]])!=fin(p[a[i][2]]))
        {
            unio(a[i][1],a[i][2]);
            sum++;ans+=a[i][0];
        }
    }
    printf("%lld",ans);
    return 0;
}
