#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110000],b[110000][20],c[110000][20];
int main()
{
    int n,m,i,j,k,s,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    memset(b,0,sizeof(b));memset(c,0,sizeof(c));
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++){b[i][0]=a[i];c[i][0]=a[i];}
    for(i=1;(1<<i)<=n;i++)
        for(j=1;j-1+(1<<i)<=n;j++)
        {
            b[j][i]=max(b[j][i-1],b[j+(1<<(i-1))][i-1]);
            c[j][i]=min(c[j][i-1],c[j+(1<<(i-1))][i-1]);
        }
   // for(i=0;i<=5;i++){for(j=1;j<=n;j++)printf("%d ",b[j][i]);printf("\n");}
    k=0;while((1<<(k+1))<=m)k++;//printf("%d\n",k);
    printf("%d",min(c[1][k],c[1+m-(1<<k)][k]));
    for(i=2;i<=n-m+1;i++)printf(" %d",min(c[i][k],c[i+m-(1<<k)][k]));printf("\n");
    printf("%d",max(b[1][k],b[1+m-(1<<k)][k]));
    for(i=2;i<=n-m+1;i++)printf(" %d",max(b[i][k],b[i+m-(1<<k)][k]));printf("\n");
    }
    return 0;
}
