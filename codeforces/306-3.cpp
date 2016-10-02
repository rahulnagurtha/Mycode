#include <bits/stdc++.h>

using namespace std;



// main code begins now


int main()
{
    string a;
    cin >> a;
    int temp = 0;
    for (int i = 0; i < a.size(); ++i) {
    	temp = (int)(a[i]) - 48;
    	if(temp % 8 == 0) {
    		printf("YES\n");
    		printf("%c\n",a[i]);
    		return 0;
    	}
    	for (int j = i+1; j < a.size(); ++j) {
    		temp = (temp*10) + ((int)(a[j]) - 48);
	    	if(temp % 8 == 0) {
	    		printf("YES\n");
	    		printf("%c%c\n",a[i],a[j]);
	    		return 0;
	    	}
    		for (int k = j+1; k < a.size(); ++k) {
    			temp = (temp*10) + ((int)(a[k]) - 48);
		    	if(temp % 8 == 0) {
		    		printf("YES\n");
		    		printf("%c%c%c\n",a[i],a[j],a[k]);
		    		return 0;
		    	}
		    	temp = temp/10;
    		}
    		temp = temp/10;
    	}
    	temp = temp/10;
    }
    printf("NO\n");
    return 0;
}