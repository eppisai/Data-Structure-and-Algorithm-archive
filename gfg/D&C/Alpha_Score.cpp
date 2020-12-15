// You are climbing up using stairs where a number is written on each stair. 
// At each step we define the alpha score as sum of all the numbers previously seen on the stairs
// which are smaller than the present number. Alpha score of the whole journey is defined as 
// the sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.

// Input Format
// First line contains a single integer n denoting the number of stairs. Next line contains 
// n space separated integers denoting the numbers written on stairs.

// Constraints
// 1 <= n <= 10^5 Every number written on stair lies between [0,10^9]

// Output Format
// Single integer denoting the alpha score of the journey modulus 1000000007.

// Sample Input
// 5
// 1 5 3 6 4
// Sample Output
// 15

#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000000007

using namespace std;
typedef long long ll;

ll cross(ll *a,ll left,ll mid,ll right)
{
    ll i,j,k;
    ll alphasum=0;

    i=left;
    j=mid;
    vector<ll> b;
    while((i<=mid-1) && (j<=right))
    {
        if(a[i]<a[j])
        {   
            alphasum=(alphasum+(a[i]*(right-j+1))%M)%M;
            b.push_back(a[i]);
            i++;
            
        }
        else
        {
             b.push_back(a[j]);
            j++;
        
        }
    }
    while(i<=mid-1)
    {
        b.push_back(a[i]);
        i++;
    }
    while(j<=right)
    {
         b.push_back(a[j]);
         j++;
    }
    for(int i=left,j=0;j<b.size();i++,j++)
        a[i]=b[j];
    

    return alphasum;
}

ll merge(ll *a,ll n,ll left,ll right)
{   
    if(left>=right)
        return 0;
    ll mid;
    ll alpha=0;

    mid=(left+right)/2;

    alpha=merge(a,n,left,mid);
    alpha+=merge(a,n,mid+1,right);

    alpha+=cross(a,left,mid+1,right);

    return alpha%M;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll a[n];

    for(ll i=0;i<n;i++)
    cin>>a[i];

    ll res=merge(a,n,0,n-1);

    cout<<res<<endl;
    return 0;   
}