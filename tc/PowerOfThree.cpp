#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PowerOfThree {
public:
	string ableToGet(int x, int y)
    {
        // to save us the issue of dealing with the % operation being flawed with
        // negative numbers, we can just use some symmetry, 
        // (x,y) is reachable if and only if (-x,y), (-x,-y) and (x,-y) are.
        x = abs(x);
        y = abs(y);
        while (x != 0 || y != 0) {
            // one of x,y must be a multiple of 3, the other shouldn't.
            if ( (x % 3 == 0) && (y % 3 != 0) ) {
                // If y % 3 == 2, the result is y/3 + 1 or (y+1) / 3.
                if (y % 3 == 2) {
                    y = (y + 1) / 3;
                } else {
                    y = (y - 1) / 3;
                }
                x /= 3;
            } else if ( (y % 3 == 0) && (x % 3 != 0) ) {
                if (x % 3 == 2) {
                    x = (x + 1) / 3;
                } else {
                    x = (x - 1) / 3;
                }
                y /= 3;
            } else {
                return "Impossible";
            }
        }
        return "Possible";
    }
};
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!