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
#define rem1(a,b) 			    ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


int rank[30][100005]; //rank[k][i] indicates the ranks based on their first 2^k characters
vector<pair<PII,int> > tobesorted(100005);

struct sort_pred {
    bool operator()(const pair<PII,int> &left, const pair<PII,int> &right) { 
        return left.FF.SS < right.FF.SS;
    }
};



void bucketsort(int temp1) {
    
    vector< vector<pair<PII,int> > > buckets;
    buckets.resize(100005);
    int temp,totalbuckets=0,count;
    for (int i = 0; i < temp1; ++i) {
        if(tobesorted[i].FF.FF > totalbuckets) totalbuckets = tobesorted[i].FF.FF;
        buckets[tobesorted[i].FF.FF].pb(tobesorted[i]);
    }
    for (int i = 1; i <= totalbuckets ; ++i) {
        sort(buckets[i].begin(),buckets[i].end(),sort_pred());
    }
    count=0;
    for (int i = 1; i <= totalbuckets ; ++i) {
        temp=buckets[i].size();
        for (int j = 0; j < temp ; ++j) {
            tobesorted[count++] = buckets[i][j] ;
        }
    }
    return;
}



int task(int x,int y,int temp) {
	int answer=0,temp1;
	temp1 = 1 << temp ;
	for (int i = temp; i >= 0; --i) {
		if(rank[i][x]==rank[i][y]) {
			answer += temp1;
			x+=temp1;
			y+=temp1;
		}
		temp1 = temp1 >> 1 ;
	}
	return answer;
}


// main code begins now

int main()
{
	clock_t start_t, end_t, total_t;
	double ans;
    freopen("in.txt", "r", stdin);
	int count,temp1,temp2,temp3,temp4,lcp[100005];
	VOII final(100005);
	string input,temp;
	cin >> temp ;
	input = " " + temp;
	temp1 = temp.size();
	
	start_t = clock();
	//giving ranks based on first character
	for (int i = 1; i <= temp1; ++i) {
	    rank[0][i] = (char)input[i];
	}
	temp2 = 1 ;

	//runnig for logn times by doubling the length to compared at each step
	for (int i = 1; i < temp1 ; temp2++) {

		//preparing the numbers to sort based on the criteria
		for (int k = 0; k < temp1; ++k) {
			tobesorted[k].FF.FF=rank[temp2-1][k+1];
			tobesorted[k].FF.SS=( (i+k+1 > temp1) ? -1 : rank[temp2-1][i+k+1]);
			tobesorted[k].SS=k+1;
		}
		bucketsort(temp1);
		temp3=tobesorted[0].FF.FF;
		temp4=tobesorted[0].FF.SS;
		count=1;

		//assigning the ranks to the strings based on first 2^temp2 characters
		for (int k = 0; k < temp1; ++k) {

			//giving same rank in case their first 2^temp2 characters are same
			if( tobesorted[k].FF.FF !=temp3 || tobesorted[k].FF.SS !=temp4 ) {
				temp3=tobesorted[k].FF.FF;
				temp4=tobesorted[k].FF.SS;
				count++;
			}
			rank[temp2][tobesorted[k].SS]=count;
		}
		i = i << 1;
	}	
	//now sorting the final result
	temp2--;
	for (int i = 0; i < temp1 ; ++i) {
		final[i].FF=rank[temp2][i+1];
		final[i].SS=i+1;
	}
	sort(final.begin(),final.begin()+temp1);

	//calculating lcp between all the adjacent strings
    for (int i = 1; i < temp1; ++i) {
    	lcp[i]=task(i,i+1,temp2);
    }
    end_t = clock();
	ans = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %lf\n\n", ans );
    return 0;
}
