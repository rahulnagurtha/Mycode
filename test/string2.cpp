#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  string s0 ("Initial string");

  // constructors used in the same order as described above:
  string s1;
  string s2 (s0);
  string s3 (s0, 8, 3);
  string s4 ("A character sequence", 6);
  string s5 ("Another character sequence");
  string s6 (10, 'x');
  string s7a (10, 97);      // 42 is the ASCII code for '*'
  string s7b (s0.begin(), s0.begin()+7);

  cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
  cout << "\ns7a: " << s7a << "\ns7b: " << s7b << '\n';

  std::string str;
  std::string str2="Writing ";
  std::string str3="print 10 and then 5 more";

  // used in the same order as described above:
  str.append(str2);                       // "Writing "
  str.append(str3,6,3);                   // "10 "
  str.append("dots are cool",5);          // "dots "
  str.append("here: ");                   // "here: "
  str.append(10,97);                    // ".........."
  str.append(str3.begin()+8,str3.end());  // " and then 5 more"
  str.append<int>(5,0x2E);                // "....."

  std::cout << str << '\n';
  //str.reverse();
  str.resize(100,'+');
  for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
    {
    std::cout << *it ;}
  std::cout << '\n';
  //cout << str.at(300) ;
  char d='z';
  std::string name ("John");
  std::string family ("Smith");
  name += " K. ";         // c-string
  name += family;
  name += d;         // string
  name += '\n';           // character

  std::cout << name << "\n" ;
  std::cout << name.find(" ");
  return 0;
}
