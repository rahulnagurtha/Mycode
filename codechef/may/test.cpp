#include <bits/stdc++.h>

using namespace std;

string s;
int changes,k;

int findsubstr(int start) {
	int tmp,i;
    char one,two;
    one = s[start];
    for (i = start; i < s.size(); ++i) {
        printf("checking %c %c\n",s[i],one);
        if (s[i] != one) {
            return i-1;
        }
    }
    return s.size()-1;
}

void changestr(int start,int end) {
    int cur;
    char newchar;
    if (s[start] == '0') {
        newchar = '1';
    }
    else {
        newchar = '0';
    }
    cur = start+k;
    while(cur <= end) {
        if (cur == end) {
            s[cur-1] = newchar;
        }
        else {
            s[cur] = newchar;
        }
        cur += k+1;
    }
}


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n,ans,tmp,left,right,cur;
    	char alt[3];
    	changes = 0;
    	alt[0] = '0';
    	alt[1] = '1'; 
    	cin >> n >> k ;
    	getchar();
    	getline(cin,s);
        cur = 0;
        while(cur < n) {
            left = cur;
            right = findsubstr(left);
            printf("%d %d\n",left,right);
            scanf("%c",&alt[0]);
            getchar();
            if(right-left+1 > k) changestr(left,right);
            cout << s << endl ;
            cur = right+1;
        }
    	cout << changes  << "\n" << s << endl;
    }
    return 0;
}