#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;
 
#define INF -7777
 
typedef long long int lli;
typedef unsigned long long int ulli;
 
#define box(a,b) ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) (a-(box(a,b))*b)
#define ceil(a,b) ((a%b==0)?(a/b):(a/b+1))
#define abs(a) ((a>=0?a:-a))
#define loop(s,l,i) for(i=s;i<l;i++)
// main code begins now

int main()
{
    int test;
    cin >> test ;
    while(test--)
    {
        int ocount[405],status[205],rush=0,temp1,temp2;
        long long int c_count=0;
        int order[405];
        for (int i = 0; i < 405; ++i)
        {
            ocount[i]=0;
        }
        for (int i = 0; i < 205; ++i)
        {
            status[i]=-1;
        }
        int N,M,temp;
        cin >> N ;
        cin >> M ;
        order[0]=0;
        for (int i = 1; i <= M; ++i)
        {
            cin >> temp ;
            order[i]=temp;
            ocount[temp]++;
        }
        int max,maxpr,flag;
        for (int i=1 ; i<=M ; i++ )
        {
            flag=1;
            temp=order[i];
            if(rush<N)
            {
                if(find(status+1, status+N+1, temp)==status+N+1)
                {
                    status[rush+1]=temp;// printf("%d added to table:%d\n",temp,rush+1);
                    ocount[temp]--;
                    c_count++;
                    rush++;
                }
                else ocount[temp]--;
            }
            else
            {
                //printf("tables are full\n");
                if(find(status+1, status+N+1, temp)!=status+N+1)
                {
                    ocount[temp]--;
                }
                else
                {
                    /////main decision
                    max=i;
                    for (int j = 1; j <=N ; ++j)
                    {
                        if(ocount[status[j]]==0)
                        {
                            status[j]=temp;
                            ocount[order[i]]--;
                            c_count++;
                            flag=0;
                            break;
                        }
                        else
                        {
                            for (int k = i; k <=M ; ++k)
                            {
                                if(order[k]==status[j])
                                    {
                                        maxpr=k;
                                        break;
                                    }
                            }
                            if(max<=maxpr) max=maxpr;
                        }
                    }
                    if(flag==1)
                    {
                        for (int k = 1; k <=N ; ++k)
                        {
                            if(status[k]==order[max])
                            {
                                status[k]=order[i];
                                ocount[order[i]]--;
                                c_count++;
                                break;
                            }
                        }
                    }

                    /////decision complete
                }
            }
        }
        printf("%lld\n",c_count);
    }
    return 0;
}







