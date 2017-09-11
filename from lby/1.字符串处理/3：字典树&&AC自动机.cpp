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
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
struct node
{
    int nxt[26];
    int idx,sum,fl;
}a[15000000];
int tot;
void clr(int i)
{
    clc(a[i].nxt,-1);
    a[i].idx=i;
    a[i].sum=0;
    a[i].fl=-1;
}
void init()
{
    clr(0);
    tot=0;
}
void add(char *c,int len)
{
    int s=0,i,x;
    for(i=0;i<len;i++)
    {
        x=c[i]-'a';
        if(a[s].nxt[x]==-1)
        {
            tot++;
            clr(tot);
            a[s].nxt[x]=tot;
        }
        s=a[s].nxt[x];
    }
    a[s].sum++;
}
void build()
{
    int i,s,t;
    queue<int>q;
    while(!q.empty())q.pop();
    q.push(0);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<26;i++)
        if(a[s].nxt[i]!=-1)
        {
            if(s==0)
                a[a[s].nxt[i]].fl=0;
            else
            {
                t=a[s].fl;
                while(t!=-1)
                {
                    if(a[t].nxt[i]!=-1)
                    {
                        a[a[s].nxt[i]].fl=a[t].nxt[i];
                        break;
                    }
                    t=a[t].fl;
                }
                if(t==-1)
                    a[a[s].nxt[i]].fl=0;
            }
            q.push(a[s].nxt[i]);
        }
    }
}
int ac(char *c,int len)
{
    int s=0,t,i,x,cnt=0;
    for(i=0;i<len;i++)
    {//printf("=%d",s);
        x=c[i]-'a';//printf(" %c ",c[i]);
        while(a[s].nxt[x]==-1&&s)s=a[s].fl;//printf(" %d=",s);
        s=a[s].nxt[x];
        t=s;
        while(t>0)
        {//printf("%d ",t);
            if(a[t].sum>=0)
            {
                cnt+=a[t].sum;
                a[t].sum=-1;
            }else
                break;
            t=a[t].fl;
        }//printf("\n");
    }
    return cnt;
}
char c[105],ch[10000005];
int main()
{
    int tt,n,m,i,j,k,s,t;
    scanf("%d",&tt);
    while(tt--)
    {
        init();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",c);
            add(c,strlen(c));
        }
        build();
        /*for(i=0;i<=10;i++)
        {
            for(j=0;j<26;j++)printf("%c-%d ",j+97,a[i].nxt[j]);
            printf("\n");
        }
        for(i=0;i<=10;i++)
            printf("%d %d\n",a[i].fl,a[i].sum);*/
        scanf("%s",ch);
        printf("%d\n",ac(ch,strlen(ch)));
    }
    return 0;
}
