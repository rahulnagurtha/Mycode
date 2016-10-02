#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 143548849365049LL
#define rem(a,b) ((a%b+b)%b)

char A[1505];
ll expo[1505],prime,K,llen;
set<ll> hvalues;
bool status[30]; // 1 if good
std::pair<std::set<int>::iterator,bool> retval;

void init() {
	prime = 37;
	expo[0] = 1;
	for (int i = 1; i < 1503; ++i) {
		expo[i] = expo[i-1]*prime;
		expo[i] %= mod;
	}
	return;
}


ll gethash(int l,int r) {
	int len = l - r + 1;
	ll send = 0;
	for (int i = r; i >= l; --i) {
		send += ((ll)(A[i]-'a'+1))*expo[r-i];
		send %= mod;
	}
	return send;
}


void rabinkarp() {
	int bad;
	ll window;
	llen = strlen(A);
	for (int i = 1; i <= llen; ++i) {
		//preprocess from 0 to i-1 i.e 
		//find if the string is suitable and maintain the hashvalue 
		//and then keep moving forward
		bad = 0;
		for (int j = i-1; j >= 0; --j) if(!status[A[j]-'a']) bad++;
		window = gethash(0,i-1);
		if(bad <= K) hvalues.insert(window);
		for (int j = i; j < llen; ++j) {
			if(!status[A[j]-'a']) bad++;
			if(!status[A[j-i]-'a']) bad--;
			window = ((rem(window - rem(((ll)(A[j-i]-'a'+1))*expo[i-1],mod),mod)*prime)%mod + (ll)( A[j] -'a' + 1))%mod;
			if(bad <= K) hvalues.insert(window);
		}
	}
	return;
}


// main code begins now

int main()
{
	init();
	char tmp;
    scanf("%s",A);
    getchar();
    for (int i = 0; i < 26; ++i) {
    	scanf("%c",&tmp);
    	if(tmp == '0') status[i] = false;
    	else status[i] = true;
    }
    scanf("%I64d",&K);
    rabinkarp();
    printf("%d\n",hvalues.size());
    return 0;
}