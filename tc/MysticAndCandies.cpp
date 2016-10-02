#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,temp;
	vector<int> A;	// A is an empty vector
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << " ";
	}
	return 0;
}