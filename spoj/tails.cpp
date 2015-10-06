#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;

vector<vector<string> > graph(1500000);
bool status[1500000];
string inp;

string DecToBin(int number){
string result = "";
do {
if((number&1)==0)
result+="0";
else
result+="1";
number>>=1;
}while(number);
reverse(result.begin(),result.end());
return result;
}

inline int BinToDec(string input) {
int result = 0 ;
int temp = 1 << 19;
for (int i = 19; i >= 0; --i) {
result += (int(input[20-i-1]-48))*temp;
temp = temp >> 1 ;
}
return result;
}

// main code begins now

int main()
{
int num,temp1,foo,answer = 0,curlayer = 0,flag = 0,temp2,temp3;
string cur,pre;
deque<pair<string,int> > layers;
for (int i = 0; i < 20; ++i) {
scanf("%d",&num);
inp += char(48 + num);
}
num = BinToDec(inp);
if(num == 0) {
printf("0\n");
return 0;
}
temp1 = 1 << 20;
for (int j = 0; j < temp1; ++j) {
status[j]=false;
}
layers.push_back(mp(inp,0));
status[num] = true;
while(!layers.empty()) {
pre = "";
if((layers.front()).SS == curlayer) {
curlayer++;
}
cur = (layers.front()).FF;
if(cur.size() < 20) {
for (int j = cur.size()+1; j <= 20 ; ++j) {
pre += '0';
}
pre = pre + cur;
}
else pre = cur;
cur = pre;
cur[1] = char(48+((int((pre[1]-48))+1)%2));
cur[0] = char(48+((int((pre[0]-48))+1)%2));
temp2 = BinToDec(cur);
if (status[temp2] == false) {
status[temp2] = true;
layers.push_back(mp(cur,curlayer));
}
cur = pre;
cur[19] = char(48+((int((pre[19]-48))+1)%2));
cur[18] = char(48+((int((pre[18]-48))+1)%2));
temp2 = BinToDec(cur);
if (status[temp2] == false) {
status[temp2] = true;
layers.push_back(mp(cur,curlayer));
}
for (int j = 1; j < 19; ++j) {
cur = pre;
cur[j-1] = char(48+((int((pre[j-1]-48))+1)%2));
cur[j+1] = char(48+((int((pre[j+1]-48))+1)%2));
cur[j] = char(48+((int((pre[j]-48))+1)%2));
temp2 = BinToDec(cur);
if (status[temp2] == false) {
status[temp2] = true;
layers.push_back(mp(cur,curlayer));
}
}
if(status[0] == true) flag = 1;
if((layers.front()).SS > answer) answer++;
if(flag == 1) break;
layers.pop_front();
}
//end of bfs

if (status[0] == true) {
printf("%d\n",answer+1);
}
return 0;
}