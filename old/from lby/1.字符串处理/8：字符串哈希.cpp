//题目：匹配前后缀
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include <queue>
#include <vector>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define clc(a,b) memset(a,b,sizeof(a))
#define MAXN 2010
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
char a[100005];
char trans[300],tra[300];
unsigned long long pre[100005],suf[100005],pw[100005];
int main()
{
    int n,m,i,j,k,s,tt,ans;
    unsigned long long t;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%s",trans);
        for(i=0;i<26;i++)tra[trans[i]]=i;
        scanf("%s",a);
        n=strlen(a);
        pw[0]=1;
        for(i=1;i<100005;i++)pw[i]=pw[i-1]*37LL;
        t=0;
        for(i=0;i<n;i++)
        {
            t=t*37+a[i]-96;
            pre[i]=t;
        }
        t=0;
        for(i=n-1;i>=0;i--)
        {
            t=t+pw[n-1-i]*(trans[a[i]-97]-96);
            suf[i]=t;
        }//for(i=0;i<n;i++)printf("%lld %lld\n",pre[i],suf[i]);
        ans=n;
        for(i=n/2-1;i>=0;i--)
        if(pre[i]==suf[n-1-i])
        {
            ans=n-1-i;
            break;
        }//printf("%d\n",ans);
        for(i=0;i<ans;i++)printf("%c",a[i]);
        for(i=0;i<ans;i++)printf("%c",tra[a[i]]+97);
        printf("\n");
    }
    return 0;
}
