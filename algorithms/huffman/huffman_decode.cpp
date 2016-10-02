#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a%b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;

//input text is to be given from in.txt
//encoded text will be in out.txt
//after decing,text will be in decode.txt
//code.txt contains the huffman coding for each character



map<char,LL> frequency;
map<string,string> huffcode;
typedef struct tree {
	char info;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}node;

node *head;

void initialise() {
	head=new node;
	head->info=' ';
	head->left=NULL;
	head->right=NULL;
	head->parent=NULL;
	return;
}

void build_tree(string body,char alphabet) {
	node *temp,*temp1;
	temp=head;
	for (int i = 0; i < body.size(); ++i) {
		if(body[i]=='<') {
			if(temp->left==NULL) {
				temp1=new node;
				temp1->info='<';
				temp1->left=NULL;
				temp1->right=NULL;
				temp1->parent=temp;
				temp->left=temp1;
				temp=temp1;
			}
			else {
				temp=temp->left;
			}
		}
		else{
			if(temp->right==NULL) {
				temp1=new node;
				temp1->info='>';
				temp1->left=NULL;
				temp1->right=NULL;
				temp1->parent=temp;
				temp->right=temp1;
				temp=temp1;
			}
			else {
				temp=temp->right;
			}
		}
	}
	temp1=new node;
	temp1->info=alphabet;
	temp1->left=NULL;
	temp1->right=NULL;
	temp1->parent=temp;
	temp->left=temp1;
	return;
}


void decode() {
	char ch;
	node *temp1;
	temp1=head;
	ifstream infile("out.txt");
	ofstream outfile("decode.txt");
	while(infile) {
		infile.get(ch);
		if(ch=='<') {
			temp1=temp1->left;
			if (temp1->left->info !='<') {
				if(temp1->left->info !='>') {
					//decode and go to beginning
					outfile.put(temp1->left->info);
					temp1=head;
				}
			}
		}
		else {
			temp1=temp1->right;
			if (temp1->left->info !='<') {
				if(temp1->left->info !='>') {
					//decode and go to beginning
					outfile.put(temp1->left->info);
					temp1=head;
				}
			}
		}
	}
	return;
}


// main code begins now

int main()
{
	initialise();
	char temp,ch;
    string one,two;
    int length=0,count=0;
	ifstream infile("code.txt");
    one="";
    //reading huffman format for each character to decode the original message
    while(infile) {
		infile.get(ch);
		if(ch!=',') {
			one+=ch;
			length++;
		}
		else {
			ch=count;
			two="";
			two+=ch;
			huffcode[two]=one;
			one="";
			count++;
			length=0;
		}
	}

    
    //build the tree based on the found coding from file
    for (int i = 0; i < 123; ++i) {
    	ch=i;
    	one="";
    	one+=ch;
    	if (huffcode[one]!="") { //building tree only for characters present in file
    		build_tree(huffcode[one],i);
    	}
    }
    infile.close();
    decode();
    return 0;
}