#include <bits/stdc++.h>
using namespace std;
#define ll     long long
int main() {

    string s;
    cin>>s;
    ll len = s.length();
    ll ans = (1<<(len)) - 2;
    for(ll i = (len -1),pos = 0; i>=0, pos<=(len -1); i--,pos++){
        if( s[i] == '7') ans += (1<<pos);
    }

    cout<<ans+1;
     return 0;
}