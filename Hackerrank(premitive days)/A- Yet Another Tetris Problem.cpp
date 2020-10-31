#include <bits/stdc++.h> 
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc>0)
	{   bool ans = false;
	    int sz;
	    cin>>sz;
	    int tet[sz];
	    int temp;
	    for(int i = 0; i<sz ; i++) cin>>tet[i];
	    for(int j = 0; j<sz ; j++)
	     {   for(int k = 0; k<sz ; k++)
	          {int diff=abs(tet[j] - tet[k]);
	           if(diff%2 !=0) {
	               ans = false;
	               break;
	           }
	           else ans = true;
	          }
	     }
	    if(ans == true) {cout<<"YES"<<endl;}
	    if(ans == false)
	    {cout<<"NO"<<endl;}
   tc--;
	}
	
	return 0;
}