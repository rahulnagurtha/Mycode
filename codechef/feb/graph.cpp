#include <bits/stdc++.h>

using namespace std;

#define mp     make_pair
#define pb     push_back
#define MOD    1000000007

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


VOLL edges(50005);
VI layers(50005);
VL starting;
VL ending;
map<LL,LL> dp;
map<LL,list<PLL> > info;

LL n,m,k,ans;



LL fast_exp(LL base,LL exp) {
    LL res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base) % MOD;
       base=(base*base) % MOD;
       exp/=2;
    }
    return res % MOD;
}


LL previous(LL val) {
    VL::iterator it;
    it=lower_bound(ending.begin(),ending.begin()+k,val);
    //finding
    if(ending[it-ending.begin()]>val) {
        if (it!=ending.begin()) {
            it--; // not at end of array so rewind to previous item
        } 
        else {
            it=ending.end(); // no items before this point, so return end()
        }
    }
    if(it==ending.end()) return -1;
    else {
        return ending[it-ending.begin()];
    }
}


void process() {
    // printf("process\n");
    LL temp,temp1,temp2,prelayer,temp3;
    PLL tobefound;
    map<LL,LL> ::iterator it;
    list<PLL> templist;
    //calculating the answer
    temp=info.size();
    //for each layer calculate the answer
    for (int i = 0; i < temp; ++i) {
        templist=info.find(edges[i].second)->second;
        temp1=templist.size();
        // printf("each layer\n");
        //for each edge ending at that layer
        for (int i = 0; i < temp1; ++i) {
            tobefound=templist.front();
            prelayer=previous(tobefound.first);
            if(prelayer==-1) {  //if there is no layer before this
                temp2=fast_exp(m,tobefound.second-1);
                dp[tobefound.second]=temp2;    
                ans+=temp2;
                ans=ans%MOD;
                // printf("here\n");
            }
            else {
                it=dp.find(prelayer);
                ans+=it->second;
                if(edges[i].second==n+1) {
                    ans+=fast_exp(m,edges[i].second-1);
                    ans%=MOD;
                }
                else {
                    ans+=fast_exp(m,edges[i].second);
                    ans%=MOD;
                }
            }
            templist.pop_front();
        }
    }
}


void task() {
    map<LL,list<PLL> > ::iterator it;
    sort(edges.begin(),edges.begin()+k,sort_pred());
    //processing info for my algo
    for (int i = 0; i < k; ++i) {
        it=info.find(edges[i].second);
        if (it==info.end()) {
            list<PLL> templist;
            templist.pb(mp(edges[i].first,edges[i].second));
            info[edges[i].second]=templist;
            ending.pb(edges[i].second);
            starting.pb(edges[i].first);
            // printf("inserted layer %lld\n",edges[i].second);
        }
        else {
            it->second.pb(mp(edges[i].first,edges[i].second));
            // ending.pb(edges[i].second);
            starting.pb(edges[i].first);
        }
    }
    process();
}


// main code begins now

int main()
{
    LL ans1,temp1,temp2,temp3,temp4;
    ans=0;
    cin >> n >> m >> k ;
    for (int i = 0; i < k; ++i) {
        cin >> temp1 >> temp2 >> temp3 >> temp4;
        edges[i]=(mp(temp1,temp3));
    }
    if(k!=0) {
       task();
    }
    else ans=fast_exp(m,n);
    cout << ans << endl ;
    return 0;
}