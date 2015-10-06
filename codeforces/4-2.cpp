#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    map<string,int> data;
    map<string,int>::iterator it;
    string inp;
    int n,tmp;
    cin >> n ;
    getchar();
    for (int i = 0; i < n; ++i) {
    	getline(cin,inp);
    	it = data.find(inp);
    	if(it == data.end()) {
    		data[inp] = 1;
    		cout << "OK" << endl ;
    	}
    	else {
    		tmp = data[inp];
    		cout << inp << tmp << endl;
    		data[inp] = tmp + 1;
    	}
    }
    return 0;
}