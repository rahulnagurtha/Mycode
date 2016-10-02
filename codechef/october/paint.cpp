#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
 
int main() {

	long long int count1=0;
	long long int count2=0;
	ostringstream oss,oss1;
	string str="";
	string str2="";

	int n,m,k;int w,v;
	scanf("%d%d%d",&n,&m,&k);

	vector<vector<int> > v1(n+1);
	vector<vector<int> > v2(m+1);
 
	for(int i=0;i<k;i++) {
		scanf("%d%d",&w,&v);
		v1[w].push_back(v);
		v2[v].push_back(w);
	}


	for(int i=1;i<=n;i++) sort(v1[i].begin(),v1[i].end());
	for(int i=1;i<=m;i++) sort(v2[i].begin(),v2[i].end());


	vector<int>::iterator u;

	for(int i=1;i<=n;i++) {
		if(v1[i].size()==0) {
			count1++;
			oss << i ;
			str=str+oss.str()+" "+"1 "+"0\n";
		}
		
		else {
			u=v1[i].begin();
			if(*v1[i].begin()!=1) {
				count1++;
				oss << i ;
				str=str+oss.str()+" "+"1 "+"0\n";
			}
			
			if(*(v1[i].end()-1)!=m) {
				count1++;
				oss << i ;
				oss1 << m ;
				str=str+oss.str()+" "+oss1.str()+" "+"0\n";
			}
			u++;
			while(u!=v1[i].end()) {
				if(*u-*(u-1)>1) {
					count1++;
					oss << i ;
					oss1 << (*u-1) ;
					str=str+oss.str()+" "+oss1.str()+" "+"0\n";
				}	
				u++;	
			}
	
	
		}
	}
	
	for(int i=1;i<=m;i++) {
		if(v2[i].size()==0) {
			count2++;
			oss << i ;
			str2=str2+"1 "+oss.str()+" 1\n";
		}
		else {
			u=v2[i].begin();
			if(*v2[i].begin()!=1) {
				count2++;
				oss << i ;
				str2=str2+"1 "+oss.str()+" 1\n";
			}
			if(*(v2[i].end()-1)!=n) {
				count2++;
				oss << i ;
				oss1 << n ;
				str2=str2+oss1.str()+" "+oss.str()+" 1\n";
			}
			u++;
			while(u!=v2[i].end()) {
				if(*u-*(u-1)>1) {
					count2++;
					oss << i ;
					oss1 << (*u-1) ;
					str2=str2+oss1.str()+" "+oss.str()+" 1\n";
				}
				u++;
	
	
			}
	
	
		}

	}
	if(count2>=count1) cout<<count1<<"\n"<<str;
	else cout<<count2<<"\n"<<str2;
	return 0;
} 
