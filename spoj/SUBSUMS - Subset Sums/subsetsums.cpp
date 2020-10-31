#include<bits/stdc++.h>
using namespace std;
#define ll    long long
vector<ll> v1,v2;
 
vector<ll> subset(int n, vector<ll> v){
    vector<ll> ans;
    for(int i = 0; i<(1<<n); i++){
       
        int sum = 0, j = 0; 
        for(int no = i; no > 0; no = no>>1){
           if(no&1) sum += v[j];
           j++;
        }  
 
        ans.push_back(sum);  
}
 
return ans;
}
 
 
int main(){
//   #ifndef ONLINE_JUDGE
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);
//  #endif
    ll n,a,b, an = 0;
    cin>>n>>a>>b;
    ll n1 = n/2;
    ll n2 = n - n1;
    for(ll i = 0; i<n1;i++){
        ll x;
        cin>>x;
        v1.push_back(x);
    }
 
    for(ll i = 0; i<n2;i++){
        ll x;
        cin>>x;
        v2.push_back(x);
    }
   
   vector<ll> sv1 = subset(n1,v1);
   vector<ll> sv2 = subset(n2,v2);
 
   sort(sv2.begin(), sv2.end());
 
   for(auto x: sv1){
       vector<ll>::iterator low,high;
       low  = lower_bound(sv2.begin(), sv2.end(), (a -x));
       high = upper_bound(sv2.begin(), sv2.end(), (b -x));
       an += (high - sv2.begin()) - (low - sv2.begin());
   }
 
   cout<<an;
 
  return 0;
}