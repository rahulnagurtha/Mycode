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


struct sort_pred {
    bool operator()(const pair<PII,int> &left, const pair<PII,int> &right) {
        if (left.FF.FF != right.FF.FF) {
            return left.FF.FF < right.FF.FF;
        }
        else {  
            return left.FF.SS < right.FF.SS;
        }
    }
};


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
	vector<pair<PII,int> > tobesorted(100005);
	int count,temp1,temp2,temp3,temp4,lcp[100005];
	VOII final(100005);
	string input,temp;
	cin >> temp ;
	input = " " + temp;
	temp1 = temp.size();

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
		sort(tobesorted.begin(),tobesorted.begin()+temp1,sort_pred());
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
		final[i].FF = rank[temp2][i+1];
		final[i].SS = i+1;
	}
	sort(final.begin(),final.begin()+temp1);
	//printing the final answer
	for (int i = 0; i < temp1; ++i) {
		for (int j = final[i].SS; j <= temp1 ; ++j) {
			cout << input[j] ;
		}
		printf("\n");
	}

	//calculating lcp between all the adjacent strings
    for (int i = 1; i < temp1; ++i) {
    	lcp[i]=task(i,i+1,temp2);
    }
    printf("\n");
    //calculating the lcp between any two suffixes
    for (int i = 1; i < temp1 ; ++i) {
    	printf("%d,%d--->%d\n",i,i+1,lcp[i]);
    }
    printf("%d\n",task(1,4,temp2));
    return 0;
}