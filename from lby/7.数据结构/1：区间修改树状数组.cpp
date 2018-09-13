#include <cstdio>
#include <iostream>
#include<algorithm>
#define lowbit(i) (i & (-i))
using namespace std;
const int Nmax = 200100;
int N, Q;
long long delta[Nmax]; // delta的前缀和
long long deltai[Nmax]; // delta * i的前缀和
long long sum[Nmax]; // 原始前缀和
long long Query(long long *array, int pos)
{
    long long temp = 0ll;
    while(pos > 0)
    {
        temp += array[pos];
        pos -= lowbit(pos);
    }
    return temp;
}
void Update(long long *array, int pos, int x)
{
    while(pos <= N)
    {
        array[pos] += x;
        pos += lowbit(pos);
    }
}
int main()
{
    int l,r,x,i,sign;
    long long suml,sumr;
    scanf("%d",&N);
    for(i=1;i<=N;++i)
    {
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&sign);
        if(sign==1) // 修改：把[l, r]区间均加上x
        {
            scanf("%d%d%d",&l,&r,&x);
            Update(delta,l,x);
            Update(delta,r+1,-x);
            Update(deltai,l,x*l);
            Update(deltai,r+1,-x*(r+1));
        }
        else // 查询：[l, r]区间和
        {
            scanf("%d%d",&l,&r);
            suml=sum[l-1]+l*Query(delta,l-1)-Query(deltai,l-1);
            sumr=sum[r]+(r+1)*Query(delta,r)-Query(deltai,r);
            printf("%lld\n",sumr- suml);
        }
    }
    return 0;
}
