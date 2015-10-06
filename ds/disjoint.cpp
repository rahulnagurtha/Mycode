#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;

typedef struct tree {
	int info;
	int rank;
	struct tree *parent;
}node;


void makeset(node *x,int key) {
	x->info=key;
	x->parent=x;
	x->rank=0;
	return;
}

node * findset(node *x) {
	if(x->parent!=x) {
		x->parent=findset(x->parent);
	}
	return x->parent;
}


void unionofboth(node *x,node *y) {
	node *one,*two;
	one=findset(x);
	two=findset(y);
	//combining their parents according to the required condition
	if(one!=two) {
		if(one->rank==two->rank) {
			one->rank++;
			two->parent=one;
		}
		else if(one->rank > two->rank) two->parent=one->parent;
		else one->parent=two->parent;
	}
	else {
		printf("they both belong to same parent\n");
	}
	return;
}


// main code begins now

int main()
{
    node entities[105];
    int key,temp1,temp2,count;
    cin >> count ;
    for (int i = 0; i < count; ++i) {
    	cin >> key ;
    	makeset(&entities[i],key);
    }
    for (int i = 0; i < 15; ++i) {
    	cin >> temp1 >> temp2 ;
    	unionofboth(&entities[temp1],&entities[temp2]);
    }
    return 0;
}