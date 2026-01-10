#include<iostream>
using namespace std;

int main()
{
    int s,t;
    cout<<"Enter how many stations: ";
    cin>>s;
    cout<<"Enter how many trains: ";
    cin>>t;

    int TT[s][t];

    cout<<"Enter train Data:\n";
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<t;j++)
        {
            cin>>TT[i][j];
        }
    }

    cout<<"Train time table :\n";
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<t;j++)
        {
            cout<<TT[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"Active traines are:\n";
    cout<<"Station\tTimeslot\tTrain ID\n";
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<t;j++)
        {
            if(TT[i][j]!=0)
            {
            cout<<i<<"\t"<<j<<"\t"<<TT[i][j];
            }
        }
        cout<<endl;
    }

    return 0;
}