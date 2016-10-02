#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

set<int> hbreaks,vbreaks;
set<int>::iterator itlow,itup;
int hfreq[200005],vfreq[200005],temp,hpntr,vpntr,point,w,h,n;
LL answer;
string type;


void hprocess() {
	itlow = hbreaks.lower_bound(temp);
	itup = hbreaks.upper_bound(temp);
	itlow--;
	hfreq[*itup-*itlow]--;
	hfreq[*itup-temp]++;
	hfreq[temp-*itlow]++;
	hbreaks.insert(temp);
	return;
}


void vprocess() {
	itlow = vbreaks.lower_bound(temp);
	itup = vbreaks.upper_bound(temp);
	itlow--;
	vfreq[*itup-*itlow]--;
	vfreq[*itup-temp]++;
	vfreq[temp-*itlow]++;
	vbreaks.insert(temp);
	return;
}


void solve() {
	while(hfreq[hpntr]==0) hpntr--;
	while(vfreq[vpntr]==0) vpntr--;
	answer = (LL)(hpntr)*(LL)(vpntr);
	printf("%I64d\n",answer);
}

void init() {
	hpntr = h;
    vpntr = w;
    hfreq[h] = 1;
    vfreq[w] = 1;
	hbreaks.insert(0);
    hbreaks.insert(h);
    vbreaks.insert(0);
    vbreaks.insert(w);
    return;
}

// main code begins now

int main()
{
    cin >> w >> h >> n;
    init();
    for (int i = 0; i < n; ++i) {
    	cin >> type >> temp;
    	if (type == "H") {
    		hprocess();
    		solve();
    	}
    	else {
    		vprocess();
    		solve();
    	}
    }
    return 0;
}