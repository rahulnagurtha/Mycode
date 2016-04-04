#include <bits/stdc++.h>

using namespace std;

const int maxn = 100009;

#define maxKD 100005
#define maxK  205
#define CEIL(a,b)  (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))




void generaterandgraph(int read_k) {
	vector<int> Al[100009];
    int deg,edges;
    int from[maxK+5];
    bool okay = false;
    while(1) {
        cout << "Enter degree d (k*d must be even): ";
        cin >> deg;
        if(((read_k*deg) % 2) == 0) break;
    }
    while(!okay) {
        int Q[maxKD],cur;
        double tmp;
        int toswap;
        for (int i = 1; i <= read_k*deg; ++i) {
            Q[i] = i;
        }

		random_shuffle(Q+1, Q+read_k*deg+1);
        cur = read_k*deg;
        for (int i = 1; i*2 <= read_k*deg; ++i) {

           double rr = (double)rand();
		    double mx = (double)(RAND_MAX-1);
		    double r = rr/mx;
		    tmp = ((double)(cur-1)*r);
            

            toswap = (int)(ceil(tmp));
            assert(toswap > 0 && toswap < cur);
            from[Q[cur]] = Q[toswap];
            from[Q[toswap]] = Q[cur];
            swap(Q[cur-1],Q[toswap]);
            cur -= 2;
        }
        okay = true;
        for (int i = 1; i <= read_k; ++i) {
            bool zerodegree = true; 
            for (int j = (i-1)*deg+1; j <= i*deg; ++j) {
                if((from[j] > i*deg) || (from[j] < (1+(i-1)*deg))) {
                    zerodegree = false;
                }
            }
            if(zerodegree) {
                okay = false;
                break;
            }
        }
    }
    edges = 0;
    for (int i = 1; i <= read_k; ++i) {
        int to;
        for (int j = (i-1)*deg+1; j <= i*deg; ++j) {
        	assert(from[j] > 0);
            to = CEIL(from[j],deg);
            if((to != i) && (find(Al[i].begin(),Al[i].end(),to) == Al[i].end()) ) {
                Al[i].push_back(to);
                Al[to].push_back(i);
                edges = 0;
            }
        }
    }
    for (int i=1; i<=10; i++){
        cout<<i<<" -> ";
        for (int j=0; j<Al[i].size(); j++){
            cout<<Al[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\nGraph ends\n\n\n";
    return;
}


int main()
{
    generaterandgraph(10);
    return 0;
}
