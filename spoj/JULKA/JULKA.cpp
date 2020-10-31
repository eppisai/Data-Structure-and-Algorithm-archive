#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ff                first;
#define ss                second;
#define pb                push_back;
#define mp                make_pair;
#define pii               pair<int,int>
#define vi                vector<int>
#define mii               map<int,int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int, vector<int>, greater<int>>
#define setbits(x)        __buildin_popcountll(x)
#define mod               1000000007
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type *arr=new type[n];
#define w(t)              int t; cin>>t; while(t--)



vector<int> add(vector<int> x, vector<int> y){

  // Reverse  the numbers so we can add them from unit's place
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  vector<int> ans; // our final answer

  int len = min(x.size(), y.size()), carry = 0;
  for (int i = 0; i < len; i++)
  {
      int val = x[i] + y[i] + carry;
      carry = val/10;
      ans.push_back(val%10);
  }
   if(x.size() > len){
       for(int i = len; i<x.size(); i++){
              int val = x[i] + carry;
              carry = val/10;
              ans.push_back(val%10);
       }
   }

   if(y.size() > len){
       for(int i = len; i < y.size(); i++){
           int val = y[i] + carry;
           carry = val%10;
           ans.push_back(val%10);
       }
   }
   
   while(carry){
       ans.push_back(carry%10);
       carry/=10;
   }

   //Reverse the ans to get back actual and return.
   reverse(ans.begin(), ans.end());
   return ans;
  
}

vector<int> sub(vector<int> x, vector<int> y){
  
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    
    vector<int> ans;
    int len = y.size();
    for(int i = 0; i < len; i++){
        if(x[i] < y[i]){
            x[i+1]--;
            ans.push_back(x[i] + 10 -y[i]);
        }

        else ans.push_back(x[i] - y[i]);
    }

    if(x.size() > len){
        for(int i = len; i <x.size(); i++){

            if(x[i] < 0){
                x[i+1]--;
                ans.push_back(x[i]);
            }

            else{
                ans.push_back(x[i]);
            }
        }
    }

    reverse(ans.begin(), ans.end());

    vector<int> arr;
    int i = 0;
    while(ans[i] == 0) i++;    // omit the leading zeros and return result
    for(; i < ans.size(); i++) arr.push_back(ans[i]);

    return arr;
}

vector<int> divby2(vector<int> x){
    
    vector<int> ans;
    int val = 0, len = x.size();
    for(int i = 0; i<len; i++){
           if(val){
               val = val*10 + x[i];
               ans.push_back(val/2);
               val = val%2;
           }

           else{
               if(x[i] < 2){
                   val += x[i];
                   ans.push_back(0);
               }
               else{
                   val = x[i]%2;
                   ans.push_back(x[i]/2);
               }
           }
    }

    vector<int> arr;
    int i = 0;
    while(ans[i] == 0) i++;
    for(; i < ans.size(); i++){
        arr.push_back(ans[i]);
    }   

    return arr; 
}

int main()
{

 
int t = 10;
while(t--){
   string Ss, Ds;
   cin>>Ss;
   cin>>Ds;
   vector<int> S,D,sm,df,div;
   for(int i = 0; i<Ss.size(); i++) S.push_back(Ss[i] - '0');
   for(int i = 0; i<Ds.size(); i++) D.push_back(Ds[i] - '0');
   sm = add(S,D);
   df = sub(S,D);
   sm = divby2(sm);
   df = divby2(df);

   for(int i = 0; i< sm.size(); i++) cout<<sm[i];
   cout<<endl;

   
   for(int i = 0; i< df.size(); i++) cout<<df[i];
    cout<<endl;
}
    return 0;
}
