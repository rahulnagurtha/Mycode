#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define MOD 1000000009LL
#define rem(a,b) ((a%b+b)%b)

string A,B; //searching for B in A

ll expo[100005],coeff,hashB,curval;

void init() {
	coeff = 131;
	expo[0] = 1;
	for (int i = 1; i < 100003; ++i)  {
		expo[i] = expo[i-1]*coeff;
		expo[i] %= MOD;
	}
	return;
}

ll gethash(string one) {
	ll ret = 0;
	for (int i = one.size()-1; i >= 0; --i) {
		ret += expo[one.size()-1-i]*((ll)one[i]);
		ret %= MOD;
	}
	return ret;
}

void preprocess() {
	hashB = gethash(B);
	curval = 0;
	for (int i = B.size()-1; i >= 0 ; --i) {
		curval += expo[B.size()-1-i]*((ll)A[i]);
		curval %= MOD;
	}
	return;
}

void window() {
	if(curval == hashB) printf("0\n");
	for (int i = B.size(); i < A.size(); ++i) {
		curval = (rem((curval - rem(expo[B.size()-1]*((ll)A[i-B.size()]),MOD))*coeff,MOD)+A[i])%MOD;
		if(curval == hashB) {
			printf("%d\n",i-B.size()+1);
			return;
		}
	}
	printf("-1\n");
	return;
}

// main code begins now

int main()
{
    cin >> A ;
    cin >> B ;
    //
    //write the corner cases here
    //
    init();
    preprocess();
    window();
    return 0;
}