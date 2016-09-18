#include <bits/stdc++.h>

using namespace std;



#ifndef ONLINE_JUDGE
#include "debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif


#define root 0
#define N 10100
#define LN 14

vector <int> adj[N], costs[N], indexx[N];

int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(int cur, int s, int e) {
	if(s == e) {
		st[cur] = baseArray[s];
		return;
	}
	int c1 = (cur << 1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m+1, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e < x) return;
	if(s == x && s == e) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m + 1, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E]
 */
void query_tree(int cur, int s, int e, int S, int E) {
	if(s > E || e < S) {
		qt[cur] = -1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	int c1 = (cur << 1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m + 1, e, S, E);
	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v) {
	// if(u == v) return 0; // Trivial
	int uchain, vchain = chainInd[v], ans = -1;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			// if(u == v) break;
			query_tree(1, 0, ptr, posInBase[v], posInBase[u]);
			// Above is call to segment tree query function
			if(qt[1] > ans) ans = qt[1]; // Update answer
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		if(qt[1] > ans) ans = qt[1];
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}


/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}

void HLD(int curNode, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = 0;

	int sc = -1;
	// Loop to find special child
	for(int i = 0; i < adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, curNode);
	}

	for(int i = 0; i < adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], curNode);
		}
	}
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(int cur, int prev) {
	pa[cur] = prev;
	subsize[cur] = 1;
	for(int i = 0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main() {
	ptr = 0;
	int n;
	scanf("%d", &n);
	// Cleaning step, new test case
	for(int i = 0; i < n; i++) {
		adj[i].clear();
		costs[i].clear();
		indexx[i].clear();
		chainTail[i] = -1;
		for(int j=0; j<LN; j++) child[j][i] = -1;
	}
	for(int i = 1; i < n; i++) {
		int u, v, c;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	chainNo = 0;
	dfs(root, -1); // We set up subsize, depth and parent for each node
	HLD(root, -1); // We decomposed the tree and created baseArray
	make_tree(1, 0, ptr-1); // We use baseArray and construct the needed segment tree

	while(1) {
		int type,x;
		scanf("%d %d",&type, &x);
		if(type == 0) {
			change(x);
		}
		else {
			printf("%d\n",query_up(x,1));
		}
	}
}