#include <bits/stdc++.h>      

using namespace std;

// vector<int> binarySearch(vector<int>& random); //pass by reference


vector<int> binarySearch(vector<int> random); //pass by value

//accessing is same in both value and reference

int main()
{
    vector<int> random(100);
    vector<int> rec;
    int search4, found;
    int first ;
    int last;
    for (int i = 0; i < 100; ++i)
    {
        random[i]=i;
    }
    // cin >> search4 ;

    rec = binarySearch(random);
    for (int i = 0; i < 100; ++i)
    {
        cout << random[i] << " " ;
    }
    printf("\n\n");
    for (int i = 0; i < 50; ++i)
    {
        cout << rec[i] << " " ;
    }
}

vector<int> binarySearch(vector<int>& random)
{
    vector<int> yoo(50);
    for (int i = 0; i < 100; ++i)
    {
        random[i]=100+i;
    }
    for (int i = 0; i < 50; ++i)
    {
        yoo[i]=200+i;
    }
    return yoo;
}