#include <bits/stdc++.h>

using namespace std;



bool check(list<int> &w,int candles[],int r,int *count,int t) {
	int temp,res,minus;
	res=0;
	for (int i = 0; i < r; ++i) {
		if(candles[i] < w.front()) {
			res++;
		}
	}
	temp=res;
	if(res==0) {
		for (int i = 0; i < r; ++i) {
			cout << candles[i] << " " ;
		}
		printf("\n");
		printf("no problem for %d\n",w.front());
		return true;
	}
	minus=0;
	for (int i = 0; i < r; ++i) {
		if(candles[i] < w.front()) {
			candles[i]=w.front()+t-minus;
			minus++;
		}
	}
	res=0;
	for (int i = 0; i < r; ++i) {
		if(candles[i] < w.front()) {
			res=1;
			break;
		}
	}
	if(res==0) {
		*count += temp;
		return true;
	}
	else return false;
}


// main code begins now

int main()
{
    int m,t,r,count=0,temp,end,res,flag=1;
    int candles[305];
    memset(candles,0,sizeof(candles));
    list<int> w;
    cin >> m >> t >> r ;
    for (int i = 0; i < m; ++i) {
    	cin >> temp ;
    	w.push_back(temp);
    }
	while(w.size() > 0) {
		res=check(w,candles,r,&count,t);
		if(res==false) {
			flag=0;
			printf("-1\n");
		}
		w.pop_front();
	}
	if(flag==1)	printf("%d\n",count);
    return 0;
}