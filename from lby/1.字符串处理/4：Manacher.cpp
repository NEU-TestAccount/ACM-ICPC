给定一个长度不超过110000的字符串T，求它的最长回文子串。其时间复杂度为O(n)
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N=200005<<1;

char T[N];   //原字符串
char S[N];   //转换后的字符串
int  R[N];   //回文半径

void Init(char *T)
{
    S[0]='$';
    int len=strlen(T);
    for(int i=0; i<=len; i++)
    {
        S[2*i+1]='#';
        S[2*i+2]=T[i];
    }
}

void Manacher(char *S)
{
    int k=0,mx=0;
    int len=strlen(S);
    for(int i=0; i<len; i++)
    {
        if(mx>i)
            R[i]=R[2*k-i]<mx-i? R[2*k-i] : mx-i;
        else
            R[i]=1;
        while(S[i+R[i]]==S[i-R[i]])
            R[i]++;
        if(R[i]+i>mx)
        {
            mx=R[i]+i;
            k=i;
        }
    }
}

int main()
{
    while(~scanf("%s", T))
    {
        Init(T);
        Manacher(S);
        int len=strlen(S);
        int ans=1;
        for(int i=0; i<len; i++)
            ans=R[i]>ans? R[i] : ans;
        printf("%d\n", ans-1);
    }
    return 0;
}