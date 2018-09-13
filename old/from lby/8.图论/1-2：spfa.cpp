#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define maxn 100
#define INF 1000000000
using namespace std;
vector<int>a[maxn+5],b[maxn+5];
long long p[maxn+5];
int flag[maxn+5];
int n,m;
queue<int>q;
int init()
{
    int i,u,v,w;
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++)
    {
        a[i].clear();
        b[i].clear();
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(v);
        b[u].push_back(w);
        a[v].push_back(u);
        b[v].push_back(w);
    }
}
void spfa(int px)
{
    int i,k,s;
    memset(flag,0,sizeof(flag));
    for(i=0;i<=n;i++)p[i]=INF;
    while(!q.empty())q.pop();
    flag[px]=1;q.push(px);p[px]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        flag[s]=0;
        for(i=0;i<a[s].size();i++)
            if(p[a[s][i]]>p[s]+b[s][i])
            {
                p[a[s][i]]=p[s]+b[s][i];
                if(!flag[a[s][i]])
                {
                    flag[a[s][i]]=1;
                    q.push(a[s][i]);
                }
            }
    }
}
int main()
{
    int tt,m,i,j,k,s,t;
    long long ans,sum;
    scanf("%d",&tt);
    while(tt--)
    {
        init();
        spfa(0);//for(i=1;i<=n;i++)printf("==%I64d\n",p[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);

    return 0;
}