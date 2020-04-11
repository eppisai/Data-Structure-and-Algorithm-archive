#include <iostream>
using namespace std;


int ans(int i)
{    int an=0;
     while(i)
	   { an += i % 10;
	     i = i/10;
	   }
	 return an;  
} 

int main() {
    int u =0;
    int inp;
    cin>>inp;
	for(int i = 18; i<=100000000; i++)
	 { int temp = i;
	   if(ans(i) == 10)
	   { u++;
	     if(u == inp)
	      {
	          cout<<temp<<endl;
	          break;
	      }
	       
	   }
	   
	 }
}