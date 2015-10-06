#include <bits/stdc++.h>

using namespace std;


long long int recur(int n) {
	while(n%2==0) {
        n=(n>>1);
    }
    return n ;
}


// main code begins now

int main()
{
    clock_t start, end;
    double cpu_time_used,f;
    f=22.0/7;
    int t,n;
    start = clock();
    cin >> n ;
    long long int sum=0;
    for (int i = 1; i <=n ; ++i) {
        sum+=recur(i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lld\n",sum );
    printf("fun() took %f seconds to execute \n", cpu_time_used);
    cout << setprecision(51) << f << '\n';
    cout << setprecision(66) << f << '\n';
    return 0;
}