#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

struct info {
	LL x,y,g;
};


info exeuclid(LL a,LL b) {
	info send,temp;
	if(b == 0) {
		send.x = 1;
		send.y = 0;
		send.g = a;
	}
	else {
		temp = exeuclid(b,a%b);
		send.x = temp.y;
		send.y = temp.x - (a/b)*temp.y;
		send.g = temp.g;
	}
	return send;
}

// main code begins now

int main()
{
	info temp;
    LL a,b;
    cin >> a >> b ;
    if(a <= b) if(b>a) swap(a,b);
    temp = exeuclid(a,b);
    printf("%lld*%lld + %lld*%lld = %lld\n",a,temp.x,b,temp.y,temp.g);
    return 0;
}