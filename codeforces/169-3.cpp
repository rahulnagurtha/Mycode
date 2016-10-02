#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
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

LL N,bsize,q,lft,ryt,lblock,rblock,answer;
LL numbers[200005],freq[200005],block[505];
LL lastblock;

void process(LL lft,LL ryt) {
    lblock = ceil(lft,bsize);
    rblock = ceil(ryt,bsize);
    if(lblock == rblock) {
        for (LL i = lft; i <= ryt; ++i) {
            freq[i]++;
        }
        return;
    }
    if(lblock == lastblock-1) {
        for (LL i = lft; i <= ryt; ++i) {
            freq[i]++;
        }
        return;
    }
    if(lft%bsize != 1) {
        for (LL i = lft; i <= lblock*bsize; ++i) {
            freq[i]++;
        }
        lft = lblock*bsize+1;
        lblock++;
    }
    if(ryt%bsize != 0) {
        for (LL i = ryt; i > (rblock-1)*bsize; --i) {
            freq[i]++;
        }
        ryt = (rblock-1)*bsize;
        rblock--;
    }
    if(lft > ryt) {
        return;
    }
    for (LL i = lblock; i <= rblock; ++i) {
        block[i]++;
    }
    return;
}


void solve() {
    LL preblock;
    for (LL i = 0; i < q; ++i) {
        scanf("%I64d %I64d",&lft,&ryt);
        process(lft,ryt);
    }
    for (LL i = 1; i <= N; i+=bsize) {
        preblock = ceil(i,bsize);
        for (LL j = 0; j < bsize; ++j) {
            freq[i+j] += block[preblock];
        }
    }
    sort(freq+1,freq+N+1,greater<int>());
    for (LL i = 1; i <= N; ++i) {
        answer += freq[i]*numbers[i];
    }
    printf("%I64d\n",answer);
    return;
}

void brute() {
    for (int i = 0; i < q; ++i){
        scanf("%I64d %I64d",&lft,&ryt);
        for (LL i = lft; i <= ryt; ++i) {
            freq[i]++;
        }
    }
    sort(freq+1,freq+N+1,greater<int>());
    for (LL i = 1; i <= N; ++i) {
        answer += freq[i]*numbers[i];
    }
    printf("%I64d\n",answer);
    return;
}

// main code begins now

int main()
{
    scanf("%I64d %I64d",&N,&q);
    bsize = sqrt(N);
    for (int i = 1; i <= N; ++i) {
        scanf("%I64d",&numbers[i]);
    }
    lastblock = ceil(N,bsize);
    sort(numbers+1,numbers+N+1,greater<int>());
    if(N <= 3) brute();
    else solve();
    return 0;
}