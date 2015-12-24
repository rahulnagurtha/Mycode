struct tree {
    int mi;
    int ma;
    int sum;
};

tree seg[500001];
int a[100001];

// Build with array [i,j]

void build(int node,int i,int j) {
    if(i>j) return;
    if(i==j) {                        
        seg[node].mi = seg[node].ma = seg[node].sum = a[i];
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    seg[node].ma = max(seg[node*2].ma,seg[1+node*2].ma);
    seg[node].mi = min(seg[node*2].mi,seg[1+node*2].mi);
    seg[node].sum = seg[node*2].sum + seg[1+node*2].sum;
    return;
}

int qmin(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return 2147483645;
    if(a >= i && b <= j) return seg[node].mi;
    int q1,q2;
    q1 = qmin(node*2, a, (a+b)/2, i, j);
    q2 = qmin(1+node*2, 1+(a+b)/2, b, i, j);
    int res = min(q1, q2);
    return res;
}

int qmax(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return -2147483645;
    if(a >= i && b <= j) return seg[node].ma;
    int q1,q2;
    q1 = qmax(node*2, a, (a+b)/2, i, j);
    q2 = qmax(1+node*2, 1+(a+b)/2, b, i, j);
    int res = max(q1, q2);
    return res;
}

int qsum(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return 0;
    if(a >= i && b <= j) return seg[node].sum;
    int q1,q2;
    q1 = qsum(node*2, a, (a+b)/2, i, j);
    q2 = qsum(1+node*2, 1+(a+b)/2, b, i, j);
    int res = q1 + q2;
    return res;
}

void upd(int node,int pos,int i,int j,int val) {
    if(i>j) return;
    if(i==j&&i==pos) {            
        seg[node].ma = seg[node].mi = seg[node].sum = val;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].ma = max(seg[2*node].ma,seg[2*node+1].ma);
        seg[node].mi = min(seg[2*node].mi,seg[2*node+1].mi);
        seg[node].sum = seg[2*node].sum + seg[1+2*node].sum;
        return;
    }
}