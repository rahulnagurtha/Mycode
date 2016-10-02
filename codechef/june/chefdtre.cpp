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


typedef struct tree {
	char info;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}node;

node *head;

inline string dectobinary(LL number,LL maxbits){
    string tobeinserted="";
    string result = "";
    do {
        if((number&1)==0)
            result+="0";
        else
            result+="1";
        number>>=1;
    }while(number);
    reverse(result.begin(),result.end());
	for (int i = 0; i < maxbits-result.size(); ++i) {
		tobeinserted+='0';
	}
	result=tobeinserted+result;
    return result;
}

inline LL binarytodec(string binary){
	LL length,temp,result=0;
	length=binary.size();
	if(binary[length-1]=='1') result+=1;
	temp=1;
	for (int i = length-2; i >= 0; --i) {
		temp = temp <<  1 ;
		if(binary[i]=='1') result+=temp;
	}
    return result;
}


void initialise() {
	head=new node;
	head->info=' ';
	head->left=NULL;
	head->right=NULL;
	head->parent=NULL;
	return;
}



void addword(LL toadd,LL maxbits) {
	string tobeinserted=dectobinary(toadd,maxbits);
	struct tree *current,*temp;
	LL length;
	length=tobeinserted.size();
	current=head;
	for (LL i = 0; i < length; ++i) {
		if(tobeinserted[i]=='0') {
			if(current->left==NULL) {
				temp=new node;
				temp->info='0';
				temp->left=NULL;temp->right=NULL;
				temp->parent=current;
				current->left=temp;
			}
			current=current->left;
		}
		else {
			if(current->right==NULL) {
				temp=new node;
				temp->info='1';
				temp->left=NULL;temp->right=NULL;
				temp->parent=current;
				current->right=temp;
			}
			current=current->right;
		}
	}
	return;
}


LL query(LL toquery,LL maxbits) {
	string result="";
	string tobequeried=dectobinary(toquery,maxbits);
	struct tree *current,*temp;
	LL length,tobereturned;
	length=tobequeried.size();
	current=head;
	for (LL i = 0; i < length; ++i) {
		if(tobequeried[i]=='0') {
			if(current->right!=NULL) {
				result+='1';
				current=current->right;
			}
			else {
				result+='0';
				current=current->left;
			}
		}
		else {
			if(current->left!=NULL) {
				result+='1';
				current=current->left;
			}
			else {
				result+='0';
				current=current->right;
			}
		}
	}
	tobereturned=binarytodec(result);
	return tobereturned;
}

// main code begins now

int main()
{
	int t;
	cin >> t;
	while(t--) {
	    LL n,numbers[75][75],dp[75][75],maxbits,max,fans = -1,temp;
	    scanf("%lld",&n);
	    for (int i = 1; i <= n; ++i) {
	    	for (int j = 1; j <= n; ++j) {
	    		slli(numbers[i][j]);
	    	}
	    }
	    for (int i = 1; i <= n; ++i) dp[i][0] = 0;

	    for (int i = 1; i <= n; ++i) {
	    	dp[i][1] = numbers[i][1];
	    	for (int j = 2; j <= n; ++j) {
	    		dp[i][j] = dp[i][j-1] ^ numbers[i][j];
	    	}
	    }

	    for (int i = 1; i <= n; ++i) {
	    	for (int j = 1; j <= n-i+1; ++j) {
    			initialise();
    			maxbits=0;
    			max = -1;
                for (int k = 1; k <= n; ++k) {
                	temp = dp[k][j-1] ^ dp[k][j+i-1];
			    	if( temp > max) max = temp;
			    }
			    temp = max;
			    while(temp > 0) {
			    	temp = temp >> 1 ;
			    	maxbits++;
			    }
			    if( (dp[1][j+i-1] ^ dp[1][j-1]) > fans)  fans = dp[1][j+i-1] ^ dp[1][j-1];
	
			    for (int k = 2; k <= n; ++k) {
			    	addword(dp[k-1][j-1] ^ dp[k-1][i+j-1],maxbits);
			    	temp = query(dp[k][j-1] ^ dp[k][i+j-1],maxbits);
			    	if(temp > fans) fans = temp;
			    }
	    	}
	    }
	    printf("%lld\n",fans);
	}
    return 0;
}