#include <bits/stdc++.h>

using namespace std;

int verty[105],vertx[105];

int pnpoly(int nvert, int testx, int testy)
{
    int i, j, c = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((verty[i]>testy) != (verty[j]>testy)) &&
        (testx < (vertx[j]-vertx[i])*(testy-verty[i])/(verty[j]-verty[i]) + vertx[i]) )
           c = !c;
    }
    return c;
}



int main ()
{
    int n,x,y;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> vertx[i] >> verty[i];
    }
    cin >> x >> y ;
    printf("%d\n",pnpoly(n,x,y));
    return 0;
}