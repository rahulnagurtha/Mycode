#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;


// fast input

#ifndef ONLINE_JUDGE //  ifndef checks whether this macro is defined earlier or not
#define gc getchar //for local PC
#else
#define gc getchar_unlocked //for online judge environments
#endif
int readint()
{
register char c=gc();
while(c<'0'||c>'9')
    c=gc();  //ignore all characters till the first digit
int ret=0;
while(c>='0' && c<='9') //till we get a stream of digits.As soon as we get something else,we stop
{
ret=ret*10+(c-48);//construct the number
c=gc();
}
return ret;
}


// main code begins now

int main()
{
    int test;
    queue<int> one;
    printf("enter the numbers\n");
    for (int i = 0; i < 10; ++i)
    {
    	one.push(readint());
    }
    queue<int>two(one);
    //printf("the front element is %d\n",one.front());
    printf("the first element is %d\n",one.front());
    printf("the size of the stack is %d\n",one.size());
    printf("the numbers are:\n");
    test=one.size();
    for (int i = 0; i < test ; ++i)
    {
    	cout << one.front() << " " ;
    	one.pop();
    }
    printf("the size of stack is %d\n",one.size());
    printf("the second stack is:\n");
    for (int i = 0; i < two.size(); ++i)
    {
    	cout << two.front() << " " ;
    	two.pop();
    }
    return 0;
}
