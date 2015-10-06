// string::erase
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string str[10];
  cout << "enter the names\n" ;
  for(int i=0;i<10;i++)
    getline(cin,str[i]);
  for(int i=0;i<9;i++)
  {
      cout << str[i].compare(str[i+1]) << " " << str[i] <<  " " << str[i+1] << endl ;
  }
  cout <<
  return 0;
}
