#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
	bool modify;
    string a;
    cin >> a;

    modify = true;
    //case-1
    for (int i = 0; i < a.size(); ++i) {
    	if(!isupper(a[i])) {
    		modify = false;
    		break;
    	}
    }
    if(modify == true) {
    	for (int i = 0; i < a.size(); ++i) {
    		printf("%c",tolower(a[i]));
    	}
    	printf("\n");
    	return 0;
    }
    //case-2
    if(isupper(a[0])) {
    	cout << a << endl;
    	return 0;
    }
    modify = true;
    for (int i = 1; i < a.size(); ++i) {
    	if(!isupper(a[i])) {
    		modify = false;
    		break;
    	}
    }
    if(modify == true) {
    	printf("%c",toupper(a[0]));
    	for (int i = 1; i < a.size(); ++i) {
    		printf("%c",tolower(a[i]));
    	}
    	printf("\n");
    	return 0;
    }
    cout << a << endl;
    return 0;
}