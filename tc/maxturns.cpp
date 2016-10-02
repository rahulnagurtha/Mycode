#include <bits/stdc++.h>

using namespace std;


class SRMCards
{
public:
	int maxTurns(vector <int> cards) {
		int i = 0,turns = 0;;
		sort(cards.begin(),cards.end());
		while(i < cards.size()) {
			turns++;
			if(i+1 < cards.size()) {
				if(cards[i + 1] == cards[i] + 1) {
					i++;
				}
			}
			i++;
			return turns;
		}	
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