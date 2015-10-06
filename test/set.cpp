#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <set>
#include <functional>
using namespace std;
int main()
{
	char test;
	set<int> mapy;
	pair<set<int>::iterator,bool> ret;
	for (int i = 10; i > 0 ; --i)
	{
		ret=mapy.insert(i);
	}
	ret=mapy.insert(11);
	if(ret.second==false) printf("unsuccessful because 7 is already there\n");
	for (set<int>::iterator it=mapy.begin(); it!=mapy.end(); ++it)
	{
		cout << *it << " ";
	}
}
