#include <bits/stdc++.h>

using namespace std;


class FoxPlayingGame
{
	double SA,SB;
public:
	double getmax(int nA,int nB,double score) {
		if(nB == 0) {

		}
		else if(nA == 0) {

		}
		else {
			double ans1 = getmax(nA-1,nB,score+SA);
			double ans2 = getmax(nA,nB-1,score*SB);
			
		}
	}
	double theMax(int nA, int nB, int paramA, int paramB) {
		SA = paramA/1000.0;
		SB = paramB/1000.0;
		return getmax(,0);
	}
	
};


int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {

    }
    return 0;
}