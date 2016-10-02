#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


// main code begins now

int main()
{
	int pos[10],tmp;
    string inp;
    getline(cin,inp);
    pos[0] = inp.size();
    for (int i = 0; i < inp.size(); ++i) {
    	if(inp[i] == 'h') {
        	pos[0] = i;
    		break;
    	}
    }
    if(pos[0] == inp.size()){
    	printf("NO\n");
    	return 0;
    }
    pos[1] = inp.size();
    for (int i = pos[0]+1; i < inp.size(); ++i) {
    	if(inp[i] == 'e') {
        	pos[1] = i;
    		break;
    	}
    }
    if(pos[1] == inp.size()){
    	printf("NO\n");
    	return 0;
    }
    pos[2] = inp.size();
    for (int i = pos[1]+1; i < inp.size(); ++i) {
    	if(inp[i] == 'l') {
        	pos[2] = i;
    		break;
    	}
    }
    if(pos[2] == inp.size()){
    	printf("NO\n");
    	return 0;
    }
    pos[3] = inp.size();
    for (int i = pos[2]+1; i < inp.size(); ++i) {
    	if(inp[i] == 'l') {
        	pos[3] = i;
    		break;
    	}
    }
    if(pos[3] == inp.size()){
    	printf("NO\n");
    	return 0;
    }
    pos[4] = inp.size();
    for (int i = pos[3]+1; i < inp.size(); ++i) {
    	if(inp[i] == 'o') {
        	pos[4] = i;
    		break;
    	}
    }
    if(pos[4] == inp.size()){
    	printf("NO\n");
    	return 0;
    }
    printf("YES\n");
    return 0;
}