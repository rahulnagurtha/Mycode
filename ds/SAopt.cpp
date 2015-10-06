#include <bits/stdc++.h>

using namespace std;

#define si(i) 					scanf("%d",&i)
#define slli(i) 				scanf("%I64d",&i)

#define pi(i) 					printf("%d\n",i)
#define plli(i) 				printf("%I64d\n",i)

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
typedef vector<VI> VOVI;

#define N 100005

int rank[30][N],n,aux[N],final; //rank[k][i] indicates the ranks based on their first 2^k characters
vector<pair<pair<int,int>,int> > tmparr(N);
vector<pair<pair<int,int>,int> > tmparr1(N);
VOII test;
string a;

void countsort() {

	int temp1 = n,temp2,temp3;
	
	//based on second type rank
	fill(aux,0);
	for (int i = 0; i < temp1; ++i) {
		aux[tmparr[i].FF.SS]++;
	}
	
	for (int i = 1; i <= 27; ++i) aux[i] += aux[i-1];
	
	for (int i = temp1-1; i >= 0; --i) {
		tmparr1[aux[tmparr[i].FF.SS]-1] = tmparr[i];
		aux[tmparr[i].FF.SS]--;
	}
	
	//based on first rank
	fill(aux,0);
	for (int i = 0; i < temp1; ++i) {
		aux[tmparr1[i].FF.FF]++;
	}
	
	for (int i = 1; i <= 27; ++i) aux[i] += aux[i-1];
	
	for (int i = temp1-1; i >= 0; --i) {
		tmparr[aux[tmparr1[i].FF.FF]-1] = tmparr1[i];
		aux[tmparr1[i].FF.FF]--;
	}
	
	return;
}

void buildSA() {
	int temp1,temp2,cnt,pre1,pre2;
	for (int i = 0; i < n; ++i) rank[0][i] = (a[i] - 'a') + 1;
	
	temp1 = n;
	temp2 = 1;
	for (int i = 1; i < temp1; ++temp2) {
		for (int j = 0; j < temp1; ++j) {
			tmparr[j].FF.FF = rank[temp2-1][j];
			tmparr[j].FF.SS = ((j+i > temp1 - 1) ? 0 : rank[temp2-1][j+i]);
			tmparr[j].SS = j;
		}
		
		countsort();
		cnt = 1;
		rank[temp2][tmparr[0].SS] = 1;
		pre1 = tmparr[0].FF.FF;
		pre2 = tmparr[0].FF.SS;
		for (int j = 1; j < temp1; ++j) {
			if( pre1 != tmparr[j].FF.FF || pre2 != tmparr[j].FF.SS ) {
				cnt++;
			}
			rank[temp2][tmparr[j].SS] = cnt;
		}
		
		i = i << 1;

	}
	final = temp2 - 1;
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
	cin >> a;
	n = a.size();
	buildSA();
	for (int i = 0; i < n; ++i) {
		test.pb(mp(rank[final][i],i));
	}
	sort(test.begin(),test.end());
	for (int i = 0; i < n; ++i) {
		for (int j = test[i].SS; j < n; ++j) {
			printf("%c",a[j]);
		}
		printf("\n");
	}
	return 0;
}
