#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>



// 4,8,11,14,17
using namespace __gnu_pbds;
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int primes[] = {2,3,5,7,11,13,17,19};
int t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    long long subset = (1<<8) - 1;
    long long ans = 0;
    for(long long i = 1; i<=subset; i++){
        long long deno = 1;
        int setbits =  __builtin_popcount(i);
        for(long long j = 0; j<=7; j++) if((i&(1<<j)) > 0) deno = deno * primes[j];
        if(setbits&1 > 0) ans+= (n/deno);
        else ans-=(n/deno); 
    }
    cout<<ans<<"\n";

}

    return 0;
}
