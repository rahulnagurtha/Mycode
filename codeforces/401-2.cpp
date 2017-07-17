#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;


int main(){
    int n=0;
    cin>>n;
    int a1[n],a2[n],b1[n],b2[n];
    int x=0,y=0,u=0,v=0,i=n-1;
    cin>>x;
    cin>>y;
    u=x;
    v=y;

    if(u==0){
        for(int i=0;i<n;i++)
            a1[i]=0;
    }
    while(u!=0){
        a1[i]=u%10;
        a2[i]=a1[i];
        i--;
        u/=10;
    }
    i=n-1;
    if(v==0){
        for(int i=0;i<n;i++){
            b1[i]=0;
            b2[i]=0;
        }
    }
    while(v!=0){
        b1[i]=v%10;
        b2[i]=b1[i];
        i--;
        v/=10;
    }
    int j=0,m=0;
    std::sort(b1,b1+n);
    for(int i=0;i<n;i++){
        //(lower_bound(b1, b1+n,a1[i]) - b1)
        if(a1[i]>b1[n-1]){
            m++;
            int h=(upper_bound(b1, b1+n,0) - b1);
            b1[h]=-1;
            std::sort(b1,b1+n);
        }
        else{
            int k=(upper_bound(b1, b1+n,a1[i]) - b1);
            b1[k]=-1;
            std::sort(b1,b1+n);
        }
    }
    cout<<m<<endl;

    int mx=0;
    std::sort(b2,b2+n);
    for(int i=0;i<n;i++)
    {
        if(a1[i]>=b2[n-1]){
           // m++;
            int h=(upper_bound(b2, b2+n,0) - b2);
            b2[h]=-1;
            std::sort(b2,b2+n);
        }
        else{
            int k=(upper_bound(b2, b2+n,a1[i]+1) - b2);
            mx++;
            b2[k]=-1;
            std::sort(b2,b2+n);
        }
    }
    cout<<mx<<endl;
    return 0;
}