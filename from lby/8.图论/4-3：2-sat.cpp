#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2005;
const int M = 2000000;
int head[N];
struct edge
{
    int to,next;
}g[M];
bool flag;
int stack1[N];
int stack2[N];
int vis[N];
int scc[N];
int n,m;

void build(int s,int t,int num)
{
    g[num].to = t;
    g[num].next = head[s];
    head[s] = num;
}

void dfs(int cur,int &sig,int &num)
{
    if(!flag)
        return;
    vis[cur] = ++sig;
    stack1[++stack1[0]] = cur;
    stack2[++stack2[0]] = cur;
    for(int i = head[cur];i != -1;i = g[i].next)
    {
        if(!vis[g[i].to])
            dfs(g[i].to,sig,num);
        else
        {
            if(scc[g[i].to] == 0)
            {
                while(vis[stack2[stack2[0]]] > vis[g[i].to])
                    stack2[0] --;
            }
        }
    }
    if(stack2[stack2[0]] == cur)
    {
        ++ num;
        stack2[0] --;
        do
        {
            scc[stack1[stack1[0]]] = num;
            int tmp = stack1[stack1[0]];
            if(tmp > n)
            {
                if(scc[tmp - n] && scc[tmp - n] == num)
                {
                    flag = false;
                    return;
                }
            }
            else
            {
                if(scc[tmp + n] && scc[tmp + n] == num)
                {
                    flag = false;
                    return;
                }
            }
        }while(stack1[stack1[0] --] != cur);
    }
}

void Gabow()
{
    int i,sig,num;
    memset(vis,0,sizeof(vis));
    memset(scc,0,sizeof(scc));
    stack1[0] = stack2[0] = sig = num = 0;
    for(i = 1;i <= n + n && flag;i ++)
        if(!vis[i])
            dfs(i,sig,num);
}

int nextint()
{
    char c;
    int ret;
    while((c = getchar()) > '9' || c < '0')
        ;
    ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    return ret;
}

int main()
{
    int i,j,a,b,c,d;
    while(scanf("%d",&n) != EOF)
    {
        //scanf("%d",&m);
        m = nextint();
        memset(head,-1,sizeof(head));
        for(i = 1;i <= m + m;i += 2)//Ã¿¶ÔÃ¬¶Ü½¨Á½Ìõ±ß
        {
            a = nextint();
            b = nextint();
            c = nextint();
            d = nextint();
            //scanf("%d%d%d%d",&a,&b,&c,&d);//1-n husband   n + 1 - 2n wife
            a ++;
            b ++;
            switch(c + d)
            {
                case 0:build(a + n,b,i);build(b + n,a,i + 1);break;//a+n b+n Ã¬¶Ü
                case 1:if(c)//a  b + nÃ¬¶Ü
                        {
                            build(a,b,i);build(b + n,a + n,i + 1);
                        }
                        else//a + n   bÃ¬¶Ü
                        {
                            build(a + n,b + n,i);build(b,a,i + 1);
                        }break;
                case 2:build(a,b + n,i);build(b,a + n,i + 1);break;
            }
        }
        flag = true;
        Gabow();
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
