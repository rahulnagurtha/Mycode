#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    string a;
    int count=0,pos=0,flag=0,size;
    char b;
    // freopen("in.txt", "r", stdin);
    cin >> a ;
    size=a.length();
    b=a[size-1];
    for (int i = 0; i < size; ++i)
    {
    	if(a[i] == '0' || a[i] == '2' || a[i] == '4' || a[i] == '6' || a[i] == '8') {
    		count++;
    		pos=i;
    	}
    }
    if(count==0) {
    	printf("-1\n");
    }
    else {
    	for (int i = 0; i < size; ++i)
	    {
	    	if(a[i]<b && (a[i] == '0' || a[i] == '2' || a[i] == '4' || a[i] == '6' || a[i] == '8')) {
	    		swap(a[i],a[size-1]);
	    		flag=1;
	    		break;
	    	}
	    }
	    if (flag==0)
	    {
	    	// printf("hello\n");
	    	swap(a[pos],a[size-1]);
	    }
	    for (int i = 0; i < size; ++i)
	    {
	    	cout << a[i] ;
	    }
	    printf("\n");
    }

    return 0;
}