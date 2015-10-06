#include <bits/stdc++.h>

using namespace std;



int let[4][1000006];



// main code begins now

int main()
{
    memset(let[0],0,sizeof(let[0]));
    memset(let[1],0,sizeof(let[1]));
    memset(let[2],0,sizeof(let[2]));
    memset(let[3],0,sizeof(let[3]));
	// freopen("in.txt", "r", stdin);
    int t,l,r;
    long long int ans;
    vector<map<string,long long int> > data(1000006);
    // string special;
    char test,a,b,special[1000005];
	scanf("%s",special);
    if (special[0]=='c') {
        let[0][0]=1;
    }
    else if (special[0]=='h') {
        let[1][0]=1;
    }
    else if (special[0]=='e') {
        let[2][0]=1;
    }
    else {
        let[3][0]=1;
    }
	data[0].insert(make_pair("ch",0));
	data[0].insert(make_pair("ce",0));
	data[0].insert(make_pair("cf",0));
	data[0].insert(make_pair("hc",0));
	data[0].insert(make_pair("he",0));
	data[0].insert(make_pair("hf",0));
	data[0].insert(make_pair("ec",0));
	data[0].insert(make_pair("eh",0));
	data[0].insert(make_pair("ef",0));
	data[0].insert(make_pair("fc",0));
	data[0].insert(make_pair("fh",0));
	data[0].insert(make_pair("fe",0));
    for (int i = 1; i < strlen(special); ++i) {
    	data[i].insert(make_pair("ch",0));
    	data[i].insert(make_pair("ce",0));
    	data[i].insert(make_pair("cf",0));
    	data[i].insert(make_pair("hc",0));
    	data[i].insert(make_pair("he",0));
    	data[i].insert(make_pair("hf",0));
    	data[i].insert(make_pair("ec",0));
    	data[i].insert(make_pair("eh",0));
    	data[i].insert(make_pair("ef",0));
    	data[i].insert(make_pair("fc",0));
    	data[i].insert(make_pair("fh",0));
    	data[i].insert(make_pair("fe",0));

    	test=special[i];
    	if(test=='c') {
    		let[0][i]=let[0][i-1]+1;
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1];

    		data[i]["hc"]=data[i-1]["hc"]+let[1][i-1];
    		data[i]["ec"]=data[i-1]["ec"]+let[2][i-1];
    		data[i]["fc"]=data[i-1]["fc"]+let[3][i-1];
            data[i]["ch"]=data[i-1]["ch"];
            data[i]["eh"]=data[i-1]["eh"];
            data[i]["fh"]=data[i-1]["fh"];
            data[i]["ce"]=data[i-1]["ce"];
            data[i]["he"]=data[i-1]["he"];
            data[i]["fe"]=data[i-1]["fe"];
            data[i]["cf"]=data[i-1]["cf"];
            data[i]["hf"]=data[i-1]["hf"];
            data[i]["ef"]=data[i-1]["ef"];

    	}
    	else if(test=='h') {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1]+1;
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1];

    		data[i]["ch"]=data[i-1]["ch"]+let[0][i-1];
            data[i]["eh"]=data[i-1]["eh"]+let[2][i-1];
            data[i]["fh"]=data[i-1]["fh"]+let[3][i-1];
            data[i]["hc"]=data[i-1]["hc"];
            data[i]["ec"]=data[i-1]["ec"];
            data[i]["fc"]=data[i-1]["fc"];
            data[i]["ce"]=data[i-1]["ce"];
            data[i]["he"]=data[i-1]["he"];
            data[i]["fe"]=data[i-1]["fe"];
            data[i]["cf"]=data[i-1]["cf"];
            data[i]["hf"]=data[i-1]["hf"];
            data[i]["ef"]=data[i-1]["ef"];
        }
    	else if(test=='e') {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1]+1;
    		let[3][i]=let[3][i-1];
    		
            data[i]["ce"]=data[i-1]["ce"]+let[0][i-1];
            data[i]["he"]=data[i-1]["he"]+let[1][i-1];
            data[i]["fe"]=data[i-1]["fe"]+let[3][i-1];
            data[i]["hc"]=data[i-1]["hc"];
            data[i]["ec"]=data[i-1]["ec"];
            data[i]["fc"]=data[i-1]["fc"];
            data[i]["ch"]=data[i-1]["ch"];
            data[i]["eh"]=data[i-1]["eh"];
            data[i]["fh"]=data[i-1]["fh"];
            data[i]["cf"]=data[i-1]["cf"];
            data[i]["hf"]=data[i-1]["hf"];
            data[i]["ef"]=data[i-1]["ef"];
        }
    	else {
    		let[0][i]=let[0][i-1];
    		let[1][i]=let[1][i-1];
    		let[2][i]=let[2][i-1];
    		let[3][i]=let[3][i-1]+1;
    	    
            data[i]["cf"]=data[i-1]["cf"]+let[0][i-1];
            data[i]["hf"]=data[i-1]["hf"]+let[1][i-1];
            data[i]["ef"]=data[i-1]["ef"]+let[2][i-1];
            data[i]["hc"]=data[i-1]["hc"];
            data[i]["ec"]=data[i-1]["ec"];
            data[i]["fc"]=data[i-1]["fc"];
            data[i]["ch"]=data[i-1]["ch"];
            data[i]["eh"]=data[i-1]["eh"];
            data[i]["fh"]=data[i-1]["fh"];
            data[i]["ce"]=data[i-1]["ce"];
            data[i]["he"]=data[i-1]["he"];
            data[i]["fe"]=data[i-1]["fe"];
        }
        // printf("after %d :\n",i);
        // cout << "ch-" << data[i]["ch"] << endl ;
        // cout << "ce-" << data[i]["ce"] << endl ;
        // cout << "cf-" << data[i]["cf"] << endl ;
        // cout << "hc-" << data[i]["hc"] << endl ;
        // cout << "he-" << data[i]["he"] << endl ;
        // cout << "hf-" << data[i]["hf"] << endl ;
        // cout << "ec-" << data[i]["ec"] << endl ;
        // cout << "eh-" << data[i]["eh"] << endl ;
        // cout << "ef-" << data[i]["ef"] << endl ;
        // cout << "fc-" << data[i]["fc"] << endl ;
        // cout << "fh-" << data[i]["fh"] << endl ;
        // cout << "fe-" << data[i]["fe"] << endl ;
    }
    scanf("%d",&t);
    getchar();
    while(t--) {
    	string tbsrchd;
        scanf("%c %c %d %d",&a,&b,&l,&r);
    	// cin >> a >> b >> l >> r ;
    	tbsrchd.push_back(a);
    	tbsrchd.push_back(b);
    	// cout << tbsrchd << endl ;
    	if(l==1) ans=data[r-1][tbsrchd];
    	else if(a=='c' && b=='h') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[0][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else if(a=='c' && b=='e') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[0][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
        else if(a=='c' && b=='f') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[0][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='h' && b=='c') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[1][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='h' && b=='e') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[1][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
        else if(a=='h' && b=='f') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[1][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='e' && b=='c') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[2][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='e' && b=='h') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[2][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else if(a=='e' && b=='f') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[2][l-2]*(let[3][r-1]-let[3][l-2]) );
        }
        else if(a=='f' && b=='c') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[3][l-2]*(let[0][r-1]-let[0][l-2]) );
        }
        else if(a=='f' && b=='h') {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[3][l-2]*(let[1][r-1]-let[1][l-2]) );
        }
        else {
            ans=data[r-1][tbsrchd]-data[l-2][tbsrchd]-(let[3][l-2]*(let[2][r-1]-let[2][l-2]) );
        }
    	printf("%lld\n",ans);
    	// cout << ans << endl ;
        getchar();
    }
    return 0;
}