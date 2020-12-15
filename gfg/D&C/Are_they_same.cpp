// This year when tourist visited India for codsule 2019. He and Rajat started discussing
//  few problems on divide and conquer. tourist asked Rajat that if you have 2 strings s1
//   and s2 can you find if they are equivalent. Rajat then asked the condition for being 
//   equivalent to which tourist replied

// Two strings a and b of equal length are called equivalent in one of the two cases:

// They are equal.
// If we split string a into two halves of the same size a1 and a2, and string b into two 
// halves of the same size b1 and b2, then one of the following is correct:
// a1 is equivalent to b1, and a2 is equivalent to b2
// a1 is equivalent to b2, and a2 is equivalent to b1
// Rajat quickly solved the problem can you?

// Input Format
// First line is number of test cases t Then follow two strings each of same length

// Constraints
// 1 <= test cases <= 10 1 <= string length <= 50000

// Output Format
// print "YES" if they are "equivalent" and "NO" if they are not

// Sample Input
// 3
// ababa
// baaba
// ab
// ba
// abc
// abc
// Sample Output
// NO
// YES
// YES
// Explanation
// test case 1 : - you cannot split the string into two halves of same size and s1 != s2 
// hence they are not same 
// test case 2 :- split ab as a and b and ba as b and a then conditon is fulfilled 
// test case 3 :- they are already same

#include<bits/stdc++.h>
using namespace std;
bool fun(string s1,string s2)
{
    string a1,a2,b1,b2;
        if(s1==s2)
            return true;//cout<<"YES"<<endl;
		else if(s1.length()!=s2.length())
		{
			return false;//cout<<"NO"<<endl;
		}
		else if(s1.length()==1)
		    return false;
		else
		{
            //cout<<"final mei aaye";
            int len = s1.length();
            if(len%2==1)
                return false;
            int half = (len+1)/2;
            a1=s1.substr(0,half);
            a2=s1.substr(half,len-half);
            b1=s2.substr(0,half);
            b2=s2.substr(half,len-half);
			
            if((fun(a1,b2) && fun(a2,b1)) or (fun(a2,b2) && fun(a1,b1)))
                return true;//cout<<"YES"<<endl;
            else return false;// cout<<"NO"<<endl;

		}
}
int main() {
	//return 0;
	int t;
	cin>>t;
	while(t--)
	{
	    //cout<<"test";
		string s1,s2;
		cin>>s1>>s2;
        if(fun(s1,s2))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
		
	}
}