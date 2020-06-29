#include<bits/stdc++.h>
using namespace std;
const int R = 100005;
int p[R];
vector<int> primes ;

void  seive(){
    for(int i = 2; i<100005; i++){
        if(p[i] == 0){ 
            primes.push_back(i);
            for(int j = i; j<100005; j+=i){
                p[j] = 1;
                
            }
            
        }
    }
}


 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    seive();
    while(t--){
        int n,m,ans =0;
        cin>>m>>n;
        int seg[n-m+1] = {0};
        for(auto x: primes) {
            if(x*x > n) break;
            int start = (m/x)*x;
            if(x>=m) start = x+x;
            while(start < m) start+=x;
            while(start< n-m+1){
                seg[start-m] = 1;
                start+=x;
            }
            
        }
        for(int i = 1; i<n-m; i++) if(seg[i]==0) cout<<i+m<<"\n";
        cout<<"\n\n\n";
        
            
    }

    return 0;
 
}