#include <bits/stdc++.h>

using namespace std;

int n,m,ans,temp,one,two;
vector<int> starting,ending;
string a,a1;
char b;


void init() {
	for (int i = 0; i < n + 5; ++i) {
		starting.push_back(-1);
		ending.push_back(-1);
	}
	return;
}

void process() {
	if( (b != '.' && a[temp] != '.') || (b == '.' && a[temp] == '.') ) {
		printf("%d\n",ans);
		return;
	}

	if(b == '.') { // letter is replaced by a dot,so merge
		if(temp == 1 && a[temp+1] == '.') ans++;
		else if(temp == n && a[temp-1] == '.') ans++;
		else {
			if(a[temp-1] == '.' && a[temp+1] == '.') ans += 2;
			else if(a[temp-1] != '.' && a[temp+1] != '.') ans = ans;
			else if(a[temp-1] == '.') ans++;
			else ans++;
		}
	}
	else { // dot is replaced by a letter,so break
		if(temp == 1 && a[temp+1] == '.') ans--;
		else if(temp == n && a[temp-1] == '.') ans--;
		else {
			if(a[temp-1] == '.' && a[temp+1] == '.') ans -= 2;
			else if(a[temp-1] != '.' && a[temp+1] != '.') ans = ans;
			else if(a[temp-1] == '.') ans--;
			else ans--;
		}
	}
	a[temp] = b;
	printf("%d\n",ans);
	return;
}


// main code begins now

int main()
{
	cin >> n >> m;
	cin >> a1;
	a = 'D' + a1;
	ans = 0;
	for (int i = 1; i <= n; ) {
		if(a[i] != '.') {
			i++;
			continue;
		}
		one = i;
		two = i;
		for (; i <= n; ) {
			if(a[i] == '.') {
				two = i;
				i++;
			}
			else break;
		}
		ans += two - one;
	}
	for (int i = 0; i < m; ++i) {
		cin >> temp >> b;
		process();
	}
    return 0;
}