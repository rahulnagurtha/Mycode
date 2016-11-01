#include <bits/stdc++.h>

using namespace std;


#define mp make_pair

map<pair<int,pair<int,pair<int,int> > >,bool> dp;

bool recurse(int l1,int r1,int l2,int r2,string A,string B) {
	cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
	if(dp.find(mp(l1,mp(r1,mp(l2,r2)))) != dp.end()) return dp[mp(l1,mp(r1,mp(l2,r2)))];
	if(l1 == r1) return (A[l1] == B[l2]);
	bool retval = false;
	for (int i = l1,j = l2; i < r1; ++i,++j) {
		if(retval) break;
		retval = recurse(l1,i,l2,j,A,B) && recurse(i+1,r1,j+1,r2,A,B);
	}
	for (int i = l1,j = r2; i < r1; ++i,--j) {
		if(retval) break;
		retval = recurse(l1,i,j,r2,A,B) && recurse(i+1,r1,l2,j-1,A,B);
	}
	dp[mp(l1,mp(r1,mp(l2,r2)))] = retval;
}

int isScramble(const string A, const string B) {
    dp.clear();
    return recurse(0,A.size()-1,0,B.size()-1,A,B);
}


int main()
{
    string A = "we";
    string B = "we";
    cout << isScramble(A,B) << endl;
    return 0;
}