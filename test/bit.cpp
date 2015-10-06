#include <bits/stdc++.h>

using namespace std;


void display(int n) {
	int temp,len=0;
	temp=n;
	while(temp>0) {
		temp=temp >> 1 ;
		len++;
	}
	for (int i = 0; i < len; ++i) {
		temp = n & (1<<(len-i-1));
		if (temp!=0) {
			printf("1");
		}
		else printf("0");
	}
	printf("\n");
	return;
}


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int temp,temp1,temp2;
    	cin >> temp ;
    	display(temp);
    	temp=temp&(temp^(-temp));
    	// printf("%d\n",temp);

    	// temp=(temp^(-temp));

    	// temp1=temp+(temp&(-temp));
    	// temp2=(temp1&(-temp1))/(temp&(-temp));
    	// temp2=( temp2 >> 1 ) -1;
    	// temp=temp1+temp2;
    	

    	display(temp);
    }
    return 0;
}