#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 300001
using namespace std;
typedef long long lld;
 
lld l, r;
lld ret = 0LL;
lld br = 1;
int poz = 0;
 
int main()
{
    cin >> l >> r;
    lld razl = r - l;
    while (razl >= br)
    {
        ret += br;
        br *= 2;
        poz++;
    }
    while (r >= br)
    {
        if ((((l>>poz)^(r>>poz))&1LL)==1LL) ret += br;
        br *= 2;
        poz++;
    }
    cout << ret << endl;
    return 0;
}