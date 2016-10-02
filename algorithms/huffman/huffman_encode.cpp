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

//input text is to be given from in.txt
//encoded text will be in out.txt
//after decing,text will be in decode.txt
//code.txt contains the huffman coding for each character


class CompareDist
{
public:
    bool operator()(pair<LL,string> n1,pair<LL,string> n2)
    {
    	if(n1.first>n2.first) return true;
    	else return false;    
  	}
};


map<char,LL> frequency;
priority_queue<pair<LL,string>,vector<pair<LL,string> >,CompareDist > pq; 
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



void huffman() {
	string one,two;
	pair<LL,string> temp1,temp2,tobepushed;
	if(pq.size()>2) {
		temp1=pq.top();
		pq.pop();
		temp2=pq.top();
		pq.pop();
		tobepushed.FF=temp1.FF+temp2.FF;
		tobepushed.SS=temp2.SS+temp1.SS;
		pq.push(tobepushed);
		huffman();
		huffcode[temp1.SS]=huffcode[tobepushed.SS]+"<";
		huffcode[temp2.SS]=huffcode[tobepushed.SS]+">";	
	}
	else {
		temp1=pq.top();
		pq.pop();
		temp2=pq.top();
		pq.pop();
		huffcode[temp1.SS]="<";
		huffcode[temp2.SS]=">";
	}
	return;
}


// main code begins now

int main()
{
	initialise();
	char temp,ch;
    string one;
	ifstream infile("in.txt");
    ofstream outfile;
    outfile.open("code.txt");
    
    //read the entire file and find the frequencies
    for (int i = 0; i < 125; ++i) {
    	temp=i;				//initialising character frequencies to zero by inserting into map
    	frequency[temp]=0;
    }
    while(infile) {
		infile.get(ch); 	//reading characters from file and increasing frequencies correspondingly
		frequency[ch]++;
	}
    for (int i = 0; i < 125; ++i) {
    	temp=i;					
    	one="";			// inserting into priorityqueue for the purpose of encoding
    	one+=temp;
    	if(frequency[temp]!=0) {
    		pq.push(mp(frequency[temp],one));
    	}
    }

    //finding huffman coding accordingly
    huffman();

    
    //build the tree based on the found coding
    for (int i = 0; i < 125; ++i) {
    	ch=i;
    	one="";
    	one+=ch;
    	if (frequency[ch]!=0) { //building tree only for characters present in file
    		build_tree(huffcode[one],i);
    	}
    	outfile << huffcode[one]; //exporting the coding to other file for later use
    	outfile << ",";
    }
    outfile.close();
    infile.close();
    
    //encoding the file accordingly
    outfile.open("out.txt");
    infile.open("in.txt");
    while(infile) {
		infile.get(ch);
		one="";
		one+=ch;
		outfile << huffcode[one];
	}
	outfile.close();
    infile.close();
    return 0;
}