#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int> > > types(10);
int n,m,model,quality,price,answer,sum;


void solve() {
	answer = -9999999;
	for (int i1 = 0; i1 < types[1].size(); ++i1) {
		for (int i2 = 0; i2 < types[2].size(); ++i2) {
			for (int i3 = 0; i3 < types[3].size(); ++i3) {
				for (int i4 = 0; i4 < types[4].size(); ++i4) {
					for (int i5 = 0; i5 < types[5].size(); ++i5) {
						for (int i6 = 0; i6 < types[6].size(); ++i6) {
							sum = types[1][i1].first + types[2][i2].first + types[3][i3].first + types[4][i4].first + types[5][i5].first + types[6][i6].first;
							if(sum <= m) {
								answer = max(answer,min(types[1][i1].second,min(types[2][i2].second,min(types[3][i3].second,min(types[4][i4].second,min(types[5][i5].second,types[6][i6].second))))));
							}
						}
					}
				}
			}
		}
	}
	if(answer != -9999999) printf("%d\n",answer);
	else printf("0\n");
}

// main code begins now

int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
    	scanf("%d %d %d",&model,&price,&quality);
    	types[model].push_back(make_pair(price,quality));
    }
    if(types[1].size() == 0 || types[2].size() == 0 || types[3].size() == 0 || types[4].size() == 0 || types[5].size() == 0 || types[6].size() == 0) printf("0\n");
    else solve();
    return 0;
}