#include <bits/stdc++.h>
 
using namespace std; 

struct object {
	int score;
	int index;
	struct object *parent;
};
 
 
object player[10005];


struct object * process(struct object *x) {
	if(x->parent!=NULL) {
		x->parent=process(x->parent);
		return x->parent;
	}
	else {
		return x;
	}
}
 
 
// main code begins now
 
int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	int n,q,x,y,op,temp;
    	struct object *one,*two;
    	cin >> n ;
    	for (int i = 1; i <= n; ++i) {
    		cin >> temp ;
    		player[i].score=temp;
    		player[i].index=i;
    		player[i].parent=NULL;
    	}
    	cin >> q ;
    	for (int i = 0; i < q; ++i) {
    		cin >> op ;
    		if(op==0) {
    			cin >> x >> y ;
    			one=process(&player[x]);
    			two=process(&player[y]);
    			// printf("%d,%d\n",one->index,two->index);
    			if( one->index == two->index ) {
    				printf("Invalid query!\n");
    			}
    			else if(one->score > two->score){
    				if(one->parent!=NULL) two->parent=one->parent;
    				else two->parent=one;
    			}
    			else if(one->score < two->score) {
    				if(two->parent!=NULL) one->parent=two->parent;
    				else one->parent=two;
    			}
    			else {
    				continue;
    			}
    		}
    		else {
    			cin >> x ;
    			one=process(&player[x]);
    			cout << one->index << endl ;
    		}
    	}
    }
    return 0;
}  