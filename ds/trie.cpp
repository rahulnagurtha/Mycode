#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;

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
	initialise();
    int n;
    LL temp,numbers[100005],max=-1,maxbits=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
    	scanf("%lld",&a[i]);
    	if(a[i]>max) max=a[i];
    }
    temp=max;
    while(temp>0) {
    	temp = temp >> 1 ;
    	maxbits++;
    }
    return 0;
}