#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// Complete the counterGame function below.
long lousie(long n)
{   int k;
    if(n%2==0)
    {
        k=n/2;
        return k;
    }
    else
    {
        int l=2;
        while(l<n)
        {
            l=pow(2,2);
        }
        return (n-l);
    }
}
long richard(long n)
{   int k1;
    if(n%2==0)
    {
        k1=n/2;
        return k1;
    }
    else
    {
        int l1=2;
        while(l1<n)
        {
            l1=pow(2,2);
        }
        return (n-l1);
    }
}
string counterGame(long n) {
    int k=0;
    while(n!=1)
    { n=lousie(n);
    k++;
      if(n!=1)
        {
           n = richard(n);
           k++;
        }
    }
    if(k%2==0)
    {
        return "Louise";

    }
    else{
        return "Richard";
    }



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
