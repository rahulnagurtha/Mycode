#include <bits/stdc++.h>


using namespace std;




typedef long long int lint;
#define inf 1000000009
int main()
{
	int t;
	//printf("pro not started\n");
	cin >> t ;
	char array[100005];
	
	while(t--) {
		//printf("entered into while loop\n");
		memset( array, '\0', sizeof(array) );
		int n,m,temp1,min=1000000;
		lint ans=1;
		char temp;
		cin >> n >> m ;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp >> temp1 ;
			if(min>temp1) min=temp1;
			array[temp1]=temp;
		}
		if(m==1) 
		{
			cout << "1" << endl;
			continue;
		}
		int one,two,count=m-1;
		one=min;
		for (int i = min+1 ; i <= n; ++i)
		{
			if((count>0) && (array[i]!='\0') )
			{
				if((array[one]==array[i])) 
				{
					//printf("same colour at %d and %d\n",one,i);
					//array[one]='\0';
					one=i;
				}
				else
				{
					//printf("different colour at %d and %d\n",one,i);
					//array[one]='\0';
					ans=(ans*(i-one)%inf)%inf;
					one=i;
				}
				count--;
			}
		}


		ans=ans%inf;
		cout << ans << endl ;
	}
	return 0;
}