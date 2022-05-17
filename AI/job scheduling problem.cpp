//job scheduling problem
#include<bits/stdc++.h>
using namespace std;

struct Job
{
   char id;
   int dead;
   int profit;
};

bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}

void scheduleJobs(Job arr[], int n)
{
    sort(arr, arr+n, comparison);

    int result[n];
    bool slot[n];

    for(int i=0; i<n; i++)
        slot[i] = false;

    int maxProfit = 0;
    for(int i=0; i<n; i++)
    {
       for(int j=min(n, arr[i].dead)-1; j>=0; j--)
       {
          if(slot[j]==false)
          {
             maxProfit += arr[i].profit;
             result[j] = i;
             slot[j] = true;
             break;
          }
       }
    }


    for(int i=0; i<n; i++)
       if(slot[i])
         cout<<"\t" <<arr[result[i]].id << " ";

    cout<<"\n The maximum profit earned is --> "<<maxProfit<<endl;
}

int main()
{
    cout<<"\n Enter the number of Jobs : ";
    int n; cin>>n;
    Job arr[n];
    cout<<"\n Enter the Job id, Deadline and Profit for all jobs --> \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].id;
        cin>>arr[i].dead;
        cin>>arr[i].profit;
    }


    cout << "\n\t ---- The Sequence in which the Jobs are completed ----\n";
    scheduleJobs(arr, n);
    return 0;
}
/*Enter the number of Jobs : 6
Enter the Job id, Deadline and Profit for all jobs --> 
0 1 5
1 2 10
2 3 100
3 3 50
4 4 200
5 4 250
6 5 50
*/

