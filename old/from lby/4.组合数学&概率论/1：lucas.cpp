#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
const int p=1000000007;

int f[maxn+10];
void init(){//½×³Ë
    f[0]=1;
    for(int i=1;i<=maxn;i++){
        f[i]=(long long)f[i-1]*i%p;
    }
}

int fast(int a,int n){
    if(n==0)return 1;
    if(n%2)return (long long)a*fast(a,n-1)%p;
    int tmp=fast(a,n/2);
    return (long long)tmp*tmp%p;
}

int C(int n,int m){
    if(n==m||m==0)return 1;
    return ((long long)f[n]*fast(f[m],p-2)%p)*fast(f[n-m],p-2)%p;
}

int main(){
    init();
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        printf("%d\n",C(n,m));
    }
    return 0;
}
