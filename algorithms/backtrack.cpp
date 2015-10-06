#include <bits/stdc++.h>

using namespace std;

string A,out;
int siz,cnt;

void backtrack(int l,int r,int tofill) {
	bool tmp[30];
	for (int i = 0; i <= 26; ++i) tmp[i] = false;
	if(tofill == 1) {
		for (int i = l; i <= r; ++i) {
			if(tmp[A[i]-'a'] == true) continue;
			out += A[i];
			tmp[A[i]-'a'] = true;
			cout << cnt + 1 << " " << out << endl;
			out.pop_back();
			cnt++;
		}
	}
	else {
		for (int i = l; i <= r; ++i) {
			if(tmp[A[i]-'a'] == true) continue;
			out += A[i];
			tmp[A[i]-'a'] = true;
			swap(A[l],A[i]);
			backtrack(l+1,r,tofill-1);
			out.pop_back();
			swap(A[i],A[l]);
		}
	}
	return;
}

// main code begins now

int main()
{
    cin >> A;
    printf("enter the size of permutations\n");
    cin >> siz;
    backtrack(0,A.size()-1,siz);
    return 0;
}