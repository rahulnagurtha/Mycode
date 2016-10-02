#include <stdio.h>
#include <stdlib.h>
 
int is_subset_sum(unsigned long long a[], int n, unsigned long long sum)
{
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;
    
    if (a[n-1] > sum || a[n-1] == 0)
        return is_subset_sum(a, n-1, sum);
    
    if (is_subset_sum(a, n-1, sum-a[n-1]))
    {
        a[n-1] = 0;
        return 1;
    }
    return is_subset_sum(a, n-1, sum);
}
 
int main(int argc, const char* argv[])
{
    int t, n, i, k, f, j;
    unsigned long long a[101];
    unsigned long long s, avg;
    
   freopen("in.txt", "r", stdin);
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &k);
        
        s = f = 0;
        for (i = 0; i < n; ++i) {
            scanf("%llu", &a[i]);
            s = s + (unsigned long long)a[i];
        }
        
        if (k <= n && s % k == 0)
        {
            avg = s/k;
            
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n - 1 - i; ++j)
                {
                    if (a[j] > a[j+1])
                    {
                        s = a[j];
                        a[j] = a[j+1];
                        a[j+1] = s;
                    }
                }
            }
            
            if (a[n-1] <= avg)
            {
                f = 1;
                for (i = 0; i < k; ++i)
                {
                    if (!is_subset_sum(a, n, avg))
                    {
                        f = 0;
                        break;
                    }
                }
            }
        }
        
        if (f)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    
    return 0;
} 