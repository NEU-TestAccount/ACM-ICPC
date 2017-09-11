#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int nn;
struct mat{long long a[10][10];};
mat mul(mat a,mat b,long long mod)
{
    mat tt;
    int i,j,k;
    memset(tt.a,0,sizeof(tt.a));
    for(i=0;i<nn;i++)
        for(j=0;j<nn;j++)
            for(k=0;k<nn;k++)
                tt.a[i][j]=(tt.a[i][j]+a.a[i][k]*b.a[k][j]+mod)%mod;
    return tt;
}
mat matpow(mat a,long long b,long long mod)
{
    mat s;
    memset(s.a,0,sizeof(s.a));
    for(int i=0;i<nn;i++)s.a[i][i]=1;
    while(b)
    {
        if(b&1LL)s=mul(s,a,mod);
        a=mul(a,a,mod);
        b=b>>1;
    }
    return s;
}
void output(mat tt)
{
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
            printf("%lld ",tt.a[i][j]);
        printf("\n");
    }
}
int main()
{
    int n,m,tt,q,i,j,k,s,t;
    mat a,b,c,d;
    scanf("%d",&nn);

    return 0;
}
