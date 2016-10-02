#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
#   define NDEBUG
#endif

#include <bits/stdc++.h>

using namespace std;


#ifdef DEBUG
     #define debug(args...)            {cerr<<__FUNCTION__<<":"<<__LINE__<<":";dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;





#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)


#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
// #define MOD                     1000000007
// #define MOD1                    1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

LL power[6*100001],opower[6*100001],MOD = 1000000007,MOD1 = 1000000007;
int n,m;
char s[6*100001];
vector<LL> hvalues,morehvalues;

void init() {
    power[0] = 1;
    opower[0] = 1;
    for (int i = 1; i <= 600005; ++i) {
        power[i] = power[i-1]*5;
        power[i] %= MOD;
        opower[i] = opower[i-1]*31;
        opower[i] %= MOD1;
    }
    return;
}

LL gethash() {
    LL send = 0,temp;
    temp = strlen(s);
    for (int i = 0; i < temp; ++i) {
        send = (send*5 + (LL)(s[i]-'a') + 1) % MOD;
    }
    return send;
}

LL getnexthash() {
    LL send = 0,temp;
    temp = strlen(s);
    for (int i = 0; i < temp; ++i) {
        send = (send*31 + (LL)(s[i]-'a') + 1) % MOD1;
    }
    return send;
}

void process() {
    LL temp = gethash();
    LL nexttemp = getnexthash();
    LL temp1 = strlen(s);
    LL one,two;
    for (int i = 0; i < temp1; ++i) {
        if(s[i] == 'a') {
            // one = (temp + power[temp1-i-1])%MOD;
            // two = (nexttemp + opower[temp1-i-1])%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp + power[temp1-i-1])%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp + opower[temp1-i-1])%MOD1)) {
                printf("YES\n");
                return;
            }
            // one = (temp + 2*power[temp1-i-1])%MOD;
            // two = (nexttemp + 2*opower[temp1-i-1])%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp + 2*power[temp1-i-1])%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp + 2*opower[temp1-i-1])%MOD1)) {
                printf("YES\n");
                return;
            }
        }
        else if(s[i] == 'b') {
            // one = (temp + power[temp1-i-1])%MOD;
            // two = (nexttemp + opower[temp1-i-1])%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp + power[temp1-i-1])%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp + opower[temp1-i-1])%MOD1)) {
                printf("YES\n");
                return;
            }
            // one = (LL)(temp - power[temp1-i-1] + 3*MOD)%MOD;
            // two = (nexttemp - opower[temp1-i-1] + 3*MOD1)%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp - power[temp1-i-1] + 3*MOD)%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp - opower[temp1-i-1] + 3*MOD1)%MOD1)) {
                printf("YES\n");
                return;
            }
        }
        else {
            // one = (temp - power[temp1-i-1] + 3*MOD)%MOD;
            // two = (nexttemp - opower[temp1-i-1] + 3*MOD1)%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp - power[temp1-i-1] + 3*MOD)%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp - opower[temp1-i-1] + 3*MOD1)%MOD1)) {
                printf("YES\n");
                return;
            }
            // one = (temp - 2*power[temp1-i-1] + 3*MOD)%MOD;
            // two = (nexttemp - 2*opower[temp1-i-1] + 3*MOD1)%MOD1;
            // debug(s[i],one,two);
            if(binary_search(hvalues.begin(),hvalues.end(),(temp - 2*power[temp1-i-1] + 3*MOD)%MOD) && binary_search(morehvalues.begin(),morehvalues.end(),(nexttemp - 2*opower[temp1-i-1] + 3*MOD1)%MOD1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
    return;
}


// main code begins now

int main()
{
    init();
    si2(n,m);
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%s",s);
        hvalues.pb(gethash());
        morehvalues.pb(getnexthash());
    }
    sort(hvalues.begin(),hvalues.end());
    sort(morehvalues.begin(),morehvalues.end());
    for (int i = 0; i < m; ++i) {
        scanf("%s",s);
        process();        
    }
    return 0;
}