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
    char test;
	map<char,int> mapy;
	for (int i = 0; i < 10; ++i)
	{
		cout << "enter the character" << endl ;
		cin >> test ;
		mapy[test]=i;
	}
	for (map<char,int>::iterator it=mapy.begin(); it!=mapy.end(); ++it)
	{
		cout << it->first << "=>" << it->second << endl ;
	}
	map<char,int>::iterator it=mapy.begin();
	printf("after modifying the values:\n");
	for (int i = 10; it!=mapy.end(); ++i,++it)
	{
		(*it).second=i;
	}
	for (map<char,int>::iterator it=mapy.begin(); it!=mapy.end(); ++it)
	{
		cout << it->first << "=>" << it->second << endl ;
	}
    return 0;
}
