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



struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};

// main code begins now

int main()
{
	VOII activities;
	int current,number,stime,etime;
	printf("number of activities: ");
	scanf("%d",&number);
	printf("enter the activities seperated by lines,each is of the form 'start-time end-time'\n");
	for (int i = 0; i < number; ++i) {
		scanf("%d %d",&stime,&etime);
		activities.pb(mp(stime,etime));
	}
    sort(activities.begin(),activities.end(),sort_pred());
    current = 0;
    printf("\nThe compatible activities are:\n");
    for (int i = 0; i < activities.size(); ++i) {
    	if (current <= activities[i].FF) {
    		printf("%d-%d\n",activities[i].FF,activities[i].SS);
    		current = activities[i].SS;
    	}
    }
    return 0;
}