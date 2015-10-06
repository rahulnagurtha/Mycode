#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <map>
//#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <functional>

using namespace std;
int main()
{
	vector <int> test;
	test.push_back(10);
	test.push_back(11);
	test.push_back(12);
	vector<int>::iterator itr1=test.begin();
	vector<int>::iterator itr2=test.end();
	for (vector<int>::iterator itr = itr1; itr!=itr2; ++itr)
	{
		cout << *itr << endl;
	}

}
