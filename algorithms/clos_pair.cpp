#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			   ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			   (a-(box(a,b))*b)
#define ceil(a,b) 			  ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			  ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


//declaration of variables
VOLL xx,yy;
LL cpair;
LL tmp1,tmp2,n;
long double answer;

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};


LL brute(int i,int j) {
	LL tobesent;
	if(j-i==1) {
		tobesent=(xx[i].FF-xx[j].FF)*(xx[i].FF-xx[j].FF)+(xx[i].SS-xx[j].SS)*(xx[i].SS-xx[j].SS);
	}
	else {
		tmp1=(xx[i].FF-xx[j].FF)*(xx[i].FF-xx[j].FF)+(xx[i].SS-xx[j].SS)*(xx[i].SS-xx[j].SS);
		tmp2=(xx[i].FF-xx[i+1].FF)*(xx[i].FF-xx[i+1].FF)+(xx[i].SS-xx[i+1].SS)*(xx[i].SS-xx[i+1].SS);
		tmp1=min(tmp2,tmp1);
		tmp2=(xx[j].FF-xx[i+1].FF)*(xx[j].FF-xx[i+1].FF)+(xx[j].SS-xx[i+1].SS)*(xx[j].SS-xx[i+1].SS);
		tobesent=min(tmp1,tmp2);
	}
	return tobesent;
}


LL combine(int l,int r,int temp,VOLL partial) {
	VOLL tobechecked;
	LL temp1;
	for (int i = 0; i < partial.size(); ++i) {
		temp1=xx[(l+r)/2].FF;
		temp1=(temp1-partial[i].FF)*(temp1-partial[i].FF);
		if(temp1<=temp) {
			tobechecked.pb(partial[i]);
		}
	}
	for (int i = 0; i < tobechecked.size(); ++i) {
		for (int j = 1; j < 15; ++j) {
			if(i+j >= tobechecked.size()) break;
			else {
				temp1=(partial[i].FF-partial[i+j].FF)*(partial[i].FF-partial[i+j].FF)+(partial[i].SS-partial[i+j].SS)*(partial[i].SS-partial[i+j].SS);
				if (temp1<temp) temp=temp1;
			}
		}
	}
	return temp;

}

LL task(int i,int j,VOLL partial) {
	LL left,right,tobesent,middle;
	VOLL lside,rside; // vector to send left and right values in ascending order
	if(j-i<=2) {
		tobesent=brute(i,j);
	}
	else {
		middle=(i+j)/2;
		for (int k = 0; k < partial.size(); ++k) {
			if(partial[k].FF < xx[middle].FF) {
				lside.pb(partial[k]);
			}
			else {
				rside.pb(partial[k]);
			}
		}
		left=task(i,middle,lside);
		right=task(1+middle,j,rside);
		tobesent=combine(i,j,min(left,right),partial);
	}
	return tobesent;
}


// main code begins now

int main()
{
	printf("number of points\n");  
    cin >> n ;
    for (int i = 0; i < n; ++i) {
    	cin >> tmp1 >> tmp2 ;
    	xx.pb(mp(tmp1,tmp2));
    	yy.pb(mp(tmp1,tmp2));
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end(),sort_pred());
    if(n<=3) {
    	cpair=brute(0,n-1);
    }
    else cpair=task(0,n-1,yy);
    answer=sqrt(cpair);
    printf("the shortest distance is:%lld\n",cpair);
    cout << setprecision(30) << answer;
    return 0;
}