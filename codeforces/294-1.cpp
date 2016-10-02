#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
	char b[9][9];
	int black=0,white=0;
    map<char,int> score;
    map<char,int> weight;
    weight['Q']=9;
    weight['R']=5;
    weight['B']=3;
    weight['N']=3;
    weight['P']=1;
    weight['K']=0;
    weight['q']=9;
    weight['r']=5;
    weight['b']=3;
    weight['n']=3;
    weight['p']=1;
    weight['k']=0;

    score['Q']=0;
    score['R']=0;
    score['B']=0;
    score['N']=0;
    score['P']=0;
    score['K']=0;
    score['q']=0;
    score['r']=0;
    score['b']=0;
    score['n']=0;
    score['p']=0;
    score['k']=0;
    // freopen("in.txt", "r", stdin);
    for (int j = 0; j < 8; ++j) {
    	for (int i = 0; i < 8; ++i) {
    		scanf("%c",&b[j][i]);
    	}
    	getchar();
    }
    for (int i = 0; i < 8; ++i) {
    	for (int j = 0; j < 8; ++j) {
    		// scanf("%c",&b[j][i]);
    		if(b[i][j]!='.') score[b[i][j]]+=weight[b[i][j]];
    	}
    }
    white=score['Q']+score['R']+score['B']+score['N']+score['P']+score['K'];
    black=score['q']+score['r']+score['b']+score['n']+score['p']+score['k'];
    if (white>black)
    {
    	printf("White\n");
    }
    else if(white<black) {
    	printf("Black\n");
    }
    else printf("Draw\n");
    return 0;
}