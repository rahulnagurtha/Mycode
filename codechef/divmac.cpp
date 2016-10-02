#include <bits/stdc++.h>

using namespace std;


#define fill(a,v)               memset(a,v,sizeof a)
#define INF                     INT_MAX
#define N                       100007


typedef long long int ll;



inline void Refresh() {
    
}



struct tree {
	int ma;
};

tree seg[500001];

int A[100001];
int lpd[1000005];

// buildTree with array [i,j]

void buildTree(int node,int i,int j) {
	if(i>j) return;
	if(i == j) {						
		seg[node].ma = lpd[A[i]];
		return;
	}
	buildTree(node*2,i,(i+j)/2);
	buildTree(node*2+1,1+(i+j)/2,j);
	seg[node].ma = max(seg[node*2].ma,seg[1+node*2].ma);
	return;
}

int getmax(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return -2147483645;
	if(a >= i && b <= j) return seg[node].ma;
	int q1,q2;
	q1 = getmax(node*2, a, (a+b)/2, i, j);
	q2 = getmax(1+node*2, 1+(a+b)/2, b, i, j);
	int res = max(q1, q2);
	return res;
}

void upd_range(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return;
	if(a==b && a<=j && a>=i) {
		A[a] = A[a]/lpd[A[a]];
		seg[node].ma = lpd[A[a]];
        return;
	}
	if(seg[2*node].ma != 1) upd_range(2*node,a,(a+b)/2,i,j);
	if(seg[2*node + 1].ma != 1) upd_range(2*node+1,1+(a+b)/2,b,i,j);
	seg[node].ma = max(seg[2*node].ma,seg[2*node+1].ma);
    return;
}

void preprocess() {
	fill(lpd,-1);
	lpd[1] = 1;
	for (int i = 2; i < 1000005; ++i) {
		if(lpd[i] == -1) {
			for (int j = i; j < 1000005; j += i) {
				if(lpd[j] == -1) lpd[j] = i;
			}
		}
	}
	return;
}

int main()
{
	preprocess();
    int t;
    cin >> t ;
    while(t--) {
        int n,m;
        int l,r;
        int type;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
        	cin >> A[i];
        }
        buildTree(1,1,n);
        for (int i = 0; i < m; ++i) {
        	cin >> type >> l >> r;
        	if(type == 0) upd_range(1,1,n,l,r);
    		else cout << getmax(1,1,n,l,r) << " ";
        }
        cout << endl;
    }
    return 0;
}