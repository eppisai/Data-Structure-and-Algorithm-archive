#include <bits/stdc++.h>
using namespace std;

#define ll                long long
#define w(t)              int t; cin>>t; while(t--)
int hash_str[256];


int main()
{ 
    w(t){
     ll n;
     cin>>n;
     n = n/2;
     ll ar[n+1], ans = 0;;
     ar[0] = 0;
     for(int i = 1; i <= n; i++){
         ar[i] = 8*i;
     }
     for(int i = n; i > 0; i--){
         ans += ar[i];
         ar[i - 1] += ar[i];
     }
     
     cout<<ans<<"\n";
    }
    return 0;
}