 while(low<=up)  
    {  
    mid=(low+up)/2;  
    if(ans[mid]<num[i]) low=mid+1;  
    else up=mid-1;  
    }  