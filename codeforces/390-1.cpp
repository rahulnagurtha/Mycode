#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,b,a)  for(i=a;i<b;i++)
#define f(i,n)      rep(i,n,0)
#define maxn 100010
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,i;
	cin>>n;
	int a[n];
	f(i,n) cin>>a[i];
	int pref[n],suff[n];
	pref[0]=a[0];suff[n-1]=a[n-1];
	f(i,n-1) pref[i+1] = pref[i] + a[i+1];
	for(i=n-2;i>=0;i--) suff[i] = suff[i+1] + a[i];
	f(i,n-1)
	{
		if(pref[i]!=0 and suff[i+1]!=0)
		{
			cout<<"YES\n2\n1 ";
			cout<<i+1<<endl;
			cout<<i+2<<" "<<n;
			return 0;
		}
	}
	cout<<"NO";
return 0;
}