#include<cstring>
#include<cstdio>
void getnext(const char *s)
{
    int len=strlen(s);
    int i = 0, j = -1;
    p[0] = -1;
    while(i != len)
    {
        if(j == -1 || s[i] == s[j])
            p[++i] = ++j;
        else
            j = p[j];
    }
}
int main()
{
	char s1[100],s2[100];int p[100],i,j;
	j=-1;p[0]=-1;for(i=1;i<=100;i++)p[i]=-1;
	gets(s1);gets(s2);
	for(i=1;i<strlen(s2);i++)
                 {
		while(j>=0&&s2[j+1]!=s2[i])j=p[j];
		if(s2[i]==s2[j+1])j++;
		p[i]=j;
    	}
	j=-1;
	for(i=0;i<strlen(s1);i++)
    {
		while(j>=0&&s2[j+1]!=s1[i]){j=p[j];}
		if(s1[i]==s2[j+1])j++;
		if(j==strlen(s2)-1){printf("%d",i-j+1);j=p[j];}
	}
	return 0;
}
