#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define clc(a,b) memset(a,b,sizeof(a))
#define MAXN 200010
#define INF 0x3f3f3f3f
typedef long long LL;
struct mcmf{
    int n,m;
    struct Edge{
        int from, to, cap, flow, cost;
        Edge(int a, int b, int c, int d, int e){
            from = a, to = b, cap = c, flow = d, cost = e;
        }
    };
    vector<Edge> edge;
    vector<int> g[MAXN];
    bool inq[MAXN];
    int d[MAXN]/*spfa*/, p[MAXN]/*上一条弧*/, a[MAXN]/*可改进量*/;
    void init(int n){
        this->n = n;
        repe(i,1,n) g[i].clear();
        edge.clear();
    }
    void add_edge(int from, int to, int cap, int cost)
    {
        edge.push_back(Edge(from,to,cap,0,cost));
        edge.push_back(Edge(to,from,0,0,-cost));
        m = edge.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool spfa(int s, int t, int& flow, LL& cost)
    {
        clc(d,0x3f);
        clc(inq,0);
        d[s] = 0, inq[s] = true, p[s] = 0, a[s] = INF;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();q.pop();
            inq[u] = false;
            int sz = g[u].size();
            rep(i,0,sz)
            {
                Edge& e = edge[g[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u]+e.cost)
                {
                    d[e.to] = d[u]+e.cost;
                    p[e.to] = g[u][i];
                    a[e.to] = min(a[u], e.cap-e.flow);
                    if(!inq[e.to]) q.push(e.to), inq[e.to] = true;
                }
            }
        }
        if(INF == d[t]) return false;
        flow += a[t];
        cost += (LL)d[t]*(LL)a[t];
        for(int u = t; u != s; u = edge[p[u]].from)
        {
            edge[p[u]].flow += a[t];
            edge[p[u]^1].flow -= a[t];
        }
        return true;
    }
    //需要保证初始网络没有负圈，返回最大流量，cost才是最小花费
    int mincostmaxflow(int s, int t, LL & cost)
    {
        int flow = 0;
        cost = 0;
        while(spfa(s,t,flow,cost));
        return flow;
    }
}mcmf;
char a[105][105];
int n,m;
int z(int i,int j){return ((i-1)*m+j);}
int main()
{
    int i,j,k,s,t;
while(scanf("%d%d",&n,&m)!=EOF)
{
    if(n==0&&m==0)break;
    getchar();
    for(i=1;i<=n;i++)
        scanf("%s",a[i]);
    mcmf.init(n*m+2);
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            for(j=1;j<=m-1;j++)
                mcmf.add_edge(z(i,j),z(i,j+1),100,1);
            for(j=2;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i,j-1),100,1);
            for(j=1;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i+1,j),100,1);
        }else
        if(i==n)
        {
            for(j=1;j<=m-1;j++)
                mcmf.add_edge(z(i,j),z(i,j+1),100,1);
            for(j=2;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i,j-1),100,1);
            for(j=1;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i-1,j),100,1);
        }else
        {
            for(j=1;j<=m-1;j++)
                mcmf.add_edge(z(i,j),z(i,j+1),100,1);
            for(j=2;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i,j-1),100,1);
            for(j=1;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i+1,j),100,1);
            for(j=1;j<=m;j++)
                mcmf.add_edge(z(i,j),z(i-1,j),100,1);
        }
    }//for(i=1;i<=n;i++){for(j=0;j<=m-1;j++)printf("%c",a[i][j]);printf("\n");}
    for(i=1;i<=n;i++)
        for(j=0;j<=m-1;j++)
        {
            if(a[i][j]=='m')
                mcmf.add_edge(n*m+1,z(i,j+1),1,0);
            if(a[i][j]=='H')
                mcmf.add_edge(z(i,j+1),n*m+2,1,0);
        }
    LL ans;
    mcmf.mincostmaxflow(n*m+1,n*m+2,ans);
    printf("%I64d\n",ans);
}
    return 0;
}
