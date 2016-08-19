vector<int> Solution::maxone(vector<int> &arr, int m) {
    
    
    int n=arr.size();
    
    int wL = 0, wR = 0; 
 
   
    int bestL = 0, bestWindow = 0; 
 
  
    int zeroCount = 0; 
 
   
    while (wR < n)
    {
        if (zeroCount <= m)
        {
            if (arr[wR] == 0)
              zeroCount++;
            wR++;
        }
 
       
        if (zeroCount > m)
        {
            if (arr[wL] == 0)
              zeroCount--;
            wL++;
        }
 
       
        if (wR-wL > bestWindow)
        {
            bestWindow = wR-wL;
            bestL = wL;
        }
    }
 
    
    if(m==0)
    {vector<int> ans;int count;int final=-1;int finalstart=-1;
        int start=0;int end=0;
    while(start<n)
    {   count=0;
        while(start<n&&arr[start]!=1)
            start++;
        if(start==n)
            break;
        end = start; 
        count = 0;
        while(end<n && arr[end]==1) {   
            count++;
            end++;
        }
        if(count>final)
        {finalstart=start;final=count;
         
        }
        
        
        start=end;
        
    }
  
     if(finalstart!=-1)
     {
         for(int i=finalstart;i<finalstart+final;i++)
     ans.push_back(i);
     
     }
      return ans;  
    }
    int start=-1;int end=n;
    
    for (int i=0; i<bestWindow; i++)
    {
        if (arr[bestL+i] == 0)
           {if(start==-1)
           start=bestL+i;
           end=bestL+i;
               
           }
    }
    if(start!=-1)
    arr[start]=1;
    while(start>=0 &&arr[start]==1)
    start--;
    if(end<n)
    arr[end]=1;
    while(end<n&& arr[end]==1)
    end++;
    
    vector<int> ans;
    for(int i=start+1;i<end;i++)
    ans.push_back(i);
    
    return ans;
    
}