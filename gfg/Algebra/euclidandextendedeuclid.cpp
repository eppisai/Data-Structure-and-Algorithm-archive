#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    //base case
    if(b == 0) return a;

    //recursive case
    return gcd(b,a%b);
}

int x,y,gc;
void extendedEuclidMethod(int a, int b){
    //base case
    if(b == 0){
        x = 1;
        y = 0;
        gc = a;
        return;
    }

    //recursive case
    extendedEuclidMethod(b,a%b);
    int Cx = y;
    int Cy = x - (a/b)*y;
    x = Cx;
    y = Cy;
}


int main()
{   
    cout<<gcd(15,10)<<"\n";

    //18x + 30y = 6
    extendedEuclidMethod(18,30);
    cout<<x<<" "<<y;
     

     return 0;
}