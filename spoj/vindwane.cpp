#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int m,n,c,X1,Y1,X2,Y2,X,y,d;
int a[1005][1005];
char temp;
string cell[1005],tmp;
map<char,int> mymap1;
map<int,char> mymap2;

void init() {
	mymap1['N'] = 0;
	mymap1['E'] = 1;
	mymap1['S'] = 2;
	mymap1['W'] = 3;
	mymap2[0] = 'N';
	mymap2[1] = 'E';
	mymap2[2] = 'S';
	mymap2[3] = 'W';
	fill(a,0);
	return;
}


inline void modify() {
	for (int i = X1; i <= X2; ++i) {
		if(d == 0) {
			a[i][Y1]++;
			a[i][Y2+1]--;
		}
		else {
			a[i][Y1] += 3;
			a[i][Y2+1] -= 3;
		}
	}
	return;
}

inline void getdirection() {
	int one = 0;
	char ans;
	for (int i = 1; i <= y; ++i) one += a[X][i];
	ans = mymap2[(mymap1[cell[X][y]] + one)%4];
	printf("%c\n",ans);
	return;
}


// main code begins now

int main()
{
	init();
	si2(m,n);
	getchar();
	for (int i = 1; i <= m; ++i) {
		cin >> tmp;
		cell[i] = '.'+tmp;
	}
	si(c);
	getchar();
	for (int i = 0; i < c; ++i) {
		scanf("%c",&temp);
		if(temp == 'C') {
			scanf("%d %d %d %d %d",&X1,&Y1,&X2,&Y2,&d);
			modify();
		}
		if(temp == 'D') {
			si2(X,y);
			getdirection();
		}
		getchar();
	}
    return 0;
}