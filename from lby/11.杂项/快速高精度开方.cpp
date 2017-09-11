#include <cstdio>
#include <cstring>
int l;
int mian(int o,char *O,int I)
 {
    char c,*D=O;
    if(o>0) {
                for(l=0;D[l];D[l++]-=10)
                    {
                        D[l++]-=120;D[l]-=110;
                        while(!mian(0,O,l))D[l]+=20;
                        putchar((D[l]+1032)/20);
                    }
                    putchar(10);
                }
        else{
                c=o+(D[I]+82)%10-(I>l/2)*(D[I-l+I]+72)/10-9;
                D[I]+=I<0?0:!(o=mian(c/10,O,I-1))*((c+999)%10-(D[I]+92)%10);
            }
            return o;
}
int main()
{
    char s[10001]={'0'};
    scanf("%s",s+1);
    if (strlen(s)&1)mian(2,s+1,0);
    else mian(2,s,0); return 0;
}
