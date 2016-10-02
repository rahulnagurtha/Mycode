#include <bits/stdc++.h>
 
using namespace std;
 
typedef struct ele {
	int num,two,three,five;
}node;
 
typedef struct element {
	int num,two,three,five;
}nodeone;
 
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
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007
 
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;
 
int two[35],three[21],five[15];
int bsize,tot,n,m,tmp,type,L,d,l,r,lb,rb,p;
 
node a[100005];
nodeone block[320];
 
 
void init() {
	five[0] = two[0] = three[0] = 1;
	for (int i = 1; i <= 14; ++i) five[i] = five[i-1]*5;
	for (int i = 1; i <= 20; ++i) three[i] = three[i-1]*3;
	for (int i = 1; i <= 31; ++i) two[i] = two[i-1]*2;
	for (int i = 0; i <= 100001; ++i) a[i].two = a[i].three = a[i].five = 0;
	for (int i = 0; i <= 319; ++i) block[i].two = block[i].three = block[i].five = 0;
	return;
}
 
 
// main code begins now
 
 
int main()
{
	init();
	cin >> n ;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		a[i].num = tmp;
		while(tmp%5 == 0) {
			tmp /= 5;
			a[i].five++;
		}
		while(tmp%2 == 0) {
			tmp /= 2;
			a[i].two++;
		}
		while(tmp%3 == 0) {
			tmp /= 3;
			a[i].three++;
		}
	}
	bsize = ceil(sqrt(n));
	tot = Ceil(n,bsize);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> type;
		if(type == 1) {
			cin >> l >> r >> p;
			lb = Ceil(l,bsize);
			rb = Ceil(r,bsize);
			if(lb == rb) {
				for (int i = l; i <= r; ++i) {
					if(p == 2 && a[i].num % 2 == 0) {
						a[i].num /= 2;
						a[i].two--;
					}
					if(p == 3 && a[i].num % 3 == 0) {
						a[i].num /= 3;
						a[i].three--;
					}
					if(p == 5 && a[i].num % 5 == 0) {
						a[i].num /= 5;
						a[i].five--;
					}
				}
			}
			else {
				for (int i = l; i <= lb*(bsize); ++i) {
					if(p == 2 && a[i].num % 2 == 0) {
						a[i].num /= 2;
						a[i].two--;
					}
					if(p == 3 && a[i].num % 3 == 0) {
						a[i].num /= 3;
						a[i].three--;
					}
					if(p == 5 && a[i].num % 5 == 0) {
						a[i].num /= 5;
						a[i].five--;
					}
				}
				lb++;
				for (int i = r; i >= 1+(rb-1)*(bsize); --i) {
					if(p == 2 && a[i].num % 2 == 0) {
						a[i].num /= 2;
						a[i].two--;
					}
					if(p == 3 && a[i].num % 3 == 0) {
						a[i].num /= 3;
						a[i].three--;
					}
					if(p == 5 && a[i].num % 5 == 0) {
						a[i].num /= 5;
						a[i].five--;
					}
				}
				rb--;
				if(lb <= rb) {
					if(p == 2) {
    					for (int i = lb; i <= rb; ++i) block[i].two++;
					}
					else if(p == 3) {
						for (int i = lb; i <= rb; ++i) block[i].three++;
					}
					else {
						for (int i = lb; i <= rb; ++i) block[i].five++;
					}
				}
			}
		}
		else {
			cin >> L >> d;
			lb = Ceil(L,bsize);
			for (int i = 1 + (lb-1)*(bsize); i <= lb*(bsize); ++i) {
				a[i].num /= two[min(a[i].two,block[lb].two)];
				a[i].two -= min(a[i].two,block[lb].two);
				a[i].num /= three[min(a[i].three,block[lb].three)];
				a[i].three -= min(a[i].three,block[lb].three);
				a[i].num /= five[min(a[i].five,block[lb].five)];
				a[i].five -= min(a[i].five,block[lb].five);
			}
			block[lb].two = block[lb].three = block[lb].five = 0;
			a[L].num = d;
			a[L].two = a[L].three = a[L].five = 0;
			tmp = a[L].num;
			while(tmp % 2 == 0) {
				a[L].two++;
				tmp /= 2;
			}
			while(tmp % 3 == 0) {
				a[L].three++;
				tmp /= 3;
			}
			while(tmp % 5 == 0) {
				a[L].five++;
				tmp /= 5;
			}
		}
	}
	for (int i = 1; i <= tot; ++i) {
		for (int j = 1+(i-1)*bsize; j <= i*bsize && j <= n; ++j) {
			a[j].num /= two[min(a[j].two,block[i].two)];
			a[j].num /= three[min(a[j].three,block[i].three)];
			a[j].num /= five[min(a[j].five,block[i].five)];
		}
	}
	for (int i = 1; i <= n; ++i) cout << a[i].num << " ";
    return 0;
}  