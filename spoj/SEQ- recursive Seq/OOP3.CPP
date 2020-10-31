#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct customer
{
    long account_no;
    char name[80];
    long balance;
    long ibankfacility;
    int pin;
    int atype;
};

void accept(struct customer[], int);
void display(struct customer[], int);
int availi(struct customer[], int, int);
void availacc(struct customer[], int, int, int);
void availpos(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;

    cout<<"Banking System\n\n";
    cout<<"Number of customer records you want to enter? : ";
    cin>>n;
    accept(data, n);
    do
    {

        cout<<"\nBanking System Menu :\n";
        cout<<"Press 1 to display customer status, golden, silver or general.\n";
        cout<<"Press 2 to avail list of customers using internet Banking.\n";
        cout<<"Press 3 to display customer list as per account type.\n";
        cout<<"Press 4 to display customer according to the postal code.\n";
        cout<<"Press 0 to exit\n";
        cout<<"\nEnter choice(0-4) : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 2:

               break; 
            case 3:
         
              break;
            case 4:

             break;
           
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        cout<<"\nEnter data for Record #%d", i + 1;

        cout<<"\nEnter account_no : ";
        cin>>list[i].account_no;
        cout<<"Enter name : ";
        cin>>list[i].name;
        list[i].balance = 0;

    } 
}

