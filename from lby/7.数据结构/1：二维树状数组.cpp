#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1040
#define ll long long
using namespace std;
int n,tree[N][N];
int sum(int i,int j)
{
    int s=0;
    while(i>0) {
        int jj=j;
        while(jj>0) {
            s+=tree[i][jj];
            jj-=jj&-jj;
        }
        i-=i&-i;
    }
    return s;
}
void add(int i,int j,int x) {
    while(i<=n) {
        int jj=j;
        while(jj<=n) {
            tree[i][jj]+=x;
            jj+=jj&-jj;
        }
        i+=i&-i;
    }
}
int main()
{
    char sign[5];
    int m,l,r,x,i,tt,x1,y1,x2,y2,j,k,s,t,y,cnt=1;
    scanf("%d",&tt);
    while(tt--)
    {
        if(cnt==1)cnt=0;else printf("\n");
        memset(tree,0,sizeof(tree));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%s",sign);
            if(sign[0]=='C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x1,y2+1,-1);
                add(x2+1,y1,-1);
                add(x2+1,y2+1,1);
            }
            else
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(x,y)%2);
            }
        }
    }
    return 0;
}
