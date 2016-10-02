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



void huffman() {
	string one,two;
	pair<LL,string> temp1,temp2,tobepushed;
	if(pq.size()>2) {
		temp1=pq.top();
		pq.pop();
		temp2=pq.top();
		pq.pop();
		// cout << "examining " << temp1.SS << " and " << temp2.SS << endl ;
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
		// cout << "examining " << temp1.SS << " and " << temp2.SS << " and returning" << endl ;
		// cout << "assigning <,> to " << temp1.SS << " and " << temp2.SS << endl ;
		huffcode[temp1.SS]="<";
		huffcode[temp2.SS]=">";
	}
	return;
}


// main code begins now

int main()
{
	initialise();
	ifstream infile("in.txt");
    ofstream outfile;
    outfile.open("code.txt");
    char temp,ch;
    string one;
    //read the entire file and find the frequencies
    for (int i = 0; i < 123; ++i) {
    	temp=i;				//initialising the frequencies to zero by inserting into map
    	// huffcode[one]="";
    	frequency[temp]=0;
    }
    while(infile) {
		infile.get(ch); 	//reading characters from file
		frequency[ch]++;
	}
    for (int i = 0; i < 123; ++i) {
    	temp=i;					
    	one="";			// inserting into priorityqueue
    	one+=temp;
    	if(frequency[temp]!=0) {
    		pq.push(mp(frequency[temp],one));
    	}
    }

    //implement huffman coding according to that
    huffman();
    //huffman complete
    
    //build the tree based on the algorithm
    for (int i = 0; i < 123; ++i) {
    	ch=i;
    	one="";
    	one+=ch;
    	if (frequency[ch]!=0) {
    		build_tree(huffcode[one],i);
    	}
    	outfile << huffcode[one];
    	// outfile.put(huffcode[one]);
    	// outfile.put(",");
    	outfile << ",";
    }
    outfile.close();
    infile.close();
    //building of tree complete
    
    //and then code the file accordingly
    outfile.open("out.txt");
    infile.open("in.txt");
    while(infile) {
		infile.get(ch);
		one="";
		one+=ch;
		outfile << huffcode[one];
		// outfile.put(huffcode[one]);
	}
	outfile.close();
    infile.close();
	//encoding complete
	

	//now decoding part
	decode();
    return 0;
}