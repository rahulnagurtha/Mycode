#include <bits/stdc++.h>

using namespace std;

int A[100005],key[100005],n;

void heapify(int position,int last) {
	int left,right,largest;
	largest = position;
	left = position*2;
	right = 1 + position*2;
	if(A[left] > A[position] && left <= last) {
		largest = left;
	}
	if(A[right] > A[largest] && right <= last) {
		largest = right;
	}
	swap(A[position],A[largest]);
	swap(key[position],key[largest]);
	if(largest != position && largest <= last) heapify(largest,last);
	else return;
}


void buildheap() {
	for (int i = n/2; i >= 1; --i) {
    	heapify(i,n);
    }
}


void increasekey(int position,int value) {
	A[position] = value;
	heapify(position,n);
}


void heapsort() {
	for (int i = n;i > 1;--i) {
		swap(A[i],A[1]);
		swap(key[i],key[1]);
		heapify(1,i-1);
	}
}

// main code begins now

int main()
{
	int temp,temp1;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d %d",&A[i],&key[i]);
    }
    buildheap();
    for (int i = 1; i <= n; ++i) {
    	printf("%d ",A[i],key[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
    	cin >> temp >> temp1;
    	increasekey(temp,temp1);
    	for (int j = 1; j <= n; ++j) {
	    	printf("%d ",A[j],key[j]);
	    }
	    printf("\n");
    }
    heapsort();
    for (int i = 1; i <= n; ++i) {
    	printf("%d,%d->",A[i],key[i]);
    }
    printf("\n");
    return 0;
}