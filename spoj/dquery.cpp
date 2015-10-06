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



int block,n,arr[30005],queries,answer[200005];
int tmp = 0,curL,curR,Left,Right;
int cnt[1000005];

struct node {
    int L, R, num, i;
}q[200005];

bool cmp(node x,node y) {
    if(x.num != y.num) {
        return x.num < y.num;
    }
    return x.R < y.R ;
}


inline void add(int pos) {
    cnt[arr[pos]]++;
    if(cnt[arr[pos]] == 1) {
        tmp++;
    }
}

inline void remove(int pos) {
    cnt[arr[pos]]--;
    if(cnt[arr[pos]] == 0) {
        tmp--;
    }
}

// main code begins now

int main()
{
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i] ;
    }
    cin >> queries;
    block = sqrt(n);
    for (int i = 0; i < queries; ++i) {
        cin >> q[i].L >> q[i].R ;
        q[i].num = ceil(q[i].L,block);
        q[i].i = i;
    }
    curL = 1;
    curR = 2;
    add(1);
    add(2);
    sort(q,q+queries,cmp);
    // printf("\nafter sorting:\n");
    // for (int i = 0; i < queries; ++i) {
    //  printf("%d %d->%d\n",q[i].L,q[i].R,q[i].num);
    // }
    // printf("\n");
    for (int i = 0; i < queries; ++i) {
        Left = q[i].L;
        Right = q[i].R;
        while(curL < Left) {
            remove(curL);
            curL++;
        }
        while(curR > Right) {
            remove(curR);
            curR--;
        }
        while(curL > Left) {
            curL--;
            add(curL);
        }
        while(curR < Right) {
            curR++;
            add(curR);
        }
        answer[q[i].i] = tmp; 
        // printf("answer for %d,%d is %d\n",q[i].L,q[i].R,tmp);
    }
    for (int i = 0; i < queries; ++i) {
        printf("%d\n",answer[i]);
    }
    return 0;
}