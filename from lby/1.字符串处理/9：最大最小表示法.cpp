int get_minstring(char *s)  
{  
    int len = strlen(s);  
    int i = 0, j = 1, k = 0;  
    while(i<len && j<len && k<len)  
    {  
        int t=s[(i+k)%len]-s[(j+k)%len];  
        if(t==0)  
            k++;  
        else  
        {  
            if(t > 0)  
                i+=k+1;  
            else  
                j+=k+1;  
            if(i==j) j++;  
            k=0;  
        }  
    }  
    return min(i,j);  
}  
  
//最大表示法  
int get_maxstring(char *s)  
{  
    int len = strlen(s);  
    int i = 0, j = 1, k = 0;  
    while(i<len && j<len && k<len)  
    {  
        int t=s[(i+k)%len]-s[(j+k)%len];  
        if(t==0)  
            k++;  
        else  
        {  
            if(t > 0)  
                j+=k+1;  
            else  
                i+=k+1;  
            if(i==j) j++;  
            k=0;  
        }  
    }  
    return min(i,j);  
}  